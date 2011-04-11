// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"

// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

#ifdef CHANGED && THREADS
int SharedVariable;

void
SimpleThread(int which)
{
	int num, val;
	
	for(num = 0; num < 5; num++) {
	    val = SharedVariable;
	    printf("*** thread %d sees value %d\n", which, val);
	    currentThread->Yield();
	    SharedVariable = val+1;
	    currentThread->Yield();
	}
	val = SharedVariable;
	printf("Thread %d sees final value %d\n", which, val);
}
#else
void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}
#endif

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

#ifdef CHANGED && THREADS

void
ThreadTest(int n)
{
	DEBUG('t', "Entering ThreadTest invoking n threads");
	
	Thread *ts[n];
	
	for(int i=0;i<n;i++)
	{
		ts[i] = new Thread("forked thread"); //strcat("forked thread ", "itoc(i, buf, 10)")); // I am not sure whether it itoc works or not - I haven't check it. 
		
		ts[i]->Fork(SimpleThread, i);  						
	}
	
	/* the original code
    Thread *t = new Thread("forked thread");
	
    t->Fork(SimpleThread, 1);
    SimpleThread(0);
	 */
	
}

#endif



//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
    switch (testnum) {
    case 1:
	ThreadTest1();
	break;
    default:
	printf("No test specified.\n");
	break;
    }
}
