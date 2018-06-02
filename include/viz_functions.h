/* Complete header file including all visualization features created by support tools
 * Created by Maxine King based on files by Hongji Liu and Marco Harnam Kaisth
 * List of included functions and primary authors (other sources are at the bottom):
 * is_node (Marco Harnam Kaisth)
 * get_children (Hongji Liu)
 * get_n_children (Hongji Liu)
 * has_children_prefix (Hongji Liu)
 * sviz (Hongji Liu)
 * lviz (Marco Harnam Kaisth)
 * wviz (Marco Harnam Kaisth)
 * eviz (Hongji Liu)
 * print_viz(Marco Harnam Kaisth)
 */

#ifndef INCLUDE_VIS_FUNCTIONS_H
#define INCLUDE_VIS_FUNCTIONS_H

#include <stdbool.h>
#include "trie.h"


/* Is Node:
 *
 * Parameters:
 *  - t: a trie pointer to the head of the tree
 *  - str: a string to search for in the tree
 *
 * Returns:
 *  - True if the string is in the given trie, false if not
 */
int is_node(trie_t* t, char* str);

/*
 * check if a child with certain prefix exists in the trie
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: an input string
 *
 * Returns:
 *  - true if the child exists, false if doesn't
 *
 */
bool has_children_prefix(trie_t *t, char *prefix);

/* Print N Completions:
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: an input string
 *  - str: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - n: number of children required
 *
 * Returns:
 *  - 0 if something goes wrong, 1 if everything works
 *
 */
int print_n_completions(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int n);

/* Leaf visualization
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: a prefix to visualize; to print the whole tree, set prefix = NULL 
 *  - path: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array, also the size of return_arr
 *
 * Returns:
 *  - 0 if something goes wrong, 1 if everything works
 */
int print_only_leaves(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int* return_index);

/* Word visualization
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: a prefix to visualize; to print the whole tree, set prefix = NULL 
 *  - path: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array, also the size of return_arr
 *
 * Returns:
 *  - 0 if something goes wrong, 1 if everything works
 */
int print_only_words(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int* return_index);

/* Exhaustive Visualization (All Nodes):
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: a prefix to visualize; to print the whole tree, set prefix = NULL 
 *  - path: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array, also the size of return_arr
 *
 * Returns:
 *  - 0 if something goes wrong, 1 if everything works
 *
 */
int print_all_nodes(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int* return_index);

/* Print Viz:
 *
 * Parameters:
 *  - to_print: an aray of char*s to be printed
 *  - num-items: number of items to be printed
 *
 * Returns:
   - returns void, but prints to_print to stdout
 */
void print_viz(char** to_print, unsigned int* num_items);

/* Has Children:
 * Parameters:
 *  - t: a pointer to a trie node
 *
 * Returns:
 *  - 1 if a trie has children, 0 otherwise
 */
int has_children(trie_t* t);



#endif

/* Other sources:
 * Subtree Visualization (get_children, get_n_children)
 * Marco's Leaf and Word Visualizations Sample Algorithms (sviz, eviz)
 * Trie team design document V1.0 (lviz, wviz, eviz, is_node)
 * https://www.geeksforgeeks.org/trie-display-content (sviz, lviz, wviz, eviz, is_node)
 */
