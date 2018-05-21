#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "features.h"
#include "viz_functions.h"
#include "testables.h"

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
                                {"eviz", exec_eviz, "for an exhaustive visualization\n"
                                    "     - need to use with a number to represent the index of the trie you're visualizing"},
                                {"lviz", exec_lviz, "for a leaf visualization\n"
                                    "     - need to use with a number to represent the index of the trie you're visualizing"}, 
                                {"wviz", exec_wviz, "for a word visualization\n"
                                    "     - need to use with a number to represent the index of the trie you're visualizing"},
                                {"sviz", exec_sviz, "for a subtree visualization\n"
                                    "     - need to use with a number to represent the index of the trie you're visualizing\n     - and an input string"}
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

int exec_general_viz(char** sups, char which_viz)
{
  if (sups[0] == NULL){
    return -1;
  }
  trie_t* t = get_trie(sups[0]) ;
  if (t == NULL){
    return -1;
  }

  char* path = "";
  char* input = "and";
  int level = 0;
  char** return_array;
  int return_index;
  char** visualization_arr;

  if (which_viz == 'e')
    return eviz(t, path, level, return_array, &return_index);
  else if (which_viz == 'l')
    visualization_arr = lviz(t, path, level, return_array, &return_index);
  else if (which_viz == 'w')
    visualization_arr = wviz(t, path, level, return_array, &return_index);
  else if (which_viz == 's')
    return sviz(t, input, path, level, return_array, &return_index);
  
  print_viz(visualization_arr, &return_index);
  return 1; 
}

int exec_lviz(char** sups)
{
  return exec_general_viz(sups, 'l');
}

int exec_eviz(char** sups)
{
  return exec_general_viz(sups, 'e');
}

int exec_wviz(char** sups)
{
  return exec_general_viz(sups, 'w');
}

int exec_sviz(char** sups)
{
  return exec_general_viz(sups, 's');
}

int quit(char** sups){
  printf("%s\n",sups[0]);
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
  trie_t** tries = return_trie_list();
  int index = atoi(index_str);
/*  if (index >= num_tries){
    return NULL;
  }
*/
  return tries[index]; 
}
