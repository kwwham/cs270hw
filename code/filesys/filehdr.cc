// filehdr.cc 
//	Routines for managing the disk file header (in UNIX, this
//	would be called the i-node).
//
//	The file header is used to locate where on disk the 
//	file's data is stored.  We implement this as a fixed size
//	table of pointers -- each entry in the table points to the 
//	disk sector containing that portion of the file data
//	(in other words, there are no indirect or doubly indirect 
//	blocks). The table size is chosen so that the file header
//	will be just big enough to fit in one disk sector, 
//
//      Unlike in a real system, we do not keep track of file permissions, 
//	ownership, last modification date, etc., in the file header. 
//
//	A file header can be initialized in two ways:
//	   for a new file, by modifying the in-memory data structure
//	     to point to the newly allocated data blocks
//	   for a file already on disk, by reading the file header from disk
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "system.h"
#include "filehdr.h"

//----------------------------------------------------------------------
// FileHeader::Allocate
// 	Initialize a fresh file header for a newly created file.
//	Allocate data blocks for the file out of the map of free disk blocks.
//	Return FALSE if there are not enough free blocks to accomodate
//	the new file.
//
//	"freeMap" is the bit map of free disk sectors
//	"fileSize" is the bit map of free disk sectors
//----------------------------------------------------------------------

bool
FileHeader::Allocate(BitMap *freeMap, int fileSize)
{
#ifdef FILESYS
    numBytes = fileSize;
    numSectors  = divRoundUp(fileSize, SectorSize);
    numSectors += ((numSectors - 4) + PointerSectors - 1)/PointerSectors;
    if (freeMap->NumClear() < numSectors)
	return FALSE;		// not enough space

    int directs = numSectors;

    if (numSectors > 4) {
	directs = 4;
    }

    for (int i = 0; i < directs; i++)
	directDataSectors[i] = freeMap->Find();

// indirect?? ((numSectors - 4) + PointerSectors - 1)/PointerSectors
    for (int j = 0; j < ((numSectors - 4) + PointerSectors - 1)/PointerSectors; j++) {
	DEBUG('1', "Allocating a new indirect jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj\n");
	indirectDataSectors[j] = new IndirectPointerBlock();
	pointerBlockSectors[j] = freeMap->Find();
	int sectors = PointerSectors;

	if (j == ((numSectors - 4) + PointerSectors - 1) - 1) {
		sectors = (numSectors - 4) - PointerSectors*j;
	}

	for (int k = 0; k < sectors; k++) {
		indirectDataSectors[j]->PutSector(freeMap->Find());
	}
    }

    return TRUE;

#else
/*  The original code 
*/
    numBytes = fileSize;
    numSectors  = divRoundUp(fileSize, SectorSize);
    if (freeMap->NumClear() < numSectors)
	return FALSE;		// not enough space

    for (int i = 0; i < numSectors; i++)
	dataSectors[i] = freeMap->Find();
    return TRUE;

#endif
}

//----------------------------------------------------------------------
// FileHeader::Deallocate
// 	De-allocate all the space allocated for data blocks for this file.
//
//	"freeMap" is the bit map of free disk sectors
//----------------------------------------------------------------------

void 
FileHeader::Deallocate(BitMap *freeMap)
{
    #ifdef FILESYS

    int indirects = ((numSectors - 4) + PointerSectors - 1)/PointerSectors;
    int directs = (numSectors>4)? 4 : numSectors;

    for (int i = 0; i < directs; i++) {
	ASSERT(freeMap->Test((int) directDataSectors[i]));  // ought to be marked!
	freeMap->Clear((int) directDataSectors[i]);
    }

    

    for (int j = 0; j < indirects; j++) {
	ASSERT(freeMap->Test((int) pointerBlockSectors[j]));  // ought to be marked!
	freeMap->Clear((int) pointerBlockSectors[j]);
        indirectDataSectors[j]->Deallocate(freeMap);
	delete indirectDataSectors[j];
    }

    #else
    for (int i = 0; i < numSectors; i++) {
	ASSERT(freeMap->Test((int) dataSectors[i]));  // ought to be marked!
	freeMap->Clear((int) dataSectors[i]);
    }
    #endif
}

//----------------------------------------------------------------------
// FileHeader::FetchFrom
// 	Fetch contents of file header from disk. 
//
//	"sector" is the disk sector containing the file header
//----------------------------------------------------------------------

void
FileHeader::FetchFrom(int sector)
{
    synchDisk->ReadSector(sector, (char *)this);
}

//----------------------------------------------------------------------
// FileHeader::WriteBack
// 	Write the modified contents of the file header back to disk. 
//
//	"sector" is the disk sector to contain the file header
//----------------------------------------------------------------------

void
FileHeader::WriteBack(int sector)
{
    synchDisk->WriteSector(sector, (char *)this); 
}

//----------------------------------------------------------------------
// FileHeader::ByteToSector
// 	Return which disk sector is storing a particular byte within the file.
//      This is essentially a translation from a virtual address (the
//	offset in the file) to a physical address (the sector where the
//	data at the offset is stored).
//
//	"offset" is the location within the file of the byte in question
//----------------------------------------------------------------------

int
FileHeader::ByteToSector(int offset)
{
    return(dataSectors[offset / SectorSize]);
}

//----------------------------------------------------------------------
// FileHeader::FileLength
// 	Return the number of bytes in the file.
//----------------------------------------------------------------------

int
FileHeader::FileLength()
{
    return numBytes;
}

//----------------------------------------------------------------------
// FileHeader::Print
// 	Print the contents of the file header, and the contents of all
//	the data blocks pointed to by the file header.
//----------------------------------------------------------------------

void
FileHeader::Print()
{
    int i, j, k;
    char *data = new char[SectorSize];

    printf("FileHeader contents.  File size: %d.  File blocks:\n", numBytes);
    for (i = 0; i < numSectors; i++)
	printf("%d ", dataSectors[i]);
    printf("\nFile contents:\n");
    for (i = k = 0; i < numSectors; i++) {
	synchDisk->ReadSector(dataSectors[i], data);
        for (j = 0; (j < SectorSize) && (k < numBytes); j++, k++) {
	    if ('\040' <= data[j] && data[j] <= '\176')   // isprint(data[j])
		printf("%c", data[j]);
            else
		printf("\\%x", (unsigned char)data[j]);
	}
        printf("\n"); 
    }
    delete [] data;
}

//------------------------------------------------------------------------
//
//  joon
//
//------------------------------------------------------------------------

bool IndirectPointerBlock::Deallocate(BitMap* freeMap) {
    for (int i = 0; i < numSectors; i++) {
		ASSERT(freeMap->Test((int) dataSectors[i]));  // ought to be marked!
		freeMap->Clear((int) dataSectors[i]);
    }
}

void IndirectPointerBlock::PutSector(int sectorNumber) {
    DEBUG('1', "Number of sectors: %d\n", numSectors);
	dataSectors[numSectors] = sectorNumber;
	numSectors++;
}

void IndirectPointerBlock::FetchFrom(int sectorNumber) {
	synchDisk->ReadSector(sectorNumber, (char *)this);

	DEBUG('1', "=======================Size of IndirectPointerBlock %d\n", sizeof(*this));
	
/*  What is the difference b/w the code above and below?

	char* buffer = new char[128];
	synchDisk->ReadSector(sectorNumber, (char *)buffer);
	memcpy((char*) this, buffer, SectorSize);
	delete buffer;
*/
}

void IndirectPointerBlock::WriteBack(int sectorNumber) {
	synchDisk->WriteSector(sectorNumber, (char *)this); 
}

int IndirectPointerBlock::ByteToSector(int sectorNumber) {
	return(dataSectors[sectorNumber / SectorSize]);
}

// ADDED PROJECT 3 -- FINISH ME
#ifdef FILESYS
bool FileHeader::ExtendFile(BitMap *freeMap, int n, int bytes) {
//   numBytes += n;
//   int offset = numBytes - divRoundDown(numBytes, SectorSize)*SectorSize;
//   int newSectors  = divRoundUp(n - (SectorSize - offset), SectorSize);
//   newSectors += ((newSectors - 4) + PointerSectors - 1)/PointerSectors;
    if (freeMap->NumClear() < n) {
	printf("Out of disk drive space!\n");
	return FALSE;		// not enough space
    }

    DEBUG('1', "Number of sectors for this file is currently %d, looking to add %d sectors\n", numSectors, n);

    if (numSectors < 4) {
	int max = n + numSectors;	

	if (max > 4) {
           max = 4;
	}

        for (int i=numSectors; i < max; i++) {
	   DEBUG('1', "ALLOCATING A SECTOR........\n");
           directDataSectors[i] = freeMap->Find();
        }

        n = n - (max - numSectors);
        numSectors = numSectors + (max - numSectors);
    }

    numBytes = bytes;

    DEBUG('1', "Is numSectors screwy? %d\n", numSectors);

    if (n == 0) {
       return true;
    }

    int existing_blocks = divRoundUp((numSectors - 4), PointerSectors);
    int block_space = existing_blocks*PointerSectors - (numSectors - 4);

  //  if (block_space < 0) {
  //     block_space = PointerSectors;
  //    if (exisiting_blocks == 0) {
   //        indirectDataSectors[0] = new IndirectPointerBlock();
   // //   }
   // }

    if (block_space - n > 0) {
       block_space = n;
    }

    DEBUG('1', "We have enough room for %d sectors on our existing ipb\n", block_space);

    //for (int i=0; i < block_space; i++) {
	//indirectDataSectors[existing_blocks - 1]->PutSector(freeMap->Find());
	//n--;
    //}
    n -= block_space;

    if (n == 0) {
       return true;
    }

    int new_blocks = divRoundUp(n, PointerSectors);

    DEBUG('1', "We're gonna need to create %d new blocks, and we have %d existing blocks\n", new_blocks, existing_blocks);

    for (int j=existing_blocks; j < existing_blocks + new_blocks; j++) {
	 DEBUG('1', "Allocating a new indirect jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj\n");
         indirectDataSectors[j] = new IndirectPointerBlock();

         if (j == existing_blocks + new_blocks - 1) {
	     DEBUG('1', "We're on the final ipb with a %d value of n\n", n);
	     int remains = n;

             for (int k=0; k < remains; k++) {
                 indirectDataSectors[j]->PutSector(freeMap->Find());
                 n--;
             }

	     DEBUG('1', "Value of n is %d\n", n);
         }
         else {
             for (int k=0; k < PointerSectors; k++) {
                 indirectDataSectors[j]->PutSector(freeMap->Find());
		 n--;
             }
         }
    }

    if (n == 0) {
       return true;
    }

    return false;

    int numBlocks = divRoundUp(n, PointerSectors);
    int startBlock = divRoundUp((numSectors - 4), PointerSectors) - 1;

    int indirect_last_index = ((numSectors - 4) + PointerSectors - 1)/PointerSectors - 1;

    DEBUG('1', "iiiiiiiiiiiiiiiiiiiiiiiiiiii Extending file with %d indirect blocks and starting at block %d\n", numBlocks, startBlock);

    for (int i=startBlock; i < numBlocks + startBlock; i++) {
	if (i > indirect_last_index) {
                DEBUG('1', "============================================================Adding indirect pointer block: %d\n", i);
		indirectDataSectors[i] = new IndirectPointerBlock();
        }

        if (i == numBlocks + startBlock - 1) {
	    for (int j = 0; j < n; j++) {
                DEBUG('1', "Indirect block: %d\n", i);
                indirectDataSectors[i]->PutSector(freeMap->Find());
                numSectors++;
            }
        }
        else {
	    for (int j = 0; j < PointerSectors; j++) {
                indirectDataSectors[i]->PutSector(freeMap->Find());
                n--;
                numSectors++;
            }
        }
    }

//    numBytes += n;

//    int directs = numSectors;

 //   if (numSectors + newSectors > 4) {
//	directs = 4;
//    }

//    for (int i = numSectors; i < 4; i++)
//	directDataSectors[i] = freeMap->Find();

    /*int directs = numSectors;

    if (numSectors > 4) {
	directs = 4;
    }

    for (int i = 0; i < directs; i++)
	directDataSectors[i] = freeMap->Find();

    for (int j = 0; j < ((numSectors - 4) + PointerSectors - 1)/PointerSectors; j++) {
	indirectDataSectors[j] = new IndirectPointerBlock();
	pointerBlockSectors[j] = freeMap->Find();
	int sectors = PointerSectors;

	if (j == ((numSectors - 4) + PointerSectors - 1) - 1) {
		sectors = (numSectors - 4) - PointerSectors*j;
	}

	for (int k = 0; k < sectors; k++) {
		indirectDataSectors[j]->PutSector(freeMap->Find());\
	}
    }

    return TRUE;*/
}
#endif
