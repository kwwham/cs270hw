/* test3.c */
/* --------- testing system calls : Exit, Exec, Join */
/* --------- size of the program : 12 pages			      */

#include "syscall.h"

int main()
{
  int i;

  Exec("../test/test3_1");
 
  //for( i=0 ; i < 5 ; ++i ) 

	Join(Exec("../test/test3_2"));
  
  Halt(0);
}
