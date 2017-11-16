#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


char **parse_args(char * line){
  char **ret = calloc(100, 100);
  ret[0]=line;
  unsigned char i = 1;
  char * args;
  while( args = strsep(&line, " "))
    ret[i++]=args;
  return ret;
}


int main(){
  char l[100] = "ls -l -a ..";
  char *line = l;
  char **args = parse_args(line);
  printf("Executing \"%s\" with the following parameters\n", args[0]);
  unsigned char i = 1;
  while (args[i])
    printf("%s\n",args[i++]);
}
