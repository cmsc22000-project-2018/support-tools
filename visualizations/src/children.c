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
char** get_children(trie_t* t, char* prefix) {

    if (t == NULL) {
        return NULL;
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
 *  - str: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array, also the size of return_arr
*/
    int level = 0;
    char** return_arr = malloc(500 * 500 * sizeof(char));
    int return_index = 0;
    char* str = "";

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

    return return_arr;
}

// see children.h
char** get_n_children(trie_t* t, char* prefix, int n) {

    if (t == NULL) {
        return NULL;
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
 *  - str: an empty string to fill as it goes down the trie
 *  - level: indicate the current level of the trie as well as
 *           the index of the str to fill
 *  - return_arr: a pointer to the array of strings that return
 *  - return_index: current index of the array, also the size of return_arr
 */
    int level = 0;
    char** return_arr = malloc(500 * 500 * sizeof(char));
    int return_index = 0;
    char* str = "";

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

bool has_children(trie_t *t, char *prefix) {

    if (t == NULL) {
        return false;
    }

    size_t input_size = strlen(prefix);

    if (input_size == 0) {
        return true;
    }

    trie_t* trie = t;

    for (int i = 0; i < input_size; ++i) {
        trie = trie->children[prefix[i]];
        if(trie == NULL) {
            return false;
        }
    }

    return true;

}