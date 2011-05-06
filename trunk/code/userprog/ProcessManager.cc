// ProcessManager.c 
//	Implements process manager. Yay!
//

#include "copyright.h"
#include "ProcessManager.h"

ProcessManager::ProcessManager() {
	processIDs = new BitMap(MAX_PROCESS);
	pcbs = new PCB*[MAX_PROCESS];
	conditions = new Condition*[MAX_PROCESS];
	locks = new Lock*[MAX_PROCESS];
	joins = new int[MAX_PROCESS];

	pm_lock = new Lock("pm lock");
}

void ProcessManager::AddProcess(PCB* pcb) {
	pm_lock->Acquire();
	if (pcb == NULL) {
		return;
	}

	SpaceId pid = pcb->GetPID();
	pcbs[pid] = pcb;
	conditions[pid] = new Condition("condition");
	locks[pid] = new Lock("PCB lock");
	joins[pid] = 0;
	pm_lock->Release();
}

ProcessManager::~ProcessManager() {
	delete processIDs;
	delete pcbs;
	delete conditions;
	delete locks;
	delete joins;

	delete pm_lock;
}

SpaceId ProcessManager::GetPID() {
	return processIDs->Find();
}

void ProcessManager::ClearPID(SpaceId pid) {
	pm_lock->Acquire();
	if (pid > MAX_PROCESS) {
		// THROW AN ERROR
		pm_lock->Release();
		return;
	}

	if (!processIDs->Test(pid)) {
		pm_lock->Release();
		return;
	}

	locks[pid]->Acquire();

	pcbs[pid] = NULL;

	delete conditions[pid];
	conditions[pid] = NULL;

	locks[pid]->Release();

	delete locks[pid];
	locks[pid] = NULL;

	processIDs->Clear(pid);
	pm_lock->Release();
}


void ProcessManager::Join(SpaceId pid) {
	pm_lock->Acquire();
	printf(" pid > MAx number of process -> %d > %d\n in processmanager.cc\n",pid,MAX_PROCESS);

	if (pid > MAX_PROCESS) {
		// THROW AN ERROR
		pm_lock->Release();
		return;
	}

	if (!processIDs->Test(pid)) {
		pm_lock->Release();
		return;
	}

	locks[pid]->Acquire();
	joins[pid] += 1;

	pm_lock->Release();

	while(1) {
		pm_lock->Acquire();
		if (pcbs[pid]->GetStatus() > -1) {
			locks[pid]->Release();
			pm_lock->Release();
			return;
		}

		DEBUG('z', "Joined to pid %d\n", pid);
		pm_lock->Release();
		conditions[pid]->Wait(locks[pid]);
	}
}

int ProcessManager::GetJoins(SpaceId pid) {
	pm_lock->Acquire();
	if (pid > MAX_PROCESS) {
		// THROW AN ERROR
		pm_lock->Release();
		return -1;
	}

	if (processIDs->Test(pid)) {
		pm_lock->Release();
		return joins[pid];
	}

	pm_lock->Release();

	return -1;
}

void ProcessManager::DecrementJoins(SpaceId pid) {
	pm_lock->Acquire();
	if (pid > MAX_PROCESS) {
		// THROW AN ERROR
		pm_lock->Release();
		return;
	}

	if (!processIDs->Test(pid)) {
		pm_lock->Release();
		return;
	}

	if (processIDs->Test(pid)) {
		if (joins[pid] > 0) {
			joins[pid] -= 1;
		}
	}
	pm_lock->Release();
}

void ProcessManager::Broadcast(SpaceId pid) {
	pm_lock->Acquire();
	if (pid > MAX_PROCESS) {
		// THROW AN ERROR
		pm_lock->Release();
		return;
	}

	if (!processIDs->Test(pid)) {
		pm_lock->Release();
		return;
	}

	locks[pid]->Acquire();
	conditions[pid]->Broadcast(locks[pid]);
	DEBUG('z', "Broadcasting for pid %d\n", pid);
	locks[pid]->Release();

	pm_lock->Release();

	return;
}

int ProcessManager::GetStatus(SpaceId pid) {
	pm_lock->Acquire();
	if (pid > MAX_PROCESS) {
		// THROW AN ERROR
		pm_lock->Release();
		return -1;
	}

	if (!processIDs->Test(pid)) {
		pm_lock->Release();
		return -1;
	}

	pm_lock->Release();

	return pcbs[pid]->GetStatus();
}
