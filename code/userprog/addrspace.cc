// addrspace.cc 
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option 
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include <iostream>
#include <exception>

#ifdef VM
#include <cmath>
#endif

#ifdef HOST_SPARC
#include <strings.h>
#endif

extern void PageFaultHandler(int vaddr);

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the 
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void 
SwapHeader (NoffHeader *noffH)
{
	noffH->noffMagic = WordToHost(noffH->noffMagic);
	noffH->code.size = WordToHost(noffH->code.size);
	noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
	noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
	noffH->initData.size = WordToHost(noffH->initData.size);
	noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
	noffH->uninitData.size = WordToHost(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
	noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	First, set up the translation from program memory to physical 
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------

AddrSpace::AddrSpace(OpenFile *executable)
{
    pcb = new PCB(pm->GetPID(), -1, NULL, -1);
    pm->AddProcess(pcb);

    NoffHeader noffH;
    unsigned int i, size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && 
		(WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

// how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size 
			+ UserStackSize;	// we need to increase the size
						// to leave room for the stack
    DEBUG('q',"CODE = %d , DATA=%d , UNINIT=%d , STACK=%d\n",noffH.code.size , noffH.initData.size , noffH.uninitData.size, UserStackSize);
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;

    DEBUG('q',"NUMPAGES= %d\n",numPages);
    #ifndef VM 
    ASSERT(numPages <= NumPhysPages);		// check we're not trying
						// to run anything too big --
						// at least until we have
						// virtual memory

    if (numPages > memory->freePages()) {
        printf("Not enough memory to perform Exec!\n");
	pm->ClearPID(pcb->GetPID());
	//delete pcb;
        throw std::bad_alloc();
    }
    #endif

    DEBUG('a', "Initializing address space, num pages %d, size %d\n", 
					numPages, size);
    // first, set up the translation 
    pageTable = new TranslationEntry[numPages];
    for (i = 0; i < numPages; i++) {
	pageTable[i].virtualPage = i;	// for now, virtual page # = phys page #

        #ifdef VM
        pageTable[i].physicalPage = -1;
	pageTable[i].valid = FALSE;
        #else
	pageTable[i].physicalPage = memory->getPage();
        pageTable[i].valid = TRUE;
        #endif

	pageTable[i].use = FALSE;
	pageTable[i].dirty = FALSE;
	pageTable[i].readOnly = FALSE;  // if the code segment was entirely on 
					// a separate page, we could set its 
					// pages to be read-only
    }
    
// zero out the entire address space, to zero the unitialized data segment 
// and the stack segment
//    bzero(machine->mainMemory, size);

// then, copy in the code and data segments into memory
    if (noffH.code.size > 0) {
        DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", noffH.code.virtualAddr, noffH.code.size);
        ReadFile(noffH.code.virtualAddr, executable, noffH.code.size, noffH.code.inFileAddr);
    }
    if (noffH.initData.size > 0) {
        DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", noffH.initData.virtualAddr, noffH.initData.size);
        ReadFile(noffH.initData.virtualAddr, executable, noffH.initData.size, noffH.initData.inFileAddr);
    }

    #ifdef VM
    char* buffer = new char[PageSize + 1];
    memset(buffer, '\0', PageSize);
    
    // OLD CODE
    /*
    int page = (numPages - UserStackSize/PageSize) - 1;
    DEBUG('q',"############### Starting BSS ##################\n");
    for (int i=0; i < (noffH.uninitData.size/PageSize); i++) {
       DEBUG('q', "Adding blank pages for BSS...\n");
       vm->AddPage(&pageTable[page], pcb->GetPID(), buffer ,PageSize);
       page--;
    }
    DEBUG('q',"############### Starting Stacksize ##################\n");

    for (int v = (numPages - UserStackSize/PageSize); v < numPages; v++) {
       DEBUG('q', "Adding blank pages for stack...\n");
       vm->AddPage(&pageTable[v], pcb->GetPID(), buffer , PageSize);
    }
    */

    int page = ceil((float)(noffH.code.size + noffH.initData.size)/PageSize);
    DEBUG('q', "######################Adding %d pages\n",(numPages - page));
    
    for (int v = page; v < numPages; v++) {
    	vm->AddPage(&pageTable[v], pcb->GetPID(), PageSize);
    }

    delete buffer;
    #endif

    DEBUG('f', "Loaded program %d code | %d data | %d bss\n", noffH.code.size, noffH.initData.size, noffH.uninitData.size);
}

void AddrSpace::SysCallDone() {
    for (int i = 0; i < numPages; i++) {
	pageTable[i].use = FALSE;
    }
}

AddrSpace::AddrSpace(TranslationEntry* table, int page_count, int oldPID) {
    pageTable = table;
    numPages = page_count;

    pcb = new PCB(pm->GetPID(), -1, NULL, -1);
    pm->AddProcess(pcb);

    #ifdef VM
    for (int i = 0; i < numPages; i++) {
	if (pageTable[i].valid) {
		vm->AddPage(&pageTable[i], pcb->GetPID(), machine->mainMemory + (pageTable[i].physicalPage * PageSize), PageSize);
	}
	else {
    		//vm->AddPage(&pageTable[i], pcb->GetPID(), mem_buffer, PageSize);
		vm->CopyPage(&pageTable[i], oldPID, pcb->GetPID());
	}

	pageTable[i].valid = FALSE;
	pageTable[i].physicalPage = -1;
    }
    #endif
}

#ifdef VM
// Return Value ??? some int
// vaddr = virtual address
// file = file to read into memory
// size = size of data to read
// fileAddr = location in file to start at
int AddrSpace::ReadFile(int vaddr, OpenFile* file, int size, int fileAddr) {
   int bytes_read = 0;
   int bytes_wrote;
   int phys_addr;
   int write_size;
   char* mem_buffer;
   //char buffer[PageSize];
   char* buffer = new char[PageSize];

   char* out_buffer;

   DEBUG('q', "--------------------Start vaddr: %d end vaddr: %d\n", vaddr, vaddr + size);
   
   while (bytes_read < size) {
      int read = file->ReadAt(diskBuffer, PageSize - (vaddr % PageSize), fileAddr);
      fileAddr += read;
      DEBUG('q', "Bytes read: %d\n", read);
      bytes_read += read;
      DEBUG('q', "We have vaddr: %d, and PageSize: %d, VPN: %d\n", vaddr, PageSize, vaddr/PageSize);
      out_buffer = diskBuffer;

      if (vm->GetPage(&pageTable[vaddr/PageSize], pcb->GetPID(), buffer, PageSize)) {
           DEBUG('7', "Starting at %d, we should be able to write %d bytes\n", vaddr, PageSize - (vaddr % PageSize));
           memcpy(buffer + (vaddr % PageSize), diskBuffer, PageSize - (vaddr % PageSize));
           out_buffer = buffer;
      }

      vm->AddPage(&pageTable[vaddr/PageSize], pcb->GetPID(), out_buffer, PageSize);
      vaddr += read;
   }

   delete buffer;
}
#else
// Return Value ??? some int
// vaddr = virtual address
// file = file to read into memory
// size = size of data to read
// fileAddr = location in file to start at
int AddrSpace::ReadFile(int vaddr, OpenFile* file, int size, int fileAddr) {
   int bytes_read = 0;
   int bytes_wrote;
   int phys_addr;
   int write_size;
   char* mem_buffer;

   //DEBUG('m', "--------------------Start vaddr: %d end vaddr: %d\n", vaddr, vaddr + size);
   
   while (bytes_read < size) {
      //int read = file->ReadAt(diskBuffer, PageSize, fileAddr);
      int read = file->ReadAt(diskBuffer, PageSize - (vaddr % PageSize), fileAddr);
      fileAddr += read;
      //DEBUG('m', "Bytes read: %d\n", read);
      bytes_read += read;
      bytes_wrote = 0;
      mem_buffer = diskBuffer;

      while (bytes_wrote < read) {
         //DEBUG('m', "Bytes wrote: %d\n", bytes_wrote);
         write_size = PageSize - (vaddr % PageSize);
         bytes_wrote += write_size;

         if (!Translate(vaddr, &phys_addr, false)) {
	    // THROW AN ERROR
	    DEBUG('p', "Translation Failed! Should throw an Exception?\n");
         }

	 DEBUG('m', "Phys addr: %d of size: %d\n", phys_addr, write_size);
         DEBUG('a', "Writing to physical memory page %d\n", phys_addr/ PageSize);
         memcpy(machine->mainMemory + phys_addr, mem_buffer, write_size);
         mem_buffer += write_size;
         //DEBUG('m', "Virtual address location: %d\n", vaddr);
         vaddr = vaddr + write_size;
      }
   }
}
#endif

#ifdef VM
bool AddrSpace::Translate(int vaddr, int* paddr, bool writing) {
   if (paddr == NULL) {
      // THROW AN ERROR
   }

   int vpn = vaddr / PageSize;
   int offset = vaddr % PageSize;

   if (vpn > numPages) {
      return FALSE;
   }
   else if (!pageTable[vpn].valid) {
      PageFaultHandler(vaddr);
   }

   int phys_page = pageTable[vpn].physicalPage;
   int phys_addr = (phys_page * PageSize) + offset;

   *paddr = phys_addr;

   if (writing) {
      pageTable[vpn].dirty = TRUE;
   }

   #ifdef VM
   pageTable[vpn].use = TRUE;
   #endif

   return TRUE;
}
#else
bool AddrSpace::Translate(int vaddr, int* paddr, bool writing) {
   if (paddr == NULL) {
      // THROW AN ERROR
   }

   int vpn = vaddr / PageSize;
   int offset = vaddr % PageSize;

   if (vpn > numPages) {
      return FALSE;
   }
   else if (!pageTable[vpn].valid) {
      return FALSE;
   }

   int phys_page = pageTable[vpn].physicalPage;
   int phys_addr = (phys_page * PageSize) + offset;

   *paddr = phys_addr;

   if (writing) {
      pageTable[vpn].dirty = TRUE;
   }

   #ifdef VM
   pageTable[vpn].use = TRUE;
   #endif

   return TRUE;
}
#endif

#ifdef VM
int AddrSpace::Clone(AddrSpace** copySpace) {
    AddrSpace* newspace;

    TranslationEntry* newTable = new TranslationEntry[numPages];

    for (int i = 0; i < numPages; i++) {
	newTable[i].virtualPage = pageTable[i].virtualPage;
	newTable[i].physicalPage = pageTable[i].physicalPage;

	//memcpy((void*) machine->mainMemory + (newTable[i].physicalPage * PageSize), (void*) machine->mainMemory + (pageTable[i].physicalPage * PageSize), PageSize);
	newTable[i].valid = pageTable[i].valid;
	newTable[i].use = pageTable[i].use;
	newTable[i].dirty = pageTable[i].dirty;
	newTable[i].readOnly = pageTable[i].readOnly;
    }

    *copySpace = new AddrSpace(newTable, numPages, pcb->GetPID());

    return numPages;
}
#else
int AddrSpace::Clone(AddrSpace** copySpace) {
    AddrSpace* newspace;


    if (memory->freePages() < numPages) {
	printf("Not enough free memory to fork!\n");
	*copySpace == NULL;
        return 0;
    }

    TranslationEntry* newTable = new TranslationEntry[numPages];

    for (int i = 0; i < numPages; i++) {
	newTable[i].virtualPage = pageTable[i].virtualPage;
	newTable[i].physicalPage = memory->getPage();

	memcpy((void*) machine->mainMemory + (newTable[i].physicalPage * PageSize), (void*) machine->mainMemory + (pageTable[i].physicalPage * PageSize), PageSize);

	newTable[i].valid = pageTable[i].valid;
	newTable[i].use = pageTable[i].use;
	newTable[i].dirty = pageTable[i].dirty;
	newTable[i].readOnly = pageTable[i].readOnly;
    }

    *copySpace = new AddrSpace(newTable, numPages, pcb->GetPID());

    return numPages;
}
#endif


//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

#ifdef VM
AddrSpace::~AddrSpace() {
    int i;

    // Delete any pages in physical memory
    for (i = 0; i < numPages; i++) {
	if (pageTable[i].valid) {
		memory->clearPage(pageTable[i].physicalPage);
	}
    }

    delete pageTable;
}
#else
AddrSpace::~AddrSpace() {
    int i;

    for (i = 0; i < numPages; i++) {
	memory->clearPage(pageTable[i].physicalPage);
    }

    delete pageTable;
}
#endif

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
AddrSpace::InitRegisters()
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);	

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);

    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void AddrSpace::SaveState() 
{
}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState() 
{
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;
}
