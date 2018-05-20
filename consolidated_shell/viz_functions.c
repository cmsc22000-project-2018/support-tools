/* Implementation of all files from viz_functions.h
 * I have replaced all the tabs with spaces
 * Consolidation by Maxine King, see header file for function sources
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "viz_functions.h"

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
    for (size_t j = 0; j < input_size; ++j) {
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
        strcat(input, return_arr[i]);
        puts(return_arr[i]);
    }

    return 1;
}

char** lviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
    if (!t->children)
        // If current node is a leaf
    {
        path[level] = '\0';
        //Set the current index of the string to terminal char
        return_arr[*return_index] = strdup(path);
        //Put the constructed string into the array of strings to be printed
        ++*return_index;
        //Increment the current index of said array
    }

    for (int i = 0; i < 255; i++)
        // For all possible children
    {
        if (t->children[i])
            // If such a child exists
        {
            path[level] = t->children[i]->current;
            // Make the current index of the string whatever char is present
            lviz(t->children[i], path, ++level, return_arr, return_index);
            // Recursively call lviz on the child node
        }
    }

    return return_arr;
    // Return the array of constructed strings
}

char** wviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
    if (t->is_word)
        // If current node is a word
    {
        path[level] = '\0';
        // Set current char of string to terminating char
        return_arr[*return_index] = strdup(path);
        // Place string in constructed array to be printed
        ++*return_index;
        // Increment index in said array
    }

    for (int i = 0; i < 255; i++)
        // For all possible characters
    {
        if (t->children[i])
        // If t has such a child
        {
            path[level] = t->children[i]->current;
            // Add it to the string
            wviz(t->children[i], path, ++level, return_arr, return_index);
            // Recursively call wviz on the current node
        }
    }

    return return_arr;
    // Return constructed array of strings
}

// Print an individual string with correct hyphens
void print_w_dashes(char* str)
{
    if (!str) return;

    int i=0;

    while (str[i+1]!='\0')
    {
        printf("%c-",str[i]);
        i++;
    }

    printf("%c",str[i]);
}

void print_viz(char** to_print, int* num_items)
{
    for (int i=0; i<(*num_items); i++)
    {
        print_w_dashes(to_print[i]);
    }
}

int is_node(trie_t* t, char* str)
{
    trie_t* search=t;
    // Create a new trie to look through without losing our original pointer

    for (int i = 0; i < strlen(str); i++)
    // For all chars in the string
    {
        int index = str[i]-'a';
        // Convert the char to an int
        if (!search->children[index])
            return 0;
        // If no such node exists return false

        search=search->children[index];
        // Continue searching through the trie
    }

    return (search!=NULL);
    // If you go all the way through the trie, return true. Else, false.
}

int eviz(trie_t* t, char* str, int level, char** return_arr, unsigned int* return_index) {

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
    if (!(has_children(t))) {
        printf("LOOKSLIKEWEMADEIT\n");
        str[level] = '\0';
        return_arr[*return_index] = strdup(str);
        ++(*return_index);
    }

    /*
     * Slightly different to Marco's part where str[level]
     * adds the current char in the node of one of its children
     * and the return_arr must add the str since it is exhaustive
     * visualization
     */
    for (int i = 0; i < 255; i++) {

        if (t->children[i]) {

            str[level] = t->children[i]->current;

            return_arr[*return_index] = strdup(str);

            eviz(t->children[i], str, ++level, return_arr, ++return_index);
        }

    }

    return 1;
}

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
    for (size_t j = 0; j < input_size; ++j) {
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
        strcat(prefix, return_arr[i]);
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
    for (size_t j = 0; j < input_size; ++j) {
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
        strcat(prefix, return_arr[i]);
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

//returns 1 if a trie has children, 0 otherwise
int has_children(trie_t* t){
  for (int i = 0; i < 256; i++){
    if ((t->children)[i])
      return 1;
  }
  return 0;
}

