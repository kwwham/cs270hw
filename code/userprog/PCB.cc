#include "PCB.h"
#include "system.h"

PCB::PCB(SpaceId c_pid, SpaceId c_parent_pid, Thread* c_thread, int c_status) {
	DEBUG('z', "Started making PCB\n");
	pid = c_pid;
	parent_pid = c_parent_pid;
	thread = c_thread;
	status = c_status;

	files = new BitMap(MAX_USER_FILES);

	DEBUG('z', "Finished making PCB\n");
}

SpaceId PCB::GetPID() {
	return pid;
}

SpaceId PCB::GetParentPID() {
	return parent_pid;
}

void PCB::SetParentPID(SpaceId p_pid) {
	parent_pid = p_pid;
}

Thread* PCB::GetThread() {
	return thread;
}

void PCB::SetThread(Thread* newThread) {
	thread = newThread;
}

int PCB::GetStatus() {
	return status;
}

void PCB::SetStatus(int stat) {
	status = stat;
}

void PCB::AddFile(UserOpenFile* file) {
	int index = files->Find();

	if (index > -1) {
		openFiles[index] = file;
	}
}

UserOpenFile* PCB::GetFile(int index) {
	if (files->Test(index)) {
		return openFiles[index];
	}

	return NULL;
}

void PCB::CloseFile(UserOpenFile* file) {
	for(int i=0; i<MAX_USER_FILES; i++) {
		if (files->Test(i) && openFiles[i] == file) {
			fm->Close(file->index);
			delete openFiles[i];
			files->Clear(i);
			return;
		}		
	}
}
