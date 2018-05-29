#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/viz_functions.h"
#include "../include/testables.h"
#include "../include/trie.h"

void call_all_nodes(trie_t** tlist) {
  trie_t* t = tlist[0];
  char* path = calloc(1000,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char* prefix = NULL;
  char** return_array = malloc(10*sizeof(char*));
  print_all_nodes(t, prefix, path, level, return_array, return_index);
  print_viz(return_array, return_index);
}

void call_all_nodes_prefix(trie_t** tlist) {
  trie_t* t = tlist[0];
  char* path = calloc(1000,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char* prefix = "wo";
  char** return_array = malloc(10*sizeof(char*));
  print_all_nodes(t, prefix, path, level, return_array, return_index);
  print_viz(return_array, return_index);
}

void call_eviz(trie_t** tlist) {
  trie_t* t = tlist[0];
  char* path = calloc(100,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char** return_array = malloc(10*sizeof(char*));
  eviz(t, path, level, return_array, return_index);
  print_viz(return_array, return_index);
}



void call_wviz(trie_t** tlist) {
  trie_t* t = tlist[0];
  char* path = calloc(100,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char** return_array = malloc(10*sizeof(char*));
  wviz(t, path, level, return_array, return_index);
  print_viz(return_array, return_index);
}

void call_lviz(trie_t** tlist) {
  trie_t* t = tlist[0];
  char* path = calloc(100,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char** return_array = malloc(10*sizeof(char*));
  lviz(t, path, level, return_array, return_index);
  print_viz(return_array, return_index);
}

/*
void call_sviz(trie_t** tlist) {
  trie_t* t = tlist[0];
  char* path = calloc(100,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  char** return_array = malloc(10*sizeof(char*));
  char* input = "wo";
  sviz(t, input, path, level, return_array, return_index);
  print_viz(return_array, return_index);
}
*/

int main(){
  trie_t** tlist = return_trie_list();
  printf("\nall_nodes:\n");
  call_all_nodes(tlist);
  printf("\nall_nodes with prefix:\n");
  call_all_nodes_prefix(tlist);
  return 0; 
}

