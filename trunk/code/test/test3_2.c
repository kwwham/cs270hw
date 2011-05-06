/* test3_2.c */
/* --------- testing system calls : Exit, Exec, Join */
/* --------- size of the program : 11 pages          */

#include "syscall.h"

int main()
{
  Write( "Test 3_2: Write executed here\n", 40, ConsoleOutput );
	Exit(1);
}
