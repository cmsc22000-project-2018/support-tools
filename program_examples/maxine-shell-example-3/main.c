#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include "extension.h"

int exec(char* cm, char** argv){
  if (!strcmp(cm,"help")){
    printf("Available commands:\n");
    printf("help\neviz\nlviz\nwviz\nsviz\nabc\nletter\nquit\n");
  } else if (!strcmp(cm,"eviz")){
    eviz(argv);
  } else if (!strcmp(cm,"lviz")){
    lviz(argv);
  } else if (!strcmp(cm,"wviz")){
    wviz(argv);
  } else if (!strcmp(cm,"sviz")){
    sviz(argv);
  } else if (!strcmp(cm,"abc")){
    abc();
  } else if (!strcmp(cm,"letter")){
    letter(argv);
  } else if (!strcmp(cm,"quit")){
    return 0;
  } else {
    printf("Error: command not found. Type 'help' for a list of commands\n");
  }
  return 1;
}

int parse(char* input){
  char* separator = " ";
  char* parsed = strtok(input, separator);
  char* arg = parsed;
  char** sups = malloc(8*sizeof(char*));

  int index = 0;
  parsed = strtok(NULL, separator);
  while(parsed){
    sups[index] = parsed;
    index++;
    parsed = strtok(NULL, separator);
  }

  int final = exec(arg, sups);
  return final;
}


int main(){
  int run = 1;
  while (run){
     char* input = readline("> ");
     run = parse(input);
  }
  printf("exited\n");
  return 0;
}

