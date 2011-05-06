#ifndef PCB_H
#define PCB_H

#include "syscall.h"
#include "UserOpenFile.h"
#include "bitmap.h"

class Thread;

#define MAX_USER_FILES 32

class PCB {
	public:
		PCB(SpaceId c_pid, SpaceId c_parent_pid, Thread* c_thread, int c_status);
		~PCB();

		SpaceId GetPID();
		SpaceId GetParentPID();
		void SetParentPID(SpaceId pid);

		Thread* GetThread();
		void SetThread(Thread* newThread);

		int GetStatus();
		void SetStatus(int stat); // 0 = normal, > 1 = bad, -1 = running

		void AddFile(UserOpenFile* file);
		UserOpenFile* GetFile(int index);
		void CloseFile(UserOpenFile* file);

	private:
		SpaceId pid;
		SpaceId parent_pid;
		Thread* thread;
		int status;

		BitMap* files;
		UserOpenFile* openFiles[MAX_USER_FILES]; // ADD BITMAP TO HANDLE ACCESS TO ARRAY
};

#endif // PCB_H
