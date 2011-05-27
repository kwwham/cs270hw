// VMManager.h 
//	Class for handling the virtual memory manager file for Project 3

#ifndef VMMANAGER_H
#define VMMANAGER_H

#include "copyright.h"
#include "translate.h"
#include "SwapManager.h"
#include "syscall.h"
#include "synch.h"
class LRU {
	public:
		LRU();
		~LRU();

		TranslationEntry* GetLRU();
		void RecentlyUsed(TranslationEntry* entry);
		void Remove_LRU_Page();
		int tail_pid();
		void AddPage(TranslationEntry* page,int pid);
		void RemovePage(SpaceId pid);
		

	protected:
		class LRU_Node {
			public:
				LRU_Node(TranslationEntry* page) { value = page; next = NULL; }
				LRU_Node* next;
				LRU_Node* prev;
				TranslationEntry* value;
				int pid;
		};

	private:
		LRU_Node* FindPage(TranslationEntry* page, LRU_Node& prev_node);
		LRU_Node* get_tail();
		void replace_head(TranslationEntry* entry);
		void replace_head(LRU_Node* node);
		LRU_Node* head;
		LRU_Node* tail;
		Lock* LRU_lock;
};

class VMManager {
	public:
		VMManager();
		~VMManager();

		bool AddPage(TranslationEntry* page, SpaceId pid, char* buffer, int size);
		bool AddPage(TranslationEntry* page, SpaceId pid,int size);

		bool GetPage(TranslationEntry* page, SpaceId pid, char* buffer, int size);
		//void WritePage();

		void CopyPage(TranslationEntry* page, SpaceId oldPID, SpaceId newPID);
		void RemovePages(SpaceId pid);

		void Mark(TranslationEntry* page);

		void Swap(int vpn, SpaceId pid); // Swap into main memory

		int free() { swap->free(); }

	private:
		LRU* lru;
		SwapManager* swap;
};

#endif // VMMANAGER_H
