// SysOpenFile.h 

#ifndef SYSOPENFILE_H
#define SYSOPENFILE_H

#include "openfile.h"
#include "bitmap.h"
#include "syscall.h"

class Lock;

#define SOFILETABLE_SIZE 128

class SysOpenFile {
	public:
		SysOpenFile(char* name, OpenFile* f, OpenFileId ID);
		~SysOpenFile();

		OpenFile* file;
		OpenFileId FileID;
		char* fileName;

		int userOpens;

		Lock* lock;

		//void close();
};

class SysOpenFileManager {
	public:
		SysOpenFileManager();
		~SysOpenFileManager();

		int Add(SysOpenFile* newSysOpenFile);
		SysOpenFile* Get(char* fileName, int& index);
		SysOpenFile* Get(int index);

		//OpenFileId NextID();

		Lock* fm_lock;

		void Close(int index);

	private:
		SysOpenFile* sysOpenFileTable[SOFILETABLE_SIZE];
		BitMap* bitMap;
};

#endif // SYSOPENFILE_H
