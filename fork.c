#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <string.h>

int main(){

  srand( time(NULL) );

  int pid, first, status;
  first = pid = getpid();
  printf("initial msg: pid of parent: %d\n", pid);
  pid = fork();
  //error printing
  if (pid < 0) {
        printf("Errno number: %d\n", errno);
        printf("Something went wrong with fork, likely memory issue\nMessage: %s\n", strerror(errno));
        exit (1);
    }
  //parent
  if(pid){
    pid = fork();
    if(getpid() == first){
      printf ("Child process %d ended first.\n", wait (&status));
      printf("wexit status of status/ num of sec before end: %d\n", WEXITSTATUS(status));
      printf("Parent ended\n");
    }
  }
  //error printing
  if (pid < 0) {
        printf("Errno number: %d\n", errno);
        printf("Something went wrong with fork, likely memory issue\nMessage: %s\n", strerror(errno));
        exit (1);
    }
  if(!pid){
    srand(getpid());
    //srand(time(NULL));
    int timel = (rand() % 16) + 5;
    printf("child pid: %d\n", getpid());
    //printf("time: %d\n", timel);
    sleep(timel);
    return timel;
  }

  return 0;
}
