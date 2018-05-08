/*
 * Subtree visualization, based on Trie team design document V1.0,
 * Marco Harnam Kaisth's Leaf and Word Visualization Sample Algorithm
 * and https://www.geeksforgeeks.org/trie-display-content/.
 * Created by Hongji Liu
 */

#ifndef INCLUDE_SVIZ_H
#define INCLUDE_SVIZ_H

#include "trie.h"
#include "eviz.h"

/*
 * Subtree Visualization:
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
 *  - input: an input string
 *  - str: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array
 *
 * Returns:
 *  - 0 if something goes wrong, 1 if everything works
 *
 */
int sviz(trie_t* t, char* input, char* str, int level, char** return_arr, int* return_index);

#endif //INCLUDE_SVIZ_H
