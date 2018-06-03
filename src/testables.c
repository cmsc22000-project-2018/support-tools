#include "../include/testables.h"

trie_t** return_trie_list() {
  trie_t** trie_list = malloc(3*sizeof(trie_t*));
  trie_list[0] = first_trie();
  trie_list[1] = second_trie();
  trie_list[2] = third_trie();
  return trie_list;
}

trie_t* first_trie() {
  trie_t* first = trie_new('\0');
  trie_insert_string("and",first);
  trie_insert_string("would",first);
  trie_insert_string("wood",first);
  return first;
}

trie_t* second_trie() {
  trie_t* second = trie_new('\0');
  trie_insert_string("test",second);
  trie_insert_string("something",second);
  trie_insert_string("wow",second);
  trie_insert_string("tea",second);
  return second;
}
trie_t* third_trie() {
  trie_t* third = trie_new('\0');
  trie_insert_string("words",third);
  trie_insert_string("cat",third);
  trie_insert_string("catch",third);
  trie_insert_string("dog",third);
  trie_insert_string("borja",third);
  return third;
}
