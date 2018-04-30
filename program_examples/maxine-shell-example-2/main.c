#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>

char** get_input(char* input){
  //appears to make space for 8 input tokens
  char** command = malloc(8 * sizeof(char*));
  //sets separator as space
  char* separator = " ";
  //temprorary variables to be modified
  char* parsed;
  int index = 0;

  //fills in parsed with the pointer to the first token
  parsed = strtok(input, separator);

  //fills in command array with tokens
  while (parsed != NULL){
    command[index] = parsed;
    index++;
    parsed = strtok(NULL, separator);
  }

  //sets the last item in command to NULL
  command[index] = NULL;

  //my code to print the tokens
/*
  for (int i = 0; i < 8; i++){
    printf("%d",i);
    printf("%s",(command[i]));
  }
*/


  //returns the list of tokens
  return command;
}


int main(int argc, char* argv[]){
  const char* exc = "./sample";
  char** command;
  char* input;
  pid_t child_pid;
  int stat_loc;

  while(1){
    //counts "unixsh> " as a prompt, reads after that
    input = readline("unixsh> ");

    //calls get_input (below)
    command = get_input(input);

    //if the user didn't do anything
    if (!command[0]){
      free(input);
      free(command);
      continue;
    }
    if (!strcmp(command[0],"quit"))
      return 0;

    child_pid = fork();
    if (child_pid == 0){
      execvp(command[0], command);
      execvp(exc, command);
      printf("Printing this means execvp failed\n");
    } else{
      waitpid(child_pid, &stat_loc, WUNTRACED);
    }

  
//  if (child_pid == 0){
//    printf("### Child ###\nCurrentPID: %d and Child PID %d\n", getpid(), child_pid);
//    sleep(1);
//  } else{
//    printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid); 
//  }


    free(input);
    free(command);
  }
  return 0;
}


