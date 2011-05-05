#include"syscall.h"
/* Address space control operations: Exit, Exec, and Join */

/* This user program is done (status = 0 means exited normally). */
void Exit(int status)
{
	printf("stub exit\n");
}	

 
/* Run the executable, stored in the Nachos file "name", and return the 
 * address space identifier
 */
SpaceId Exec(char *name)
{
	printf("stub exec\n");
}
 
/* Only return once the the user program "id" has finished.  
 * Return the exit status.
 */
int Join(SpaceId id)
{
	kernel->currentThread->Join(findThread(NULL,id));
	return 0;
}	
 

/* File system operations: Create, Open, Read, Write, Close
 * These functions are patterned after UNIX -- files represent
 * both files *and* hardware I/O devices.
 *
 * If this assignment is done before doing the file system assignment,
 * note that the Nachos file system has a stub implementation, which
 * will work for the purposes of testing out these routines.
 */
 

/* when an address space starts up, it has two open files, representing 
 * keyboard input and display output (in UNIX terms, stdin and stdout).
 * Read and Write can be used directly on these, without first opening
 * the console device.
 */


/* Fork a thread to run a procedure ("func") in the *same* address space 
 * as the current thread.
 */
void Fork(void (*func)())
{
	printf("stub fork\n");
}

/* Yield the CPU to another runnable thread, whether in this address space 
 * or not. 
 */
void Yield()
{
	printf("stub yield\n");
}	

void Halt()
{
	printf("stub halt\n");
	return;
}

