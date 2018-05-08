

#include <string.h>
#include "../include/trie.h"

trie_t* new_trie_t();

trie_t* add_node(char current, trie_t *t);

int insert_string(char *word, trie_t *t);

int delete_string(char *word, trie_t *t);

int trie_search(char *word, trie_t *t);

int trie_free(trie_t *t);