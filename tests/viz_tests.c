#/*
 * Visualization unit tests 
 * Created by Elizabeth Crowdus and Richard Pei
 *
 * Uses API team's functions
 */

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/api/include/trie.h"

//helper make trie of words starting w 'a' fn
trie_t* generate_a_trie(){
    trie_t *t = trie_new("test_a");

    cr_assert_eq(trie_insert(t, "a"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "at"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "an"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "and"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "add"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "adding"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "ab"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "abstract"), 0, "couldn't insert word into trie");
}

//helper fn to compare char**
//returns 1 if arrays are equal
//returns 0 if arrays not equal
int compare_char_arr(char** actual, int len_actual, char** expected, int len_expected){
    //make sure lengths equal
    if(len_actual != len_expected){
        return 0;
    }
    //compare array contents
    else{
        //loop through arrays
        int i;
        for(i = 0; i < len_actual; i++){
            //if words not the same
            if(strcmp(actual[i], expected[i]) != 0){
                return 0;
            }
        }
    }
}

//print_only_words tests
Test(print_only_words, true_null_prefix){
    trie_t *t = generate_a_trie;
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_words(t, NULL, "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 8;
    char *expected[len_expected];
    expected[0]= "a";
    expected[1] = "at";
    expected[2] = "an";
    expected[3] = "and";
    expected[4] = "add";
    expected [5] = "adding";
    expected [6] = "ab";
    expected [7] = "abstract";

    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
} 

Test(print_only_words, true_prefix){
    trie_t *t = generate_a_trie;
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_words(t, "ad", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 2;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding"
    
    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
}   

