#include "syscall.h"


// create a file "bigf1", which is 9K long.

char buffer[512];


int
main()
{
    int id,id2;
    int i;
    Create("young");
    id = Open("young");


    for (i = 0; i < 512; i++) 
      buffer[i] = 'a' + (i % 26);
   
    for (i = 0; i < 9*2; i++) 
    	Write(buffer, 512, id);

    Close(id);

   Write("young\n",6,ConsoleOutput);
   Exit(10);
}
