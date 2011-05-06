/* test_exec.c*/
/* --------- testing system calls : Exec by calling test5 */
/* --------- size of the program : 12 pages			      */
#include "syscall.h"

void foo()
{
  Write("test write from test.c\n", 22, ConsoleOutput);
}

int main()
{
  Exec("../test/test1");
  Fork(foo);
  Halt(0);
}
