/*
 * Exhaustive visualization, based on Trie team design document V1.0,
 * Marco Harnam Kaisth's Leaf and Word Visualization Sample Algorithm
 * and https://www.geeksforgeeks.org/trie-display-content/.
 * Created by Hongji Liu
 */

#ifndef INCLUDE_EVIZ_H
#define INCLUDE_EVIZ_H

#include "trie.h"

/*
 * Exhaustive Visualization:
 *
 * Parameters:
 *  - t: a trie pointer pointed to the head of the tree
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
int eviz(trie_t* t, char* str, int level, char** return_arr, int* return_index);

#endif //INCLUDE_EVIZ_H
