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
  printf("sups %s,%s\n",sups[0],sups[1]);
  int argisprint = !strcmp(sups[0],"print") ? 1 : 0;
  if (sups[0] == NULL){
      printf("full_help goes here\n");
//    full_help();
  } else if ((!strcmp(sups[0],"all-nodes"))||(argisprint&&(!strcmp(sups[1],"all-nodes")))){
    printf("To see all the nodes from a trie, type:\n"
           "'print <trie>' or 'print <trie> all-nodes' where trie is the key of the trie you're printing\n"
           "This will show an alphabetical visualization of every node in your trie\n"
           "For example, the trie 'trie-ex' contains the, they, and we\n"
           "Typing 'print trie-ex all-nodes' will return:\n"
           "t\nt-h\nt-h-e\nt-h-e-y\nw\nw-e\n"
           "Optionally, you can use it with a prefix to view all nodes of a subtrie by typing\n"
           "'print <trie> all-nodes <prefix>' where <prefix> is replaced by your prefix\n"
           "For example, typing 'print trie-ex all-nodes th' will return:\n"
           "t-h\nt-h-e\nt-h-e-y\n");
  } else if ((!strcmp(sups[0],"only-leaves"))||(argisprint&&(!strcmp(sups[1],"only-leaves")))){
    printf("To see only the leaves from a trie, type:\n"
           "'print <trie> only-leaves' where trie is the key of the trie you're printing\n"
           "This will show an alphabetical visualization of every leaf, all the way to the end\n"
           "For example, the trie 'trie-ex' contains the, they, and we\n"
           "Typing 'print trie-ex only-leaves' will return:\n"
           "t-h-e-y\nw-e\n"
           "Optionally, you can use it with a prefix to view leaves of a subtrie by typing\n"
           "'print <trie> only-leaves <prefix>' where <prefix> is replaced by your prefix\n"
           "For example, typing 'print trie-ex only-leaves th' will return:\n"
           "t-h-e-y\n");
  } else if ((!strcmp(sups[0],"only-words"))||(argisprint&&(!strcmp(sups[1],"only-words")))){
    printf("To see only the words from a trie, type:\n"
           "'print <trie> only-words' where trie is the key of the trie you're printing\n"
           "This will show an alphabetical visualization of every word, even if it is not the end of the leaf\n"
           "For example, the trie 'trie-ex' contains the, they, and we\n"
           "Typing 'print trie-ex only-words' will return:\n"
           "t-h-e\nt-h-e-y\nw-e\n"
           "Optionally, you can use it with a prefix to view words of a subtrie by typing\n"
           "'print <trie> only-words <prefix>' where <prefix> is replaced by your prefix\n"
           "For example, typing 'print trie-ex only-words th' will return:\n"
           "t-h-e\nt-h-e-y\n");
  } else if (!strcmp(sups[0],"n-completions")){
    printf("To see n completions of a prefix from a given trie, type:\n"
           "'n-completions <trie> <n>' where trie is the key of the trie you're printing, and n is the number of completions you want\n"
           "This will show the first n words in that trie that start with that prefix\n"
           "For example, the trie 'trie-ex' contains the, they, and we\n"
           "Typing 'n-completions trie-ex 2 th' will return:\n"
           "t-h-e\nt-h-e-y\n"
           "Typing 'n-completions trie-ex 1 th' will return:\n"
           "t-h-e\n");
  } else if (!strcmp(sups[0],"quit")){
     printf("Typing 'quit' or 'q' allows you to exit the shell\n");
  } else {
    return 0;
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
