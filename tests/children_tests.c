/*
 * Get Children function unit tests
 * Created by Elizabeth Crowdus
 */

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "../include/children.h"

//helper fn to 
//adapted from a function i wrote for the viz_tests last sprint
//https://github.com/cmsc22000-project-2018/support-tools/blob/master/tests/viz_tests.c

/* compare_char_arr
 * parameters: actual and expected char arrys, int of array size
 * compares char**
 * returns 0 if not identical
 * returns 1 if identical
 */
//helper function for both children tests
int compare_char_arr(char** actual, char** expected, int size){
    int i, j;

    //loop through trie
    for(i = 0; i < size; i++){
        if(actual[i] == NULL || expected[i] == NULL){
            return 0;
        }
        if(strcmp(actual[i], expected[i]) == 0)
            return 0;
        }
    }
    return 1; 
}


//get_children tests
Test(get_children, true_ex1){
    char** input = ["a", "an", "and", "at"];
    trie_t *t = trie_new(input);
    char* empty_str = ""; 
    char** return_arr = [""]; 
    char** output = ["an", "and", "at"];
    int size = 3;

    char** actual = get_children(t, 'a', empty_str, 1, return_arr, 4);
    cr_assert_eq(compare_char_arr(output, return_arr, size), 1, "test failed. children char**'s don't match");
}

Test(get_children, true_ex2){
    char** input = ["c", "ca", "cat", "catch", "catty", "catfish"];
    trie_t *t = trie_new(input);
    char* empty_str = ""; 
    char** return_arr = [""]; 
    
    int size = 5;
    char** output = ["ca", "cat", "catch", "catty", "catfish"];
    int actual = get_children(t, 'c', empty_str, 1, return_arr, return_index);

    cr_assert_eq(compare_char_arr(output, return_arr, size), 1, "test failed. children char**'s don't match");
}
Test(get_children, false_ex1){
    char** input = ["b", "ba", "bat", "batch", "batty"];
    trie_t *t = trie_new(input);
    char* empty_str = ""; 
    char** return_arr = [""]; 
    
    int size = 4;
    int actual = get_children(t, 'c', empty_str, 1, return_arr, 5);
    cr_assert_eq(0, actual, "test failed.");
}

//get_n_children tests
Test(get_n_children, true_ex1){
    char** input = ["a", "an", "and", "at"];
    trie_t *t = trie_new(input);
    char** return_arr = [""]; 
    char** output = ["an", "and", "at"];
    int size = 3;

    int actual = get_n_children(t, 'a', 1, return_arr, 4);
    cr_assert_eq(compare_char_arr(output, return_arr, size), 1, "test failed. children char**'s don't match");
}

Test(get_n_children, true_ex2){
    char** input = ["c", "ca", "cat", "catch", "catty", "catfish"];
    trie_t *t = trie_new(input);
    char* empty_str = "";
    char** return_arr = [""]; 
    char** output = ["ca", "cat", "catch", "catty", "catfish"];
    
    int size = 4;
    int actual = get_n_children(t, 'c', empty_str, 1, return_arr, return_index);

    //determine if output = actual
    int actual = get_children(t, 'c', empty_str, 1, return_arr, 5);
    cr_assert_eq(compare_char_arr(actual, return_arr, size), 1, "test failed. children char**'s don't match");
}
Test(get_n_children, false_ex1){
    char** input = ["b", "ba", "bat", "batch", "batty"];
    trie_t *t = trie_new(input);
    char* empty_str = ""; 
    char** return_arr = [""]; 
    
    int size = 4;
    int actual = get_children(t, 'c', empty_str, 1, return_arr, 5);
    cr_assert_eq(0, actual, "test failed.");
}



