#/*
 * Visualization unit tests 
 * Created by Elizabeth Crowdus and Richard Pei
 */

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/api/include/trie.h"

//helper make trie fn
trie_t* generate_a_trie(){
    trie_t *t = trie_new("test_a");

    char* i1 = "a";
    char* i2 = "at"; 
    char* i3 = "and";

    cr_assert_eq(trie_insert(t, "a"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "at"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "and"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "add"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "adding"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "ab"), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, "abstract"), 0, "couldn't insert word into trie");

}
//print_only_words tests
Test(print_only_words, true_ex1){
    trie_t *t = trie_new("test");

    char* i1 = "a";
    char* i2 = "at"; 
    char* i3 = "and";

    cr_assert_eq(trie_insert(t, i1), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, i2), 0, "couldn't insert word into trie");
    cr_assert_eq(trie_insert(t, i3), 0, "couldn't insert word into trie");
   
/* eviz test cases */

Test(eviz, empty_trie_true){
    char** input = [""];
    trie_t *t = new_trie(input);

    int size = 0;
    char** actual = eviz(t);

    int result = compare_char_arr(actual, input, size);

    cr_assert_eq(1, result, "eviz test failed");
}

Test(eviz, one_first_letter_true){
    char** input = ["a", "an", "and", "at"];
    trie_t *t = new_trie(input);

    int size = 4;
    char** actual = eviz(t);

    int result = compare_char_arr(actual, input, size);

    cr_assert_eq(1, result, "eviz test failed");
}

Test(eviz, one_first_letter_false){
    char ** input = ['a', 'an', 'and', 'at'];
    trie_t *t = new_trie(input);

    int size = 4;
    char** actual = eviz(t);
    char** mod_input = ['a', 'an', 'and'];

    int result = compare_char_arr(actual, mod_input, size);

    cr_assert_eq(0, result, "eviz test failed");
}

/* LEAF VISUALIZATION TESTS
 * lviz()
 */

/* lviz test cases */

Test(lviz, one_first_letter_true){
    char **input = ["c", "ca", "cat", "catc", "catch"];
    trie_t *t = new_trie(input);

    int size = 1;
    char **expected = ["catch"];
    char **actual = lviz(t);

    int result = compare_char_arr(actual, expected, size);

    cr_assert_eq(1, result, "lviz test failed");
}

Test(lviz, one_first_letter_false){
    char **input = []"c", "ca", "cat", "catc", "catch"];
    trie_t *t = new_trie(input);

    int size = 1;
    char **expected = ["catc"];
    char **actual = lviz(t);

    int result = compare_char_arr(actual, expected, size);

    cr_assert_eq(0, result, "lviz test failed");
}

/* WORD VISUALIZATION TESTS
 * wviz()
 */


/* wviz test cases */

Test(wviz, one_first_letter_true){
    char **input = ["c", "ca", "cat", "catc", "catch"];

    trie_t *t = new_trie(input);

    int size = 2;
    char **expected = ["cat", "catch"];
    char **actual = lviz(t);

    int result = compare_char_arr(actual, expected, size);

    cr_assert_eq(1, result, "wviz test failed");

}

Test(wviz, one_1st_letter_false){
    char **input = ["c", "ca", "cat", "catc", "catch"];
    trie_t *t = new_trie(input);

    int size = 2;
    char **expected = ["cat", "catc"];
    char **actual = lviz(t);

    int result = compare_char_arr(actual, expected, size);

    cr_assert_eq(1, result, "wviz test failed");

}

/* SUBTREE VISUALIZATION TESTS
 * sviz()
 */

/* sviz test cases */

Test(sviz, working_trie_one_1st_letter){
    char **input = ["c", "ca", "cat", "catc", "catch"];
    trie_t *t = new_trie(input);

    int size = 3;
    char **expected = ["cat", "catc", "catch"];
    char **actual = lviz(t, "cat");

    int result = compare_char_arr(actual, expected, size);

    cr_assert_eq(0, result, "wviz test failed");

}

Test(sviz, working_trie_full_alphabet_start_letters){
    char **input = ["c", "ca", "cat", "catc", "catch"];
    trie_t *t = new_trie(input);

    int size = 3;
    char **expected = ["cat", "ca", "catch"];
    char **actual = lviz(t, "cat");

    int result = compare_char_arr(actual, expected, size);

    cr_assert_eq(0, result, "wviz test failed");

}
