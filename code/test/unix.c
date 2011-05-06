#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <sys/time.h>
#include  <time.h>
#include  <unistd.h>
#include  <fcntl.h>

#define   MAX_COUNT  20
#define   BUF_SIZE   100

int timeDiff(struct timeval s, struct timeval e)
{
   return (e.tv_sec-s.tv_sec)*1000000 + (e.tv_usec-s.tv_usec);
}

void  main(void)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];
     struct timeval start, end;
     char* args[] = {};
     size_t filedesc = open("./xxx", O_WRONLY);

     gettimeofday(&start, NULL);
     fork();
     gettimeofday(&end, NULL);
     printf("*****Elapsed time for fork(): %d\n", timeDiff(start, end));

     
     pid = getpid();
     for (i = 1; i <= MAX_COUNT; i++) {
          sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
          gettimeofday(&start, NULL);
          write(1, buf, strlen(buf));
          gettimeofday(&end, NULL);
          printf("*****Elapsed time for write(): %d\n", timeDiff(start, end));
     } 
     
     gettimeofday(&start, NULL);
     execv("./unix",args);
     gettimeofday(&end, NULL);
     printf("*****Elapsed time for execv(): %d\n", timeDiff(start, end));


     gettimeofday(&start, NULL);
     read(filedesc, buf, BUF_SIZE);
     gettimeofday(&end, NULL);
     printf("*****Elapsed time for read(): %d\n", timeDiff(start, end));
     
     close(filedesc);
    return ; 
}
