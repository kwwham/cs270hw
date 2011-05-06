/* test_exec.c*/
/* --------- testing system calls : Exec by calling test5 */
/* --------- size of the program : 12 pages			      */

#include "syscall.h"

int main()
{

  Exec("./test5");
  Halt(0);
}
