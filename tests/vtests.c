#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vtests.h"
#include "../include/viz_functions.h"

trie_t* trie_setup(){
    trie_t* t = trie_new('\0');
    trie_insert_string(t, "apple");
    trie_insert_string(t, "an");
    trie_insert_string(t, "and");
    trie_insert_string(t, "catch");
    trie_insert_string(t, "cat");
    return t;
}

int str_arrcmp(char** a1, char** a2, int len)
{ 
    for (int i = 0; i < len; i++){
        if (strcmp(a1[i],a2[i]))
            return 1;        
    }
    return 0;
}

void gen_arr_test(char* test_name, char** given, char** expected, int len, int* passed, int* total)
{
    (*total)++;
    if (!str_arrcmp(given, expected, len)){
        printf("PASSED:\t%s\n",test_name);
        (*passed)++;
    } else {
        printf("FAILED:\t%s\n",test_name);
    }
    return;
}

void gen_error_test(char* test_name, int returned, int* passed, int* total){
    (*total)++;
    if (returned == 0) {
        printf("PASSED:\t%s\n",test_name);
        (*passed)++;
    } else {
        printf("FAILED:\t%s\n",test_name);
    }
}

void test_all_nodes_no_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_all_nodes(t, NULL, path, level, return_array, return_index);

    char* expected[] = {"a","an","and","ap","app","appl","apple","c","ca","cat","catc","catch"};
    
    gen_arr_test("all_nodes no prefix", return_array, expected, (*return_index), passed, total);
    return;
}

void test_all_nodes_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_all_nodes(t, "ca", path, level, return_array, return_index);

    char* expected[] = {"cat","catc","catch"};
    
    gen_arr_test("all_nodes ca prefix", return_array, expected, (*return_index), passed, total);
    return;
}

void test_only_leaves_no_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_only_leaves(t, NULL, path, level, return_array, return_index);

    char* expected[] = {"and","apple","catch"};
    
    gen_arr_test("only_leaves no prefix", return_array, expected, (*return_index), passed, total);
    return;
}

void test_only_leaves_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_only_leaves(t, "ca", path, level, return_array, return_index);

    char* expected[] = {"catch"};
    
    gen_arr_test("only_leaves ca prefix", return_array, expected, (*return_index), passed, total);
    return;
}

void test_only_words_no_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_only_words(t, NULL, path, level, return_array, return_index);

    char* expected[] = {"an","and","apple","cat","catch"};
    
    gen_arr_test("only_words no prefix", return_array, expected, (*return_index), passed, total);
    return;
}

void test_only_words_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_only_words(t, "ca", path, level, return_array, return_index);

    char* expected[] = {"cat","catch"};
    
    gen_arr_test("only_words ca prefix", return_array, expected, (*return_index), passed, total);
    return;
}



int main() {
    int* total_tests = malloc(sizeof(int));
    int* total_passed = malloc(sizeof(int));
    (*total_tests) = 0;
    (*total_passed) = 0;
    trie_t* t = trie_setup();
    test_all_nodes_no_p(t, total_passed, total_tests);
    test_all_nodes_p(t, total_passed, total_tests);
    test_only_leaves_no_p(t, total_passed, total_tests);
    test_only_leaves_p(t, total_passed, total_tests);
    test_only_words_no_p(t, total_passed, total_tests);
    test_only_words_p(t, total_passed, total_tests);

    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    int an_t = print_all_nodes(NULL, NULL, path, level, return_array, return_index);
    int an_a = print_all_nodes(t, NULL, path, level, NULL, return_index);
    int an_i = print_all_nodes(t, NULL, path, level, return_array, NULL);
    int ol_t = print_only_leaves(NULL, NULL, path, level, return_array, return_index);
    int ol_a = print_only_leaves(t, NULL, path, level, NULL, return_index);
    int ol_i = print_only_leaves(t, NULL, path, level, return_array, NULL);
    int ow_t = print_only_words(NULL, NULL, path, level, return_array, return_index);
    int ow_a = print_only_words(t, NULL, path, level, NULL, return_index);
    int ow_i = print_only_words(t, NULL, path, level, return_array, NULL);

    gen_error_test("all nodes t NULL", an_t, total_passed, total_tests);
    gen_error_test("all nodes array NULL", an_a, total_passed, total_tests);
    gen_error_test("all nodes index NULL", an_i, total_passed, total_tests);
    gen_error_test("only leaves t NULL", ol_t, total_passed, total_tests);
    gen_error_test("only leaves array NULL", ol_a, total_passed, total_tests);
    gen_error_test("only leaves index NULL", ol_i, total_passed, total_tests);
    gen_error_test("only words t NULL", ow_t, total_passed, total_tests);
    gen_error_test("only words array NULL", ow_a, total_passed, total_tests);
    gen_error_test("only words index NULL", ow_i, total_passed, total_tests);

    printf("%d tests passed out of %d\n", *total_passed, *total_tests);
}
