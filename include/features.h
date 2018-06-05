#include "../api/include/trie.h"
#include "etrie.h"

/* When given the function and its arguments, excecutes the relevant function
 * Returns -2 if the input is "quit"
 * Returns 1 if the input is not "quit" but is valid and successfully excecuted
 * Returns 0 if something goes wrong due to bad input
 * Returns -1 if something goes wrong for internal reasons */
int exec(char* arg, char* sups[]);

/* Takes an input of supplementary arguments
 * Interprets the first argument to represent the key of a trie
 * Uses the second argument to determine which visualization to call
 * Uses the third optionally as a prefix
 * Uses the fourth optionally as a number of completions
 * Returns 1, 0, or -1 as described above */
int tprint(char** sups);

/* Takes an input of supplementary arguments
 * Interprets the first argument to represent the key of a trie
 * Uses the second argument to determine which word to add
 * Returns 1, 0, or -1 as described above */
int tinsert(char** sups);

/* Takes an input of supplementary arguments
 * Interprets the first argument to represent the key of a trie
 * Returns 1, 0, or -1 as described above */
int tnew(char** sups);

/* Returns -2, does nothing else*/
int quit(char** sups);

/* Prints help text, returns 1 always */
int help(char** sups);


/* Helper function for all visualizations
 * Takes an input of a string that should contain only a number
 * Converts the string to a number, accesses the trie at that index in the trie.h file
 * Returns a pointer to it */
etrie_t* get_etrie(char* index_str);

/* Helper function to print with a standardized indentation
 * Takes an input of a string and prints with 2 spaces as an indent
 */
void std_indent(char* string);

/* Helper function to print with a given indentation
 * Takes a string and a number n, prints the string with each line indented n spaces
 */
void print_indented_n(char* string, int indent);


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

