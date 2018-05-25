#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/features.h"
#include "../include/viz_functions.h"
#include "../include/testables.h"

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
                                    "     - need to use with a number to represent the index of the trie you're visualizing\n     - and an input string (NOT in quotes)"},
                                {"get_children", exec_get_children, "to see children of a node\n"
                                    "     - need to use with a number to represent the index of the trie you're getting children from\n and an input string(NOT in quotes)"},
                                {"get_n_children", exec_get_n_children, "to see n children of a node\n"
                                    "     - need to use with a number to represent the index of the trie you're getting children from, an input string (not in quotes), and a number n"},
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
  return 0;
}

int exec_general_viz(char** sups, char which_viz)
{
  if (sups[0] == NULL){
    return 0;
  }
  trie_t* t = get_trie(sups[0]) ;
  if (t == NULL){
    return 0;
  }

  char* path = calloc(1000,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char** return_array = malloc(1000*sizeof(char*));

  int success;

  if (which_viz == 'e') {
    success = eviz(t, path, level, return_array, return_index);
  } else if (which_viz == 'l') {
    success = lviz(t, path, level, return_array, return_index);
  } else if (which_viz == 'w') {
    success = wviz(t, path, level, return_array, return_index);
  } else if (which_viz == 's') {
    char* input = sups[1];
    success = sviz(t, input, path, level, return_array, return_index);
  } else if (which_viz == 'c') {
    char* input = sups[1];
    success = get_children(t, input, path, level, return_array, return_index);
  } else if (which_viz == 'n') {
    char* input = sups[1];
    int n = atoi(sups[2]);
    *return_index = n;
    success = get_n_children(t, input, path, level, return_array, n);
  }
  
  print_viz(return_array, return_index);
  return success; 
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
  if (sups[1] == NULL){
    return 0;
  }
  return exec_general_viz(sups, 's');
}

int exec_get_children(char** sups)
{
  if (sups[1] == NULL){
    return 0;
  }
  return exec_general_viz(sups, 'c');
}

int exec_get_n_children(char** sups)
{
  if (sups[1] == NULL){
    return 0;
  }
  if (sups[2] == NULL){
    return 0;
  }
  return exec_general_viz(sups, 'n');
}

int quit(char** sups){
  sups++;
  return -2;
}

int help(char** sups){
  if (sups[1] == NULL){
      full_help();
  }
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
