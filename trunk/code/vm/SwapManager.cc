#include "SwapManager.h"
#include "system.h"

SwapManager::SwapManager() {
	ASSERT(fileSystem->Create("SWAP", SWAPSIZE*PageSize));
	
	swap = fileSystem->Open("SWAP");

	if (swap == NULL) {
		// THROW AN ERROR
		printf("Could not create a SWAP file! Can't run virtual memory!\n");
		interrupt->Halt();
	}

	bitmap = new BitMap(SWAPSIZE);
	PIDs = new SpaceId[SWAPSIZE];
	entries = new TranslationEntry*[SWAPSIZE];
}

SwapManager::~SwapManager() {
	delete swap;
	delete bitmap;
	delete PIDs;
	delete entries;
}

bool SwapManager::addPage(TranslationEntry* page, SpaceId pid, char* buffer, int size) {
	//if ((pid > SWAPSIZE)&&(pid < 0)) {
	//	return false;
	//}

	DEBUG('q', "Adding a page to the swap file...with pid %d and vpn %d\n", pid, page->virtualPage);

	for (int i=0; i < SWAPSIZE; i++) {
		if ((PIDs[i] == pid)&&(bitmap->Test(i))&&(entries[i]->virtualPage == page->virtualPage)) {
			if (swap->WriteAt(buffer, size, PageSize*i) != PageSize) {
				return false;
			}

			//DEBUG('q', "Found the page in swap already when adding...\n");

			return true;
		}
	}

	//DEBUG('q', "Did NOT find the page in swap already when adding...\n");

	int free = bitmap->Find();

	DEBUG('q', "**********************free page is %d and adding the owner as %d\n",free,pid);
	if (free == -1) {
		printf("Out of virtual memory!\n");
		Exit(1);
		//return false;
	}

	entries[free] = page;
	PIDs[free] = pid;

	if (swap->WriteAt(buffer, size, PageSize*free) != PageSize) {
		return false;
	}
}

bool SwapManager::addPage(TranslationEntry* page, SpaceId pid, int size) {
	DEBUG('q', "Adding a page to the swap file...with pid %d and vpn %d\n", pid, page->virtualPage);
	for (int i=0; i < SWAPSIZE; i++) {
		if ((PIDs[i] == pid)&&(bitmap->Test(i))&&(entries[i]->virtualPage == page->virtualPage)) {
			return true;
		}
	}
	int free = bitmap->Find();
	if (free == -1) {
		printf("Out of virtual memory!\n");
		Exit(1);
		//return false;
	}

	entries[free] = page;
	PIDs[free] = pid;
}
void SwapManager::writePage(SpaceId pid, int vpn, char* buffer) {
	DEBUG('q', "Writing a page back to the swap file...\n");

	for (int i=0; i < SWAPSIZE; i++) {
		if ((PIDs[i] == pid)&&(entries[i]->virtualPage == vpn)&&(bitmap->Test(i))) {
			if (swap->WriteAt(buffer, PageSize, PageSize*i) != PageSize) {
				DEBUG('q', "Error writing dirty page into swap file!\n");
				ASSERT(false);
			}
			
			return;
		}
	}

	DEBUG('q', "Trying to write back a page not in the swap file. ERROR.\n");
	ASSERT(false);
}

void SwapManager::removePages(SpaceId pid) {
	DEBUG('q', "Removing a page from the swap file for PID %d...\n", pid);

	for (int i=0; i < SWAPSIZE; i++) {
		if (PIDs[i] == pid) {
			PIDs[i] = -1;

			if (bitmap->Test(i)) {
				bitmap->Clear(i);
				entries[i] == NULL;
	DEBUG('q', "entries for page %d removed from the swap file for PID %d...\n",i, pid);
			}
		}
	}
}

// ASSUMES BUFFER IS BIG ENOUGH TO HOLD A PAGE
TranslationEntry* SwapManager::findPage(SpaceId pid, int vpn, char* buffer) {
	DEBUG('q', "Finding a page in the swap file...with pid %d, vpn %d\n", pid, vpn);
//	DEBUG('q'," line 100 SwapManager.cc ->Swap size =% d",SWAPSIZE);
	for (int i=0; i < SWAPSIZE; i++) {
		//DEBUG('q', "WHAT\n");
		//bool b = (PIDs[i] == pid);
		//DEBUG('q', "THE\n");
		//bool c = (entries[i]->virtualPage == vpn);
		//DEBUG('q', "HELL\n");
		//bool d = (bitmap->Test(i));
//		DEBUG('q'," i =%d\n",i);
		if ((PIDs[i] == pid)&&(bitmap->Test(i))&&(entries[i]->virtualPage == vpn)) {

					//DEBUG('q',"pageSize =%d\n",PageSize);
			if (swap->ReadAt(buffer, PageSize, PageSize*i) != PageSize) {
				// THROW AN ERROR
				DEBUG('q'," throw error in Swapmanager.cc line 111\n");
			}
//						DEBUG('q'," exiting this function findPage at line 116 and entries[%d]= %d",i,entries[i]);
			return entries[i];
		}
	}

	DEBUG('q', "Page not found in swap file...\n");
	
	return NULL;
}
