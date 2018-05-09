#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "features.h"
#include "testables.h"
#include "lviz_wviz_draft.h"

/* Setup to allow for handler array */
typedef int (*command_function)(char** sups);

struct command
{
    char* command;
    command_function func;
    char* help_text;
};

/* Array containing existing commands and their relevant functions */
struct command features[] = {
                                     {"help", help, "for a list of commands"}, 
                                     {"quit", quit, "to exit the shell"}, 
                                     {"lviz", exec_lviz, "for a leaf visualization\n"
                                       "     - need to use with a number to represent the index of the trie you're visualizing"}, 
                                     {"wviz", exec_wviz, "for a word visualization\n"
                                       "     - need to use with a number to represent the index of the trie you're visualizing"}, 
                                     };

/* Number of features */
int num_features = sizeof(features) / sizeof(struct command);


int exec(char* arg, char* sups[])
{
  for (int i = 0; i < num_features; i++){
    if (strcmp(features[i].command, arg) == 0){
      return features[i].func(sups);
    }
  }
  return -1;
}

int exec_lviz(char** sups)
{
  if (sups[0] == NULL){
    return -1;
  }
  trie_t* t = get_trie(sups[0]) ;
  if (t == NULL){
    return -1;
  }

  char* path = "";
  int level = 0;
  char* return_array[] = {"test"};
  int return_index;
  
  char** visualization_arr = lviz(t, path, level, return_array, &return_index);
  
  print_viz(visualization_arr, &return_index);
  return 1;
}

int exec_wviz(char** sups)
{
  if (sups[0] == NULL){
    return -1;
  }
  trie_t* t = get_trie(sups[0]);
  if (t == NULL){
    return -1;
  }

  char* path = "";
  int level = 0;
  char* return_array[] = {"test"};
  int return_index;
  
  char** visualization_arr = wviz(t, path, level, return_array, &return_index);
  
  print_viz(visualization_arr, &return_index);
  return 1;
}

int quit(char** sups){
  return 0;
}

int help(char** sups){
  sups++;
  for (int i = 0; i < num_features; i++){
    printf("%s - %s\n", features[i].command, features[i].help_text);
  }
  return 1;
}

trie_t* get_trie(char* index_str)
{
  int index = atoi(index_str);
  if (index >= num_tries){
    return NULL;
  }
  return tries[index]; 
}
