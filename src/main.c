#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include "features.h"


int parse(char* input){
  char* separator = " ";
  char* parsed = strtok(input, separator);
  char* arg = parsed;
  char** sups = calloc(8,sizeof(char*));

  int index = 0;
  parsed = strtok(NULL, separator);
  while(parsed){
    sups[index] = parsed;
    index++;
    parsed = strtok(NULL, separator);
  }

  int final = exec(arg, sups);
  if (final == 0)
    printf("Invalid input; please try again.\n"
           "For a list of commands, type help\n");
  else if (final == -1)
    printf("Program error - please try again\n");
  return final;
}


int main(){
  std_indent("Welcome to our Trie Visualizations tool! You can use this tool to visualize tries in terms of:\n"
  "    - all their nodes (print <trie> all-nodes)\n"
  "    - only the leaves (print <trie> only-leaves)\n"
  "    - only the words (print <trie> only-words\n"
  "    - a certain number of completions for a given prefix (n-completions <trie> <prefix> <n>)\n"
  "Additionally, add a prefix to any of the first three commands to see that visualization for the sub-trie beginning with that prefix\n"
  "For more help, type 'help'\n"
  "To exit, type 'quit'\n");
  int run = 1;
  while (run != -2){
     char* input = readline("> ");
     run = parse(input);
  }
  printf("Exited.\n");
  return 0;
}

