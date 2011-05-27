#include "VMManager.h"
#include "system.h"

TranslationEntry* LRU::GetLRU() {
	return tail->value;
}

LRU::LRU() {
	tail =NULL;
	head = NULL;
	LRU_lock = new Lock("LRU Semaphore");
}

// WRITE ME
LRU::~LRU() {

}
/*
void LRU::RecentlyUsed(TranslationEntry* entry) {
	replace_head(entry);
}
*/
void LRU::AddPage(TranslationEntry* page, int pid) {
	LRU_lock->Acquire();
	LRU_Node* new_node = new LRU_Node(page);
	/* ADDED */
	new_node->pid =pid;
	replace_head(new_node);
	LRU_lock->Release();
}

void LRU::RemovePage(SpaceId pid) {
	LRU_lock->Acquire();
	LRU_Node *prev,*next,*current;
	current = head;
	//LRU_Node* temp = tail;
	//if (head->value == page) {
	//	return;
	//}
	
	while (current != NULL) {
		if (current->pid == (int) pid) {
			memory->clearPage(current->value->physicalPage);
			prev =current->prev;
			next = current->next;

			if (prev != NULL) {
				prev->next = current->next;
//				current->next->prev = prev;
			}
			if(next!=NULL)
			{
				next->prev =current->prev;
			}
			if(head ==current)
			{
				head =current->next;
			}
			if( tail =current) 
			{
				tail =current->next;
			}
			//current->next = head;
			//head->prev = current;
			//head = current;
			delete current;
			current =next;
			//return;
		}else
		{		
		//prev = current;
		current = current->next;
		}
	}
	LRU_lock->Release();
}
void LRU::Remove_LRU_Page()
{
	LRU_Node* temp =tail;
	tail = tail->prev;
	tail->next= NULL;
	delete (temp);
}
int LRU::tail_pid()
{
	return tail->pid;
}
/*
void LRU::replace_head(TranslationEntry* entry) {
	//LRU_lock->Acquire();
	LRU_Node* prev = NULL;
	LRU_Node* current = head;
	
	if (head == entry) {
		return;
	}
	if (head == NULL)
	{
		head = node;
		tail = node;
		node->next =NULL;
		node->prev =NULL;
		return;
	}
	while (current != NULL) {
		if (current->value == entry) {
			if (prev != NULL) {
				prev->next = current->next;
				current->next->prev = prev;
			}
			current->next = head;
			head->prev = current;
			head = current;
			return;
		}
		
		prev = current;
		current = current->next;
	}

	//node->next = head;
	//node->prev = NULL;
	//head->prev = node;
	//head = node;
}
*/
void LRU::replace_head(LRU_Node* node) {
	LRU_lock->Acquire();
	LRU_Node* prev = NULL;
	LRU_Node* current = head;
	if(head ==NULL)
	{
		head = node;
		tail = node;
		node->next = NULL;
		node->prev =NULL;
		//tail = head ;
		return;
	}
	if (head == node) {
		return;
	}
	int i=0;
	while (current != NULL) {
		if (current == node) {
			if (prev != NULL) {
				prev->next = current->next;
				//current->next->prev = prev;
			}
			if(current->next!=NULL)
			{
				current->next->prev =current->prev;
			}
			current->next = head;
			head->prev = current;
			head = current;
			return;
		}
		
		prev = current;
		current = current->next;
	}

	node->next = head;
	node->prev = NULL;
	head->prev = node;
	head = node;
	LRU_lock->Release();
}

LRU::LRU_Node* LRU::FindPage(TranslationEntry* page, LRU_Node& prev_node) {

}

VMManager::VMManager() {
	lru = new LRU();
	swap = new SwapManager();
}

VMManager::~VMManager() {
	delete lru;
	delete swap;
}

bool VMManager::AddPage(TranslationEntry* page, SpaceId pid, char* buffer, int size) {
	DEBUG('3', "Z %d: %d\n", pid, page->virtualPage);
	return swap->addPage(page, pid, buffer, size);
}
bool VMManager::AddPage(TranslationEntry* page, SpaceId pid, int size) {
	DEBUG('3', "Z %d: %d\n", pid, page->virtualPage);
	return swap->addPage(page, pid,size);
}


void VMManager::RemovePages(SpaceId pid) {
	lru->RemovePage(pid);
	swap->removePages(pid);
}

bool VMManager::GetPage(TranslationEntry* page, SpaceId pid, char* buffer, int size) {
	if (swap->findPage(pid, page->virtualPage, buffer) != NULL) {
		return true;
	}

	return false;
}

void VMManager::CopyPage(TranslationEntry* page, SpaceId oldPID, SpaceId newPID) {
	char buffer[PageSize];

	swap->findPage(oldPID, page->virtualPage, buffer);
	swap->addPage(page, newPID, buffer, PageSize);
}

void VMManager::Swap(int vpn, SpaceId pid) {
	int proc_kill;
	TranslationEntry* page;
	// No swap necessary, we have enough memory available
	if (memory->freePages() != 0) {
		int phys_page = memory->getPage();
		//DEBUG('q', "Swapping into main memory page %d\n", phys_page);
		char* paddr = machine->mainMemory + phys_page*PageSize;
		page = swap->findPage(pid, vpn, paddr);
		page->physicalPage = phys_page;
		lru->AddPage(page,pid);
		DEBUG('3', "L %d: %d -> %d\n", pid, vpn, phys_page);
	}
	else {
		// Assumption is, if its in main memory,
		// its in the swap file as well
		proc_kill = lru->tail_pid();
		TranslationEntry* victim = lru->GetLRU();
		DEBUG('q', "================= Finding a victim to swap out of main memory page %d\n", victim->physicalPage);
		victim->valid = false;
		char* paddr = machine->mainMemory + victim->physicalPage*PageSize;
		if (victim->dirty) {
			DEBUG('3', "S %d: %d\n", pid, victim->physicalPage);
			swap->writePage(pid, victim->virtualPage, paddr);
		}
		else {
			DEBUG('3', "E %d: %d\n", pid, victim->physicalPage);
		}
		page = swap->findPage(pid, vpn, paddr);
		page->physicalPage = victim->physicalPage;
		lru->AddPage(page,pid);
		lru->Remove_LRU_Page();
	}

	page->valid = true;
	page->dirty = false;
}

