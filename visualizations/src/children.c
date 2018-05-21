/*
 * Get Children functions
 * Modified from Subtree Visualization
 * Created by Hongji Liu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/children.h"

// see children.h
int get_children(trie_t* t, char* prefix, char* str, int level, char** return_arr, int* return_index) {

    if (return_arr == NULL) {
        fprintf(stderr, "eviz: return_arr is NULL");
        return 0;
    }

    if (return_index == NULL) {
        fprintf(stderr, "eviz: return_index is NULL");
        return 0;
    }

    size_t input_size = strlen(prefix);

    trie_t* subtrie = t;

    /*
     * Gets to the node where the input ends
     */
    for (int j = 0; j < input_size; ++j) {
        subtrie = subtrie->children[prefix[j]];
    }

    /*
     * Calls wviz to add the children of the string to
     * return_arr
     */
    wviz(subtrie, str, level, return_arr, return_index);

    /*
     * Add the input string to the front of each
     * string in the return_arr since it is left off
     * in wviz
     */
    for (int i = 0; i < *return_index; ++i) {
        strncat(prefix, return_arr[i]);
        puts(return_arr[i]);
    }

    return 1;
}

// see children.h
int get_n_children(trie_t* t, char* prefix, char* str, int level, char** return_arr, int n) {

    if (return_arr == NULL) {
        fprintf(stderr, "eviz: return_arr is NULL");
        return 0;
    }

    size_t input_size = strlen(prefix);

    trie_t* subtrie = t;

    /*
     * Gets to the node where the input ends
     */
    for (int j = 0; j < input_size; ++j) {
        subtrie = subtrie->children[prefix[j]];
    }

    int return_index = 0;

    /*
     * Calls wviz to add the children of the string to
     * return_arr
     */
    wviz(subtrie, str, level, return_arr, &return_index);

    /*
     * Add the input string to the front of each
     * string in the return_arr since it is left off
     * in wviz
     */
    for (int i = 0; i < return_index; ++i) {
        strncat(prefix, return_arr[i]);
        puts(return_arr[i]);
    }

    /*
     * If the size of the word array is bigger than
     * the size we need, make sure the return_array
     * pointer point to the new_arr created that copies
     * only the first nth elements of the old array
     */
    if (return_index > n) {
        char* new_arr[n];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = return_arr[i];
        }
        return_arr = new_arr;
    }

    return 1;
}