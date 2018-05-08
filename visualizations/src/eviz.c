/*
 * Exhaustive visualization, based on Trie team design document V1.0,
 * Marco Harnam Kaisth's Leaf and Word Visualization Sample Algorithm
 * and https://www.geeksforgeeks.org/trie-display-content/.
 * Created by Hongji Liu
 */

#include <string.h>
#include <stdio.h>
#include "../include/eviz.h"

// see eviz.h
int eviz(trie_t* t, char* str, int level, char** return_arr, int* return_index) {

    if (return_arr == NULL) {
        fprintf(stderr, "eviz: return_arr is NULL");
        return 0;
    }

    if (return_index == NULL) {
        fprintf(stderr, "eviz: return_index is NULL");
        return 0;
    }

    /*
     * Similar to Marco's part as t reaches the end of the
     * leaf, ends the str with '\0' and copies the str to
     * return_arr
     */
    if (!t->children) {

        str[level] = '\0';

        return_arr[*return_index] = strdup(str);

        ++*return_index;
    }

    /*
     * Slightly different to Marco's part where str[level]
     * adds the current char in the node of one of its children
     * and the return_arr must add the str since it is exhaustive
     * visualization
     */
    for (int i = 0; i < 255; i++) {

        if (t->children[i]) {

            str[level] = t->children[i].current;

            return_arr[*return_index] = strdup(str + '\0');

            eviz(&t->children[i], str, ++level, return_arr, ++return_index);
        }

    }

    return 1;
}