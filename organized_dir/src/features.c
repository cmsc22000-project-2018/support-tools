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
  int argisprint;
  if (sups[0] == NULL){
     std_indent("This tool provides a set of commands to visualize a trie.\n"
            "The function takes in a main command, print, as well as a trie to be printed.\n"
            "Additional arguments can be added in order to specify types of visualizations and to see certain subtries.\n"
            "Usage: print <trie> [option] [prefix]\n"
            "Visualize trie using either all-nodes, only-words, or only-leaves OPTION. If no prefix is specified, the entire trie will be visualized.\n"
            "Example: print trie1 only-words 'ab'\n\n"
            "Options:\n"
            "all-nodes\t prints out all nodes of the trie\n"
            "only-words\t only prints out valid words of the trie\n"
            "only-leaves\t only prints out the leaves of the trie\n"
            "Type 'help [option]' for more information on each option.\n\n"
            "Prefix:\n"
            "Include the prefix in a trie in order to print out only the subtrie under that prefix.\n");
  } else {
    argisprint = !strcmp(sups[0],"print") ? 1 : 0;
    if ((!strcmp(sups[0],"all-nodes"))||(argisprint&&(!strcmp(sups[1],"all-nodes")))){
      std_indent("To see all the nodes from a trie, type:\n"
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
      std_indent("To see only the leaves from a trie, type:\n"
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
      std_indent("To see only the words from a trie, type:\n"
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
      std_indent("To see n completions of a prefix from a given trie, type:\n"
             "'n-completions <trie> <n>' where trie is the key of the trie you're printing, and n is the number of completions you want\n"
             "This will show the first n words in that trie that start with that prefix\n"
             "For example, the trie 'trie-ex' contains the, they, and we\n"
             "Typing 'n-completions trie-ex 2 th' will return:\n"
             "t-h-e\nt-h-e-y\n"
             "Typing 'n-completions trie-ex 1 th' will return:\n"
             "t-h-e\n");
    } else if (!strcmp(sups[0],"quit")){
       std_indent("Typing 'quit' or 'q' allows you to exit the shell\n");
    } else {
      return 0;
    }
  }

  return 1;
}
//137 to 205

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

void std_indent(char* string)
{
  print_indented_n(string, 2);
}

void print_indented_n(char* string, int indent)
{
  int i = 0;
  int i_n = 0;
  char* new_str = calloc(1,2*strlen(string));
  for (; i_n < indent; i_n++)
    new_str[i_n] = ' ';
  while (string[i]){
    if (string[i] == '\n'){
      new_str[i_n++] = '\n';
      for (int j = 0; j < indent; j++)
        new_str[i_n++] = ' ';
    } else {
      new_str[i_n++] = string[i];
    }
    i++;
  }
  int len = strlen(new_str);
  for (int j = len; j >= len - indent; j--)
    new_str[j] = (new_str[j] == ' ') ? '\0' : ' ';
  printf("%s",new_str);
}

