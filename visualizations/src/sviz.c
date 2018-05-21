/*
 * Subtree visualization, based on Trie team design document V1.0,
 * Marco Harnam Kaisth's Leaf and Word Visualization Sample Algorithm
 * and https://www.geeksforgeeks.org/trie-display-content/.
 * Created by Hongji Liu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/sviz.h"

// see sviz.h
int sviz(trie_t* t, char* input, char* str, int level, char** return_arr, int* return_index) {

    if (return_arr == NULL) {
        fprintf(stderr, "eviz: return_arr is NULL");
        return 0;
    }

    if (return_index == NULL) {
        fprintf(stderr, "eviz: return_index is NULL");
        return 0;
    }

    size_t input_size = strlen(input);

    trie_t* subtrie = t;

    /*
     * Gets to the node where the input ends
     */
    for (int j = 0; j < input_size; ++j) {
        subtrie = subtrie->children[input[j]];
    }

    /*
     * Calls eviz to add the children of the string to
     * return_arr
     */
    eviz(subtrie, str, level, return_arr, return_index);

    /*
     * Add the input string to the front of each
     * string in the return_arr since it is left off
     * in eviz
     */
    for (int i = 0; i < *return_index; ++i) {
        strncat(input, return_arr[i]);
        puts(return_arr[i]);
    }

    return 1;
}
