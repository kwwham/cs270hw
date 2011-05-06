/* test3_1.c */
/* --------- testing system calls : Exit, Exec, Join */
/* --------- size of the program : 11 pages          */

#include "syscall.h"

int main()
{
  Write( "test 3_1: Write executed \n", 24, ConsoleOutput );
  Exit( 0 );
}
