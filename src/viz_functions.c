/* Implementation of all files from viz_functions.h
 * I have replaced all the tabs with spaces and made return values consistent
 * Also, I added a has_children function
 * Consolidation by Maxine King, see header file for function sources
 * I have now also modified almost all the functions to fix bugs, logic errors, etc
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "viz_functions.h"

int print_all_nodes(trie_t* t, char* prefix, char path[], int level, char* return_arr[], unsigned int* return_index)
{
    /*
     * Make sure that all inputs are valid
     */
    if (t == NULL) {
        fprintf(stderr, "print_all_nodes: t is NULL");
        return 0;
    }
    if (return_arr == NULL) {
        fprintf(stderr, "print_all_nodes: return_arr is NULL");
        return 0;
    }
    if (return_index == NULL) {
        fprintf(stderr, "print_all_nodes: return_index is NULL");
        return 0;
    }

    /*
     * if the prefix isn't given to be null, run with a prefix
     */
    int run_with_prefix = (prefix == NULL) ? 0 : 1;

    /*
     * if you are running it with a prefix, get to the appropriate subtrie
     */
    if (run_with_prefix) {
       //make sure prefix is in the trie
       if (trie_search(prefix, t) == 0) {
          return 0;
       }

       /*
        * Gets to the node where the prefix ends
        */
       size_t prefix_size = strlen(prefix);
       for (size_t j = 0; j < prefix_size; ++j) {
           t = t->children[(int)prefix[j]];
       }
    }
    
    for (int i = 0; i < 255; i++) {

        if (t->children[i]) {
            path[level] = t->children[i]->current;
            memset(path+level+1, 0, 1000-level-1);
            return_arr[*return_index] = strdup(path);
            (*return_index)++;
            print_all_nodes(t->children[i], NULL, path, level+1, return_arr, return_index);
            if (!(has_children(t->children[i])))
            {
                level = 0;
            }
        }

    }
    if (run_with_prefix) {
       /*
        * Add the prefix string to the front of each
        * string in the return_arr since it is left off
        * in print_all_nodes
        */
       for (unsigned int i = 0; i < *return_index; ++i) {
           char* full_child = calloc(1,100);
           strcpy(full_child, prefix);
           strcat(full_child, return_arr[i]);
           strcpy(return_arr[i],full_child);
           free(full_child);
       }
    }

    return 1;
}

int print_only_leaves(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int* return_index)
{
    /*
     * Make sure that all inputs are valid
     */
    if (t == NULL) {
        fprintf(stderr, "print_only_leaves: t is NULL");
        return 0;
    }
    if (return_arr == NULL) {
        fprintf(stderr, "print_only_leaves: return_arr is NULL");
        return 0;
    }
    if (return_index == NULL) {
        fprintf(stderr, "print_only_leaves: return_index is NULL");
        return 0;
    }

    /*
     * if the prefix isn't given to be null, run with a prefix
     */
    int run_with_prefix = (prefix == NULL) ? 0 : 1;

    /*
     * if you are running it with a prefix, get to the appropriate subtrie
     */
    if (run_with_prefix) {
       //make sure prefix is in the trie
       if (trie_search(prefix, t) == 0) {
          return 0;
       }

       /*
        * Gets to the node where the prefix ends
        */
       size_t prefix_size = strlen(prefix);
       for (size_t j = 0; j < prefix_size; ++j) {
           t = t->children[(int)prefix[j]];
       }
    }
    if (!has_children(t))
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
            print_only_leaves(t->children[i], NULL, path, level+1, return_arr, return_index);
            // Recursively call print_only_leaves on the child node
        }
    }

    if (run_with_prefix) {
       /*
        * Add the prefix string to the front of each
        * string in the return_arr since it is left off
        * in print_only_leaves
        */
       for (unsigned int i = 0; i < *return_index; ++i) {
           char* full_child = calloc(1,100);
           strcpy(full_child, prefix);
           strcat(full_child, return_arr[i]);
           strcpy(return_arr[i],full_child);
           free(full_child);
       }
    }

    return 1;
}

int print_only_words(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int* return_index)
{
    /*
     * Make sure that all inputs are valid
     */
    if (t == NULL) {
        fprintf(stderr, "print_only_words: t is NULL");
        return 0;
    }
    if (return_arr == NULL) {
        fprintf(stderr, "print_only_words: return_arr is NULL");
        return 0;
    }
    if (return_index == NULL) {
        fprintf(stderr, "print_only_words: return_index is NULL");
        return 0;
    }

    /*
     * if the prefix isn't given to be null, run with a prefix
     */
    int run_with_prefix = (prefix == NULL) ? 0 : 1;

    /*
     * if you are running it with a prefix, get to the appropriate subtrie
     */
    if (run_with_prefix) {
       //make sure prefix is in the trie
       if (trie_search(prefix, t) == 0) {
          return 0;
       }

       /*
        * Gets to the node where the prefix ends
        */
       size_t prefix_size = strlen(prefix);
       for (size_t j = 0; j < prefix_size; ++j) {
           t = t->children[(int)prefix[j]];
       }
    }

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
            print_only_words(t->children[i], NULL, path, level+1, return_arr, return_index);
            // Recursively call print_only_words on the current node
        }
    }

    if (run_with_prefix) {
       /*
        * Add the prefix string to the front of each
        * string in the return_arr since it is left off
        * in print_all_nodes
        */
       for (unsigned int i = 0; i < *return_index; ++i) {
           char* full_child = calloc(1,100);
           strcpy(full_child, prefix);
           strcat(full_child, return_arr[i]);
           strcpy(return_arr[i],full_child);
           free(full_child);
       }
    }

    return 1;
}

int print_n_completions(trie_t* t, char* prefix, char path[], int level, char** return_arr, unsigned int n)
{
    unsigned int* return_index = malloc(sizeof(unsigned int));
    print_only_words(t, prefix, path, level, return_arr, return_index);
    if (*return_index > n) {
        char* new_arr[n];
        for (unsigned int i = 0; i < n; ++i)
        {
            new_arr[i] = return_arr[i];
        }
        return_arr = new_arr;
    }

    return 1;
}

/*
 * Print an individual string with correct hyphens
 */
void print_w_dashes(char* str)
{
    if (!str) return;

    int i = 0;

    while (str[i+1] != '\0')
    {
        printf("%c-",str[i]);
        i++;
    }

    printf("%c", str[i]);
}

void print_viz(char** to_print, unsigned int* num_items)
{
    for (unsigned int i = 0; i < (*num_items); i++)
    {
        print_w_dashes(to_print[i]);
        printf("\n");
    }
}

int is_node(trie_t* t, char* str)
{
    trie_t* search=t;
    // Create a new trie to look through without losing our original pointer

    for (size_t i = 0; i < strlen(str); i++)
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

bool has_children_prefix(trie_t *t, char *prefix)
{

    if (t == NULL)
    {
        return false;
    }

    size_t input_size = strlen(prefix);

    if (input_size == 0)
    {
        return true;
    }

    trie_t* trie = t;

    for (size_t i = 0; i < input_size; ++i)
    {
        trie = trie->children[(int)prefix[i]];
        if(trie == NULL)
        {
            return false;
        }
    }

    return true;

}

/*
 * returns 1 if a trie has children, 0 otherwise
 */
int has_children(trie_t* t)
{
    for (int i = 0; i < 256; i++)
    {
        if ((t->children)[i])
            return 1;
    }
    return 0;
}

