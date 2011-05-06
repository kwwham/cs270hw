// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include <string.h>
#include <exception>
#include <iostream>
#include <stdio.h>

#include <time.h>
#include <sys/time.h>

struct timeval start, end;
int checkTime=1;

long timeDiff(struct timeval s, struct timeval e)
{
    return (e.tv_sec - s.tv_sec)*1000000 + (e.tv_usec - s.tv_usec);
}


//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------
void forkbridge(int func) {
        currentThread->space->InitRegisters();
        currentThread->space->RestoreState();

        machine->registers[PCReg] = func; // Start running from this func
        machine->registers[NextPCReg] = func + 4;
        machine->registers[RetAddrReg] += 8;

        machine->Run();
}
/*
USING PROCESSCREATOR INSTEAD OF THIS FUNCTION

void execdummy(int ignore) {
        currentThread->space->InitRegisters();
        currentThread->space->RestoreState();

        machine->Run();
} */

// Read or write from main memory
// 0 = Read, 1 = Write
int userReadWrite(int vaddr, char* buffer, int size, int type)
{
   
     int bytes_read = 0;
        int bytes_wrote;
        int phys_addr;
        int write_size;
        int read_size;
        char* mem_buffer;
        char* buffer_buffer;

        // Read from buffer into memory
        if (type == 0) {
                while (bytes_read < size) {
                        //int read = file->ReadAt(diskBuffer, PageSize, fileAddr);
                        int read = 0;
                        if ((size - bytes_read) >= PageSize) {
                                db_lock->Acquire();
                                memcpy(diskBuffer, buffer + bytes_read, PageSize);
                                db_lock->Release();
                                read = PageSize;
                        }
                        else {
                                db_lock->Acquire();
                                memcpy(diskBuffer, buffer + bytes_read, size - bytes_read);
                                db_lock->Release();
                                read = size - bytes_read;
                        }
                        //fileAddr += read;
                        bytes_read += read;
                        bytes_wrote = 0;
                        mem_buffer = diskBuffer;
						while (bytes_wrote < read) {
                                //write_size = PageSize - (vaddr % PageSize);
                                //write_size = size;
                                if (size > (PageSize - (vaddr % PageSize))) {
                                        write_size = PageSize - (vaddr % PageSize);
                                }
                                else {
                                        write_size = size;
                                }

                                bytes_wrote += write_size;

                                if (!currentThread->space->Translate(vaddr, &phys_addr, true)) {
                                        // THROW AN ERROR
                                }

                                //DEBUG('f', "Buffer value...%s\n", machine->mainMemory + phys_addr);
                                db_lock->Acquire();
                                memcpy(machine->mainMemory + phys_addr, mem_buffer, write_size);
                                db_lock->Release();
                                mem_buffer += write_size;
                                vaddr = vaddr + write_size;
                        }
                }
        }

        // Write from memory into a buffer
        if (type == 1) {
                buffer_buffer = buffer;

                while (bytes_read < size) {
                        //int read = file->ReadAt(diskBuffer, PageSize, fileAddr);
                        int read = 0;

                        //read_size = PageSize - (vaddr % PageSize);
                        //read_size = size;
						 if (size > (PageSize - (vaddr % PageSize))) {
                                read_size = PageSize - (vaddr % PageSize);
                        }
                        else {
                                read_size = size;
                        }

                        if (!currentThread->space->Translate(vaddr, &phys_addr, false)) {
                                // THROW AN ERROR
                        }

                        if (read_size > (size - bytes_read)) {
                                read_size = size - bytes_read;
                        }

                        if (read_size > PageSize) {
                                read_size = PageSize;
                        }

                        db_lock->Acquire();
                        memcpy(diskBuffer, machine->mainMemory + phys_addr, read_size);
                        db_lock->Release();
                        vaddr = vaddr + read_size;

                        //fileAddr += read;
                        bytes_read += read_size;
                        bytes_wrote = 0;
                        //mem_buffer = diskBuffer;

                        //while (bytes_wrote < read_size) {
                        db_lock->Acquire();
                        memcpy(buffer_buffer, diskBuffer, read_size);
                        db_lock->Release();

                        buffer_buffer += read_size;
                        //}
                }
        }

}

SpaceId MyFork(int arg)
{
	
    printf("Entering Fork !!!! \n");
    AddrSpace *space, *copyspace;
    Thread *newthread;

    space = currentThread->space;
    int pages = space->Clone(&copyspace);

    if (pages == 0) {
            DEBUG('f', "Error!\n");
            return -1;
    }

    newthread = new Thread("new forked thread");
    newthread->space = copyspace;

    newthread->space->pcb->SetThread(newthread);
    newthread->space->pcb->SetParentPID(currentThread->space->pcb->GetPID());

    newthread->Fork(forkbridge, arg);
    //printf("%s with SpaceId %d has been forked!!\n", newthread->getName(), copyspace->spaceId);
    DEBUG('2', "Process %d Fork: start at address 0x%X with %d pages memory\n", currentThread->space->pcb->GetPID(), arg, pages);
    currentThread->Yield();

    return newthread->space->pcb->GetPID(); // was -1

}

void Yield() 
{
	printf("\n I am trying to yield\n");
        currentThread->Yield();
	printf("\n I just yielded \n");
}


void ExitProcess(int status)
{	
/* Working */
	if (status < 0) 
	{
       status = 0;
    }
    SpaceId pid = currentThread->space->pcb->GetPID();
	printf("The pid of the process is %d \n", pid);
    DEBUG('f', "Process %d exits with %d\n", pid, status);
    currentThread->space->pcb->SetStatus(status);
    pm->Broadcast(pid);
    //currentThread->Yield(); // Experimental idea
    machine->WriteRegister(2,0);
    if (pm->GetJoins(pid) == 0) {
            pm->ClearPID(currentThread->space->pcb->GetPID());
    }
    currentThread->space->~AddrSpace();
    currentThread->Finish();
}

void GetFileName(int vaddr, char** ptr) {
        int paddr;

        currentThread->space->Translate(vaddr, &paddr, false);

        char* name = new char[strlen(machine->mainMemory + paddr) + 1];
        strcpy(name, machine->mainMemory + paddr);
        *ptr = name;
}


void processCreator(int arg)
{
	currentThread->space->InitRegisters();		// set the initial register values
    currentThread->space->RestoreState();		// load page table register

    machine->Run();			// jump to the user progam
	//ASSERT(FALSE);
}


SpaceId Exec(int vaddr) 
{
	char* name;
    int paddr; 
    currentThread->space->Translate(vaddr, &paddr, false);
    name = new char[strlen(machine->mainMemory + paddr) + 1];
    strcpy(name, machine->mainMemory + paddr);
    OpenFile *executable = fileSystem->Open(name);
	AddrSpace *space;
	if (executable == NULL) 
	{
        printf("Unable to open file %s\n", name);
        return -1;
    }
    try 
	{
		space = new AddrSpace(executable);
    }
    catch (std::bad_alloc&) 
	{
        delete name;
        return NULL;
  	}	
	Thread* newthread =new Thread("New Exec thread");
    newthread->space = space;
	newthread->space->pcb->SetThread(newthread);
    newthread->space->pcb->SetParentPID(currentThread->space->pcb->GetPID());
	newthread->Fork(processCreator, 0);
    delete executable;
    DEBUG('2', "Exec Program: %d loading %s\n", currentThread->space->pcb->GetPID(), name);
				
gettimeofday(&end, NULL);
if(checkTime) printf("*******Time elapsed for Exec: %ld\n", timeDiff(start, end)); //checkTime determines whether it prints out the time info or not			
    
    currentThread->space->SysCallDone();
    currentThread->Yield();
    delete name;

				
    return newthread->space->pcb->GetPID(); 

}

int Join(SpaceId id) 
{
	/* stub */
	printf("Entering join\n");
	pm->Join(id);
    pm->DecrementJoins(id);
    int exit_status = pm->GetStatus(id);
    if (pm->GetJoins(id) == 0) {
            //machine->WriteRegister(2,0);
            pm->ClearPID(currentThread->space->pcb->GetPID());
            //currentThread->space->~AddrSpace();
            //currentThread->Finish();
    }
    return exit_status;
}

void Create(int arg) 
{
        char* fileName;
        GetFileName(arg, &fileName);

        bool success = fileSystem->Create(fileName, 0);

        if (!success)
                DEBUG('1', "ASSERT SHOULD FAIL! ===========\n");

        ASSERT(success);
}
/* Function stubs for testing */

OpenFileId Open(int arg) 
{
	printf("Entering open!!!!!!!!!!\n\n");
	char* fileName;
    GetFileName(arg, &fileName);
    int index;
    SysOpenFile* sfile = fm->Get(fileName, index);

    if (sfile != NULL) {
            sfile->userOpens++;
		printf(" check1 = %d\n",sfile->userOpens++);    
	}
    else {
            OpenFile* ofile = fileSystem->Open(fileName);
            sfile = new SysOpenFile(fileName, ofile, -1);
            index = fm->Add(sfile);
		printf(" check2\n");    
    }

    UserOpenFile* ufile = new UserOpenFile();
    ufile->fileName = fileName;
    ufile->index = index;

    DEBUG('z', "Creating new file with index %d and file name %s......\n", ufile->index, ufile->fileName);
	printf("Creating new file with index %d and file name %s......\n", ufile->index, ufile->fileName);
    currentThread->space->pcb->AddFile(ufile);

    return sfile->FileID;
}


int ReadHandler(int baddr, int size, int id) 
{
	/*   Dummy  */
	int paddr;
    char buffer[size + 1];
    int read = 0;

    SysOpenFile* sfile = NULL;
    UserOpenFile* ufile = NULL;

    //currentThread->space->Translate(baddr, &paddr);

    if (id == ConsoleInput) {
            while (read < size) {
                    buffer[read] = getchar();
                    read++;
            }

            //buffer[read] = '\0';

            char next = 'a';

            // Get rid of excess characters
            while ((next != '\n')&&(next != EOF)) {
                    next = getchar();
            }

            //DEBUG('9', "INPUT: %s\n", buffer); 

            //printf("%s\n", machine->mainMemory[baddr]);
    }
	else {
            for (int i=0; i < MAX_USER_FILES; i++) {
                    ufile = currentThread->space->pcb->GetFile(i);

                    if (ufile != NULL) {
                            if (fm->Get(ufile->index)->FileID == id) {
                                    sfile = fm->Get(ufile->index);
                                    break;
                            }
                    }
            }

            if (sfile == NULL) {
                    // THROW AN ERROR
                    return 0;
            }

            sfile->lock->Acquire();
            int read = sfile->file->ReadAt(buffer, size, ufile->offset);
            sfile->lock->Release();
            buffer[read] = '\0';

            DEBUG('z', "Read %d bytes, should have read %d, from offset %d, says: %s\n", read, size, ufile->offset, buffer);

            //userReadWrite(baddr, buffer, size, 0);
    }

    DEBUG('f', "Almost done!\n");

    userReadWrite(baddr, buffer, size, 0);

    return read;
}


void WriteHandler(int baddr, int size, int id) 
{
	/* Working */
	int paddr;
    char buffer[size + 1];

    SysOpenFile* sfile = NULL;
    UserOpenFile* ufile = NULL;

    if (!currentThread->space->Translate(baddr, &paddr, false)) {
            DEBUG('z', "Translate failed...\n");
            return;
    }

    if (id == ConsoleOutput) {
            char format[10];
            strncpy(format, "%.", 2);
            int printed = 0;

            while(printed < size) {
                    // Find out how much of the page is remaining...
                    int read_size = PageSize - (baddr % PageSize);

                    if (read_size > size - printed) {
                            read_size = size - printed;
                    }

                    int i = sprintf(format+2, "%.6d", read_size);
                    strncpy(format + 2 + i, "s\0", 2);

                    printf(format, machine->mainMemory + paddr);

                    printed += read_size;
                    baddr += read_size;

                    if (!currentThread->space->Translate(baddr, &paddr, false)) {
                            DEBUG('z', "Translate failed...\n");
                            return;
                    }
            }
    }
	else {
            for (int i=0; i < MAX_USER_FILES; i++) {
                    ufile = currentThread->space->pcb->GetFile(i);

                    if (ufile != NULL) {
                            if (fm->Get(ufile->index)->FileID == id) {
                                    sfile = fm->Get(ufile->index);
                                    break;
                            }
                    }
            }

            if (sfile == NULL) {
                    // THROW AN ERROR
                    return;
            }

            int bytes_wrote = 0;
            int initial_length = 0;
            int new_length = 0;
            int fid = ufile->index;

            userReadWrite(baddr, buffer, size, 1);
            sfile->lock->Acquire();
            initial_length = sfile->file->Length();
            bytes_wrote = sfile->file->Write(buffer, size);
            new_length = sfile->file->Length();
            sfile->lock->Release();
            ufile->offset += size;

            DEBUG('3', "F %d %d: %d -> %d\n", currentThread->space->pcb->GetPID(), fid, initial_length, new_length);

            //DEBUG('f', "Outputting userReadWrite(1), %s\n", buffer);
    }
	printf("\nWrtie finished\n\n");
    DEBUG('1', "End WRITE system call\n");

}

void myClose(int arg) 
{
        SysOpenFile* sfile = NULL;
        UserOpenFile* ufile = NULL;

        for (int i=0; i < MAX_USER_FILES; i++) 
		{
                ufile = currentThread->space->pcb->GetFile(i);

                if (ufile != NULL) {
                        if (fm->Get(ufile->index)->FileID == arg) {
                                sfile = fm->Get(ufile->index);
                                break;
                        }
                }
        }

        if (sfile == NULL) {
                // THROW AN ERROR
                return;
        }

        currentThread->space->pcb->CloseFile(ufile);


}
  
void IncrementCounters() {
        //DEBUG('f', "BACK TO THE FUTURE( AKA USER MODE)\n");
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg) + 4);
}

void dumpMemory() {
        for (int i=0; i < 4096; i++) {
                DEBUG('6', "%-5d ", machine->mainMemory[i]);
        }
}



void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);
	int ret,arg1,arg2,arg3;
	OpenFileId fid;
	//SpaceId pid =getpid();
	SpaceId pid = currentThread->space->pcb->GetPID();
//****************************************
	if(which ==SyscallException)
	{
		int arg = machine->ReadRegister(4);
		 switch(type)
		{
			case SC_Halt:	
				DEBUG('a',"shutdown initiated by the user program.\n");
				printf("type = %d\n", type);		
				interrupt->Halt();
				break;
			case SC_Exec:
				DEBUG('a',"Exec invoked here.\n");
				gettimeofday(&start, NULL);
                		machine->WriteRegister(2, Exec(arg));
				gettimeofday(&end, NULL);
				if(checkTime) printf("Time elapsed for Exec: %ld\n", timeDiff(start, end)); //checkTime determines whether it prints out the time info or not			
                		break;
			case SC_Join:
                 		DEBUG('2', "System Call: %d invoked Join\n", pid);
                  		ret = Join(machine->ReadRegister(4));
                  		machine->WriteRegister(2, ret);
                  		break;
			case SC_Exit:
                   		DEBUG('2', "System Call: %d invoked Exit:\n", pid);
                   		ExitProcess(machine->ReadRegister(4));
                   		break;
			case SC_Yield:
				DEBUG('2', "System Call: %d invoked Yield\n", pid);
                    		Yield();
				break;
             		case SC_Fork:
                    		DEBUG('2', "System Call: %d invoked Fork\n", pid);
				gettimeofday(&start, NULL);
				printf("joon, it goes into SC_Fork\n");
                    		arg = machine->ReadRegister(4);
                    		machine->WriteRegister(2, MyFork(arg));
				gettimeofday(&end, NULL);
				if(checkTime) printf("Time elapsed for Fork: %ld\n", timeDiff(start, end)); //checkTime determines whether it prints out the time info or not			
                    		break;   
			case SC_Open:
                    		DEBUG('2', "System Call: %d invoked Open\n", pid);
				fid = Open(machine->ReadRegister(4));
		        	machine->WriteRegister(2, fid);
                    		break;
		    	case SC_Create:
                 		//dumpMemory();
                    		DEBUG('2', "System Call: %d invoked Create\n", pid);
                    		Create(machine->ReadRegister(4));
                    		//dumpMemory();
                    		break;
            		case SC_Read:
	                	DEBUG('2', "System Call: %d invoked Read\n", pid);
				gettimeofday(&start, NULL);
                    		arg1 = machine->ReadRegister(4);
                    		arg2 = machine->ReadRegister(5);
                    		arg3 = machine->ReadRegister(6);
                    		//dumpMemory();
                    		ret = ReadHandler(arg1, arg2, arg3);
                    		machine->WriteRegister(2, ret);
				gettimeofday(&end, NULL);
				if(checkTime) printf("Time elapsed for Read: %ld\n", timeDiff(start, end)); //checkTime determines whether it prints out the time info or not,		

                    		break;
            		case SC_Write:
				gettimeofday(&start, NULL);
                    		dumpMemory();
                   		DEBUG('2', "System Call: %d invoked Write\n", pid);
                    		arg1 = machine->ReadRegister(4);
                    		arg2 = machine->ReadRegister(5);
                    		arg3 = machine->ReadRegister(6);
                   		WriteHandler(arg1, arg2, arg3);
				gettimeofday(&end, NULL);
				if(checkTime) printf("Time elapsed for Write: %ld\n", timeDiff(start, end)); //checkTime determines whether it prints out the time info or not			

                    		break;
            		case SC_Close:
                    		DEBUG('2', "System Call: %d invoked Close\n", pid);
                    		myClose(machine->ReadRegister(4));
                    		break;
			default:
				printf("for exception type %d, code not written yet \n");
				ASSERT(FALSE);				
				break;
		}
		currentThread->space->SysCallDone();
        IncrementCounters();

	}
	else
	{
		printf("code not written for this exception %d\n",type);
		ASSERT(FALSE);
	}
}	
//******************
//original code of this file 

 /*   if ((which == SyscallException) && (type == SC_Halt)) {
	
	DEBUG('a', "Shutdown, initiated by user program.\n");
   	interrupt->Halt();
    } else {
	printf("Unexpected user mode exception %d %d\n", which, type);
	ASSERT(FALSE);
    }
}*/
