// SwapManager.h 
//	Class for handling the swap file for Project 3

#ifndef SWAPMANAGER_H
#define SWAPMANAGER_H

#include "copyright.h"
#include "openfile.h"
#include "bitmap.h"
#include "translate.h"
#include "syscall.h"

#define SWAPSIZE 256 //total free sector available

class SwapManager {
	public:
		SwapManager();
		~SwapManager();

		bool addPage(TranslationEntry* page, SpaceId pid, char* buffer, int size);
		bool addPage(TranslationEntry* page, SpaceId pid,int size);
		void removePages(SpaceId pid);

		TranslationEntry* findPage(SpaceId pid, int vpn, char* buffer);
		void writePage(SpaceId pid, int vpn, char* buffer);

		int free() { bitmap->NumClear(); }

	private:
		OpenFile* swap;
		BitMap* bitmap;
		TranslationEntry** entries;

		SpaceId* PIDs;
};

#endif // SWAPMANAGER_H
