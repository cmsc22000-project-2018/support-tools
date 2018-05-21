#include "trie.h"

/* When given the function and its arguments, excecutes the relevant function
 * Returns 0 if the input is "quit"
 * Returns 1 if the input is not "quit" but is valid and successfully excecuted
 * Returns -1 if something goes wrong due to bad input
 * Returns -2 if something goes wrong for internal reasons */
int exec(char* arg, char* sups[]);

/* Takes an input of supplementary arguments, uses only the first
 * Prints out an exhaustive visualization
 * Returns 1, -1, or -2 as described above */
int exec_eviz(char** sups);

/* Takes an input of supplementary arguments, uses only the first
 * Prints out a leaf visualization

 * Returns 1, -1, or -2 as described above */ 
int exec_lviz(char** sups);

/* Takes an input of supplementary arguments, uses only the first
 * Prints out a word visualization
 * Returns 1, -1, or -2 as described above */ 
int exec_wviz(char** sups);

/* Takes an input of supplementary arguments, uses the first and second
 * Prints out a subtree visualization
 * Returns 1, -1, or -2 as described above */
int exec_sviz(char** sups);

/* Returns 0, does nothing else*/
int quit(char** sups);

/* Prints help text, returns 1 always */
int help(char** sups);


/* Helper function for all visualizations 
 * Takes an input of a string that should contain only a number 
 * Converts the string to a number, accesses the trie at that index in the trie.h file
 * Returns a pointer to it */
trie_t* get_trie(char* index_str);

/*
const char* inputs = {
  "help",
  "quit",
  "eviz",
  "lviz",
  "wviz",
  "sviz",
};
 
const int functions = {
  (*help)(char**),
  (*quit)(char**),
  (*eviz)(char**),
  (*lviz)(char**),
  (*wviz)(char**),
  (*sviz)(char**),
};

const int num_features = 6;
*/

