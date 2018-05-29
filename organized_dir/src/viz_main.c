#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/viz_functions.h"
#include "../include/testables.h"
#include "../include/trie.h"

int main(){
  trie_t** tlist = return_trie_list();
  printf("\neviz:\n");
  call_eviz(tlist);
  printf("\nwviz:\n");
  call_wviz(tlist);
  printf("\nlviz:\n");
  call_lviz(tlist);
  printf("\nsviz (input = 'wo'):\n");
  call_sviz(tlist);
  return 0; 
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
