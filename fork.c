#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(){

  srand( time(NULL) );

  int first, second, third, status;
  first = getpid();
  fork();
  if(getpid() == first){
    printf("pid of parent: %d\n", getpid());
    fork();
  }
  else{
    second = getpid();
    printf("pid of first child: %d\n", second);
    status = (rand()% 16) +5;
    printf("wait time: %d\n", status);
    wait(20);
  }
  if(getpid() != first && getpid()!= second){
    third = getpid();
    printf("pid of second child: %d\n", getpid());
    status = (rand()% 16) +5;
    printf("wait time: %d\n", status);
    wait(status);
  }
  return 0;
}
