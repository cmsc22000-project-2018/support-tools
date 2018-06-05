#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vtests.h"

int trie_setup(){
    trie_t* t = trie_new();
    trie_insert(t, "apple");
    trie_insert(t, "an");
    trie_insert(t, "and");
    trie_insert(t, "catch");
    trie_insert(t, "cat");
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
        printf("PASSED:%s\n",test_name)
        (*passed)++;
    } else {
        printf("FAILED:%s\n",test_name) 
    }
    return;
}

void test_all_nodes_no_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_all_nodes(t, NULL, path, level, return_array, return_index);

    char** expected = {"a","an","and","ap","app","appl","apple","c","ca","cat","catc","catch"};
    
    gen_arr_test("all_nodes no prefix", return_array, expected, passed, total);
    return;
}

void test_all_nodes_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_all_nodes(t, "ca", path, level, return_array, return_index);

    char** expected = {"c","ca""cat","catc","catch"};
    
    gen_arr_test("all_nodes ca prefix", return_array, expected, passed, total);
    return;
}

void test_only_leaves_no_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_only_leaves(t, NULL, path, level, return_array, return_index);

    char** expected = {"an","and","apple","cat","catch"};
    
    gen_arr_test("all_nodes no prefix", return_array, expected, passed, total);
    return;
}

void test_only_leaves_p(trie_t* t, int* passed, int* total){
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));
    print_only_leaves(t, "ca", path, level, return_array, return_index);

    char** expected = {"catch"};
    
    gen_arr_test("all_nodes ca prefix", return_array, expected, passed, total);
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
//    test_only_leaves_no_p(t, total_passed, total_tests);
//    test_only_leaves_p(t, total_passed, total_tests);
}
