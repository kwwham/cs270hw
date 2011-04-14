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
#include "synch.h"

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

#if defined(CHANGED) && defined(THREADS)
int SharedVariable ;

int ThreadPool[512]; // testnum is the number of thread given by user. it is setup in main.cc (extern variable)
// Implementing barriers - it is used by both HW1_SEMAPHORES and HW1_LOCKS, and maybe by (CHANGED and THREADS)
int Wait()
{
	int counter=1;
	for(int i=0;i<testnum;i++)
	{
		if(ThreadPool[i]==0)
		{
			counter=0;
			break;
		}
	}
	return counter;
}
//end of the function for barriers

#if defined(HW1_SEMAPHORES)
Semaphore *s;
#elif defined(HW1_LOCKS)
Lock *l;
#endif


#ifdef HW1_COST
char dummy[8*1024];
#endif


void
SimpleThread(int which) 
{
   	int num, val;

#ifdef HW1_COST
//char dummy[8*1024*1024];
int indexForDummy = which*10;
char c;
#endif
 
	
	for(num = 0; num < 5; num++) 
        {
#if defined(HW1_SEMAPHORES)
s->P();
#elif defined(HW1_LOCKS)
l->Acquire();
#endif

#ifdef HW1_COST
c = dummy[indexForDummy++];
#endif

	    val = SharedVariable;
	    printf("*** thread %d sees value %d\n", which, val);
	    currentThread->Yield();
	    SharedVariable = val+1;

#if defined(HW1_SEMAPHORES)
s->V();
#elif defined(HW1_LOCKS)
l->Release();
#endif

	    currentThread->Yield();
	}

	#if defined(HW1_SEMAPHORES) || defined(HW1_LOCKS)
	ThreadPool[which]=1; 	// the current thread is out of loop
        while(Wait()==0)	// and check the other threads
	{
		currentThread->Yield();
	}
	#endif

#ifdef HW1_SEMAPHORES 
s->P();
#elif defined(HW1_LOCKS)  
l->Acquire();  
#endif
	val = SharedVariable;
	printf("Thread %d sees final value %d\n", which, val);
#if defined(HW1_SEMAPHORES)
s->V();
#elif defined(HW1_LOCKS)
l->Release();
#endif
	
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

void
ThreadTest(int n) 
{
	#if defined(CHANGED) && defined(THREADS) && defined(HW1_SEMAPHORES)
  	s = new Semaphore("test",1);  
	#elif defined(CHANGED) && defined(THREADS) && defined(HW1_LOCKS)
	l = new Lock("test");
	#endif

	DEBUG('t', "Entering ThreadTest invoking n threads");
	
	Thread *ts[n];
	
	for(int i=1;i<n;i++)
	{
		ts[i] = new Thread("forked thread"); 
		ts[i]->Fork(SimpleThread, i); 				
	}
	SimpleThread(0);

	
}

void ConditionTest()
{
	const int NUM = 100;
	Thread *ts[NUM];

	Condition *condition = new Condition("my condition");
	Lock *lock = new Lock("myLock");
	
	for(int i=0;i<NUM;i++)
	{
		ts[i] = new Thread("forked thread"); 
		ts[i]->Fork(SimpleThread2, i); 				
	}
}

void SimpleThread2(int which)
{
	for(int i=0;i<10;i++)
	{
		printf("%d is running\n",which);
	}
	
}



//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
//printf("testnum=%d\n",testnum);
#ifdef CHANGED
    ThreadTest(testnum);
#else
    switch (testnum) {
    case 1:
	ThreadTest1();
	break;
    default:
	printf("No test specified.\n");
	break;
    }
#endif
}

