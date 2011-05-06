/* test1.c */
/* --------- testing system calls of Create, Read, Write, Open, Close */
/* --------- size of the program : 17 pages			      */

#include "syscall.h"

char usr_buffer_0[256];
char usr_buffer_1[256];

int main()
{
  int i;
  OpenFileId f0, f1;

  Create( "sujay" );
  Create( "young" );
  
  f0 = Open( "sujay" );    
  f1 = Open( "young" );
  
  Write( " This is sujay's file 0\n", 22, f0 );
  Write( " This is young's file 1 appened with data in sujay's file  \n", 50, f1 );

  for( i=0 ; i < 256 ; ++i ) usr_buffer_0[i] = 'A';
    
  Write( usr_buffer_0, 128, f0 );
  
  /* reset file pointer of f0 to the starting position */
  Close( f0 );
  f0=Open( "sujay" );

  Read( usr_buffer_1, 128, f0 );
  Write( usr_buffer_1, 128, f1 );
  Close( f0 );
  Close( f1 );
  
  Halt(0);
}
