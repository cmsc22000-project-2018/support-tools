/*
 * A trie data structure
 */


#ifndef INCLUDE_TRIE_H
#define INCLUDE_TRIE_H

#define ALPHABET_SIZE 256;

typedef struct trie trie_t;

struct trie {
    char current; // The first trie_t will be '/0' for any Trie.

    trie_t *children[ALPHABET_SIZE]; // ALPHABET_SIZE is 256 for all possible characters.

    int is_word; // if is_word is 1, indicates that this is the end of a word. Otherwise 0.

    trie_t *parent; // parent trie_t for traversing backwards
};

trie_t* new_trie_t();

trie_t* add_node(char current, trie_t *t);

int insert_string(char *word, trie_t *t);

int delete_string(char *word, trie_t *t);

int trie_search(char *word, trie_t *t);

int trie_free(trie_t *t);

#endif /* INCLUDE_TRIE_H */