// ProcessManager.h 
//	Process Manager. Yay!
//

#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "copyright.h"
#include "synch.h"
#include "bitmap.h"
#include "syscall.h"
#include "PCB.h"
#define MAX_PROCESS MemorySize/UserStackSize*2


class ProcessManager {
	public:
		ProcessManager();
		~ProcessManager();

		void AddProcess(PCB* pcb);

		SpaceId GetPID(); // Return an unused id
		void ClearPID(SpaceId pid); // Clear a process id
	
		void Join(SpaceId pid); // wait on PID
		void Broadcast(SpaceId pid); // Broadcast the "pid" process in Exit

		int GetStatus(SpaceId pid); // Get process's status by pid

		int GetJoins(SpaceId pid);
		void DecrementJoins(SpaceId pid);
	
	private:
		PCB** pcbs;
		Condition** conditions;
		Lock** locks;
		int* joins;

		Lock* pm_lock;

		BitMap* processIDs;
};

#endif // PROCESSMANAGER_H
