// MemoryManager.h 
//	Handles memory pages. Yay!
//

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "copyright.h"
#include "bitmap.h"
#include "synch.h"

class MemoryManager {
	public:
		MemoryManager();
		~MemoryManager();

		int getPage();
		void clearPage(int i);

		int freePages();

	private:
		BitMap* bit_mem;
		int mem_size;
		Lock* mem_lock;
};

#endif // MEMORYMANAGER_H
