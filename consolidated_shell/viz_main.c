#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viz_functions.h"
#include "testables.h"
#include "trie.h"

int main(){
  trie_t** tlist = return_trie_list();
  trie_t* t = tlist[0];
  char* path = malloc(100);
  int level = 0;
  unsigned int return_index = 0;
  char** return_array = malloc(10*sizeof(char*));
  eviz(t, path, level, return_array, &return_index);
  printf("return index is %d\n",return_index);
  printf("testing2\n");
/*
  print_viz(return_array, return_index);
*/
  return 0; 
}

