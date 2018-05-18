/*
 * Get Children functions
 * Modified from Subtree Visualization
 * Created by Hongji Liu
 */

#ifndef INCLUDE_CHILDREN_H
#define INCLUDE_CHILDREN_H

#include <stdbool.h>
#include "trie.h"
#include "lviz_wviz_draft.h"

/*
 * Get Children:
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: an input string
 *  - str: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array, also the size of return_arr
 *
 * Returns:
 *  - 0 if something goes wrong, 1 if everything works
 *
 */
int get_children(trie_t* t, char* prefix, char* str, int level, char** return_arr, int* return_index);

/*
 * Get N Children:
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
int get_n_children(trie_t* t, char* prefix, char* str, int level, char** return_arr, int n);


bool has_children(trie_t *t, char *prefix);

#endif //INCLUDE_CHILDREN_H
