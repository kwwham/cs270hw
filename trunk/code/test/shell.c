#include "syscall.h"

int main()
{
    SpaceId newProc;
    OpenFileId output = ConsoleOutput;

	Write("Before join!!\n", 13, output);

	newProc = Exec("../test/test5");

	Write("after Exec\n", 15, output);

	Join(newProc);

	Write("\nAfter join\n", 20, output);
	Halt();
}

