#include "testables.h"

trie_t** return_trie_list() {
  trie_t** trie_list = malloc(2*sizeof(trie_t*));
  trie_list[0] = first_trie();
  trie_list[1] = second_trie();
  return trie_list;
}

trie_t* first_trie() {
  trie_t* first = new_trie('\0');
  insert_string("and",first);
  insert_string("would",first); 
  insert_string("wood",first); 
  add_node('q',first);
  return first;
}

trie_t* second_trie() {
  trie_t* second = new_trie('\0');
  insert_string("test",second);
  insert_string("something",second); 
  insert_string("wow",second); 
  insert_string("tea",second); 
  return second;
}
