#include "SysOpenFile.h"
#include "synch.h"

SysOpenFile::~SysOpenFile() {
	delete lock;
}

SysOpenFile::SysOpenFile(char* name, OpenFile* f, int ID) {
	fileName = name;
	file = f;
	FileID = ID;
	userOpens = 1;
	lock = new Lock("SysOpenFile Lock");
}

SysOpenFileManager::SysOpenFileManager() {
	bitMap = new BitMap(SOFILETABLE_SIZE);
	fm_lock = new Lock("SysOpenFileManager Lock");
}

SysOpenFileManager::~SysOpenFileManager() {
	delete fm_lock;
	delete bitMap;
}

int SysOpenFileManager::Add(SysOpenFile* newSysOpenFile) {
	fm_lock->Acquire();
	int index = bitMap->Find();

	if (index < 0) {
		// THROW AN ERROR
		fm_lock->Release();
		return -1;
	}

	sysOpenFileTable[index] = newSysOpenFile;
	newSysOpenFile->FileID = index + 2;

	fm_lock->Release();

	return index;
}

SysOpenFile* SysOpenFileManager::Get(char* fileName, int& index) {
	fm_lock->Acquire();
	for (int i=0; i < SOFILETABLE_SIZE; i++) {
		if (!bitMap->Test(i)) break;
		if (strcmp(sysOpenFileTable[i]->fileName, fileName) == 0) {
			index = i;
			fm_lock->Release();
			return sysOpenFileTable[i];
		}
	}

	fm_lock->Release();

	return NULL;
}

SysOpenFile* SysOpenFileManager::Get(int index) {
	fm_lock->Acquire();
	if (index >= SOFILETABLE_SIZE) {
		// THROW AN ERROR
		fm_lock->Release();
		return NULL;
	}

	if (!bitMap->Test(index)) {
		fm_lock->Release();
		return NULL;
	}

	fm_lock->Release();

	return sysOpenFileTable[index];
}

void SysOpenFileManager::Close(int index) {
	fm_lock->Acquire();
	if (index >= SOFILETABLE_SIZE) {
		// THROW AN ERROR
		fm_lock->Release();
		return;
	}

	if (bitMap->Test(index)) {
		//sysOpenFileTable[index]->userOpens--;
		if (--sysOpenFileTable[index]->userOpens == 0) {
			delete sysOpenFileTable[index]->file;
			delete sysOpenFileTable[index];
			sysOpenFileTable[index] = NULL;
			bitMap->Clear(index);
		}
	}

	fm_lock->Release();

	//sysOpenFileTable[index]->close();
	//delete sysOpenFileTable[index];
	//sysOpenFileTable[index] = NULL;
	//bitMap->Clear(index);
}

