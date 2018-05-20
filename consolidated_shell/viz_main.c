#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viz_functions.h"
#include "testables.h"
#include "trie.h"

int main(){
  trie_t** tlist = return_trie_list();
  trie_t* t = tlist[0];
  char* path = calloc(100,1);
  int level = 0;
  unsigned int* return_index = malloc(sizeof(unsigned int));
  (*return_index) = 0;
  printf("in main: return index is %d\n",*return_index);
  printf("in main: return index addr is %x\n",return_index);
  char** return_array = malloc(10*sizeof(char*));
  eviz(t, path, level, return_array, return_index);
  printf("return index is %d\n",*return_index);
  print_viz(return_array, return_index);
  printf("\n");
  return 0; 
}

