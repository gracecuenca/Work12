#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(){

  srand( time(NULL) );

  int pid, first, status;
  first = pid = getpid();
  printf("initial msg: pid of parent: %d\n", pid);
  pid = fork();
  //parent
  if(pid){
    pid = fork();
    if(getpid() == first){
      wait(&status);
      printf("wexit status of status/ num of sec before end: %d\n", WEXITSTATUS(status));
      printf("Parent ended\n");
    }
  }

  if(!pid){
    //srand(time( (time_t *) getpid()));
    srand(time(NULL));
    int timel = (rand() % 16) + 5;
    printf("child pid: %d\n", getpid());
    sleep(timel);
    return timel;
  }

  return 0;
}
