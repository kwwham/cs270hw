// MemoryManager.c 
//	Implements memory manager. Yay!
//

#include "copyright.h"
#include "MemoryManager.h"
#include "system.h"
#include "machine.h"

MemoryManager::MemoryManager() {
	bit_mem = new BitMap(NumPhysPages);
	mem_size = NumPhysPages;
	mem_lock = new Lock("memory_lock");
	DEBUG('m', "MEMORY MANAGER CREATED ================================ WITH SIZE %d\n", bit_mem->NumClear());
}

MemoryManager::~MemoryManager() {
	delete mem_lock;
	delete bit_mem;
}

int MemoryManager::getPage() {
	mem_lock->Acquire();
	int page_num = bit_mem->Find();

	if (page_num < 0) {
		DEBUG('f', "Ran out of physical memory!\n");
	}
	mem_lock->Release();

	return page_num;
}

void MemoryManager::clearPage(int i) {
	mem_lock->Acquire();

	if ((i > mem_size)||(i < 0)) {
		DEBUG('f', "Attempted to clear a non-existant physical memory page!\n");
		return;
	}

	bit_mem->Clear(i);
	mem_lock->Release();
}

int MemoryManager::freePages() {
	mem_lock->Acquire();
	int temp = bit_mem->NumClear();
	mem_lock->Release();

	return temp;
}
