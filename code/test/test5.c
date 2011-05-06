/* test5.c */
/* --------- testing system calls : Exit, Exec, Fork */
/* --------- size of the program : 12 pages			      */

#include "syscall.h"

char usr_buffer[256]; // ADDED

void test5_1 () {
	//Read ( usr_buffer, 5, ConsoleInput ); // ADDED
	//Write( usr_buffer, 200, ConsoleOutput ); // ADDED
	//Write( "Test5 Fork(): This is test 5 after fork before Exec\n", 52, ConsoleOutput );
	
	/*
	Write( "Cow is equal to \n", 20, ConsoleOutput); // ADDED
	Yield(); // ADDED
	Write( "MEEEEE! \n", 20, ConsoleOutput);
*/
	//Yield();
	Exit(1);

}

int main()
{
  //int i;
 
  Fork(test5_1);
  Write( "\nFork 1just happened!\n", 20, ConsoleOutput);
	//Yield();
  //Fork(test5_1);
  //Write( "\nFork 2 just happened!\n", 20, ConsoleOutput);
  //for( i=0 ; i < 2 ; ++i ) {
  //	Fork( test5_1);
  //	Yield();
  //}
  //for( i=0 ; i < 2 ; ++i ) Exec( "test5_1" );
  
  Halt(0);
}
