#include "../lib/api/include/trie.h"

int str_arrcmp(char** a1, char** a2, int len);

int gen_arr_test(char* test_name, char** given, char** expected, int len, int* passed, int* total);

void test_all_nodes_no_p(trie_t* t, int* passed, int* total);
void test_all_nodes_p(trie_t* t, int* passed, int* total);
void test_only_leaves_no_p(trie_t* t, int* passed, int* total);
void test_only_leaves_p(trie_t* t, int* passed, int* total);
void test_only_words_no_p(trie_t* t, int* passed, int* total);
void test_only_words_p(trie_t* t, int* passed, int* total);
