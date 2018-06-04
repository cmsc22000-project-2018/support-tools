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
    return 1;
}

//print_n_completions tests
Test(print_n_completions, true_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_n_completions(t, "ad", "", 0, actual, len_actual, 1), 1, "error in print_only_words");

    //expected
    int len_expected = 1;
    char *expected[len_expected];
    expected[0] = "add";
 
    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
}  

Test(print_n_completions, false){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_n_completions(t, "ad", "", 0, actual, len_actual, 1), 1, "error in print_only_words");

    //expected
    int len_expected = 2;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding";
    
    //check that same char** NOT produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 0); 
}   

//print_only_leaves
Test(print_only_leaves, true_null_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_leaves(t, NULL, "", 0, actual, len_actual), 1, "error in print_only_leaves");

    //expected
    int len_expected = 4;
    char *expected[len_expected];
    expected[0] = "abstract";
    expected[1] = "adding";
    expected[2] = "and";
    expected[3] = "at";

    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
} 

Test(print_only_leaves, true_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_leaves(t, "ad", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 2;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding";
    
    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
}   

Test(print_only_leaves, false){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_leaves(t, "ad", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 3;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding";
    expected[2] = "at";
    
    //check that same char** NOT produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 0); 
}   

//print_only_words tests
Test(print_only_words, true_null_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_words(t, NULL, "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 8;
    char *expected[len_expected];
    expected[0]= "a";
    expected[1] = "ab";
    expected[2] = "abstract";
    expected[3] = "add";
    expected[4] = "adding";
    expected[5] = "an";
    expected[6] = "and";
    expected[7] = "at";

    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
} 

Test(print_only_words, true_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_words(t, "ad", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 2;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding";
    
    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
}   

Test(print_only_words, false){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_only_words(t, "ad", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 3;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding";
    expected[2] = "at";
    
    //check that same char** NOT produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 0); 
}   

//print_all_nodes
Test(print_all_nodes, true_null_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_all_nodes(t, NULL, "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 16;
    char *expected[len_expected];
    expected[0]= "a";
    expected[1] = "ab";
    expected[2] = "abs
    expected[3] = "abst";
    expected[4] = "abstr";
    expected[5] = "abstra";
    expected[6] = "abstrac";
    expected[7] = "abstract";
    expected[8] = "ad";
    exptected[9] = "add";
    expected[10] = "addi";
    expected[11] = "addin";
    expected[12] = "adding";
    expected[13] = "an";
    expected[14] = "and";
    expected[15] = "at";

    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
} 

Test(print_all_nodes, true_prefix){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_all_nodes(t, "addi", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 2;
    char *expected[len_expected];
    expected[0]= "addin";
    expected[1] = "adding";
    
    //check that same char** produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 1); 
}   

Test(print_all_nodes, false){
    trie_t *t = generate_a_trie();
    //actual
    char** actual;
    int* len_actual;
    //assert that it works
    cr_assert_eq(print_all_nodes(t, "ad", "", 0, actual, len_actual), 1, "error in print_only_words");

    //expected
    int len_expected = 3;
    char *expected[len_expected];
    expected[0]= "add";
    expected[1] = "adding";
    expected[2] = "at";
    
    //check that same char** NOT produced
    cr_assert_eq(compare_char_arr(actual, len_actual, expected, len_expected), 0); 
}  
