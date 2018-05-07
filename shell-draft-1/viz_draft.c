/* Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth
Edited by Richard Pei */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tries.h"
#include "viz_draft.h"

// See viz_draft.h
char** eviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
    printf("Trie: %s. This is where the exhaustive visualization would be calculated.\n",
            t -> str);
    char** to_return = malloc(sizeof(char*));
    to_return[0] = strdup("This is where the visualization is printed");
    return to_return;
}

// Leaf visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** lviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
  printf("Trie: %s. This is where the leaf visualization would be calcuated.\n", t -> str);
  char** to_return = malloc(sizeof(char*));
  to_return[0] = strdup("This is where the visualization is printed");
  return to_return;
}

// Word visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** wviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
  printf("Trie: %s. This is where the word visualization would be calcuated.\n", t -> str);
  char** to_return = malloc(sizeof(char*));
  to_return[0] = strdup("This is where the visualization is printed");
  return to_return;
}

// See viz_draft.h
char** sviz(trie_t* t, char input[], char path[], int level, char** return_arr, int* return_index)
{
    printf("Trie: %s. This is where the subtree visualization would be calculated.\n",
            t -> str);
    char** to_return = malloc(sizeof(char*));
    to_return[0] = strdup("This is where the visualization is printed");
    return to_return;
}

// Print viz
void print_viz(char** to_print, int* num_items)
{
  printf("%s\n", to_print[0]);
}
