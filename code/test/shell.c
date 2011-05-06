#include "syscall.h"

int main()
{
    SpaceId newProc;
    OpenFileId output = ConsoleOutput;

	Write("\nBefore join\n", 20, output);

	newProc = Exec("../test/test3_2");

	Write("\nafter Exec\n", 20, output);

	Join(newProc);

	Write("\nAfter join\n", 20, output);
}

