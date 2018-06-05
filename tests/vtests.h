#include "trie.h"
trie_t* trie_setup();

int str_arrcmp(char** a1, char** a2, int len);

void gen_arr_test(char* test_name, char** given, char** expected, int len, int* passed, int* total);
void gen_error_test(char* test_name, int returned, int* passed, int* total);

void test_all_nodes_no_p(trie_t* t, int* passed, int* total);
void test_all_nodes_p(trie_t* t, int* passed, int* total);
void test_only_leaves_no_p(trie_t* t, int* passed, int* total);
void test_only_leaves_p(trie_t* t, int* passed, int* total);
void test_only_words_no_p(trie_t* t, int* passed, int* total);
void test_only_words_p(trie_t* t, int* passed, int* total);
