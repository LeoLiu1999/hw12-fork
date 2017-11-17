#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(){
  srand(time(NULL));
  
  int rando = rand()%15 + 5;
  int is_parent = fork();

  if ( is_parent ) {
    rando = rand()%15 + 5;
    is_parent = fork();
  }
  
  if ( is_parent ) { //parent
    printf("%d: Yo dawg I'm a parent.\n", getpid());
    int status;
    wait(&status);
    printf("My kid woke me up after %d seconds.\n",WEXITSTATUS(status));
    
  }
  else { //child
    printf("%d: Hai, I'm a child!\n", getpid());
    printf("%d: Going for a %d sec nap zzz\n", getpid(), rando);
    sleep(rando);
    printf("%d: I'm up!\n", getpid());
    return rando;
  }

  
  
  return 0;
}
