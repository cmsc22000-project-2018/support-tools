#include "../include/testables.h"

trie_t** return_trie_list()
{
    trie_t** trie_list = malloc(3*sizeof(trie_t*));
    trie_list[0] = first_trie();
    trie_list[1] = second_trie();
    trie_list[2] = third_trie();
    return trie_list;
}

trie_t* first_trie()
{
    trie_t* first = trie_new('\0');
    trie_insert_string(first, "and");
    trie_insert_string(first, "would");
    trie_insert_string(first, "wood");
    return first;
}

trie_t* second_trie()
{
    trie_t* second = trie_new('\0');
    trie_insert_string(second, "test");
    trie_insert_string(second, "something");
    trie_insert_string(second, "wow");
    trie_insert_string(second, "tea");
    return second;
}
trie_t* third_trie()
{
    trie_t* third = trie_new('\0');
    trie_insert_string(third, "words");
    trie_insert_string(third, "cat");
    trie_insert_string(third, "catch");
    trie_insert_string(third, "dog");
    trie_insert_string(third, "borja");
    return third;
}
