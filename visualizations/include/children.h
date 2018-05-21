/*
 * Children functions
 * Modified from Subtree Visualization
 * Created by Hongji Liu
 */

#ifndef INCLUDE_CHILDREN_H
#define INCLUDE_CHILDREN_H

#include <stdbool.h>
#include "trie.h"
#include "lviz_wviz_draft.h"

/*
 * Get all the children from a trie
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: an input string
 *
 * Returns:
 *  - an array of string that contains the children
 *
 */
char** get_children(trie_t* t, char* prefix);

/*
 * Get n number of children from a trie
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - prefix: an input string
 *  - n: number of children wanted
 *
 * Returns:
 *  - an array of string that contains the children
 *
 */
char** get_n_children(trie_t* t, char* prefix, int n);

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
bool has_children(trie_t *t, char *prefix);

#endif //INCLUDE_CHILDREN_H
