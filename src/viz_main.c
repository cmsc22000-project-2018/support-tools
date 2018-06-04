#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/viz_functions.h"
#include "../include/testables.h"
#include "../include/trie.h"

void call_all_nodes(trie_t** tlist, int index)
{
    trie_t* t = tlist[index];
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char* prefix = NULL;
    char** return_array = malloc(10*sizeof(char*));
    print_all_nodes(t, prefix, path, level, return_array, return_index);
    printf("first two: %s\n%s\n", return_array[0], return_array[1]);
    print_viz(return_array, return_index);
}

void call_all_nodes_prefix(trie_t** tlist, int index, char* pre)
{
    trie_t* t = tlist[index];
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char* prefix = pre;
    char** return_array = malloc(10*sizeof(char*));
    print_all_nodes(t, prefix, path, level, return_array, return_index);
    print_viz(return_array, return_index);
}

void call_only_leaves(trie_t** tlist)
{
    trie_t* t = tlist[2];
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char* prefix = NULL;
    char** return_array = malloc(10*sizeof(char*));
    print_only_leaves(t, prefix, path, level, return_array, return_index);
    print_viz(return_array, return_index);
}

void call_only_leaves_prefix(trie_t** tlist)
{
    trie_t* t = tlist[2];
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char* prefix = "ca";
    char** return_array = malloc(10*sizeof(char*));
    print_only_leaves(t, prefix, path, level, return_array, return_index);
    print_viz(return_array, return_index);
}

void call_only_words(trie_t** tlist)
{
    trie_t* t = tlist[2];
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char* prefix = NULL;
    char** return_array = malloc(10*sizeof(char*));
    print_only_words(t, prefix, path, level, return_array, return_index);
    print_viz(return_array, return_index);
}

void call_only_words_prefix(trie_t** tlist)
{
    trie_t* t = tlist[2];
    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char* prefix = "ca";
    char** return_array = malloc(10*sizeof(char*));
    print_only_words(t, prefix, path, level, return_array, return_index);
    print_viz(return_array, return_index);
}


void call_n_completions(trie_t** tlist)
{
    trie_t* t = tlist[2];
    char* path = calloc(1000,1);
    int level = 0;
    char* prefix = "ca";
    unsigned int n = 1;
    char** return_array = malloc(10*sizeof(char*));
    print_n_completions(t, prefix, path, level, return_array, n);
    print_viz(return_array, &n);
}




/*
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
*/

int main()
{
    trie_t** tlist = return_trie_list();
    printf("\nall_nodes 0:\n");
    call_all_nodes(tlist,0);
    printf("\nall_nodes 1:\n");
    call_all_nodes(tlist,1);
    printf("\nall_nodes 2:\n");
    call_all_nodes(tlist,2);
    printf("\nall_nodes with prefix, 0:\n");
    call_all_nodes_prefix(tlist, 0, "wo");
    printf("\nall_nodes with prefix, 1:\n");
    call_all_nodes_prefix(tlist, 1, "so");
    printf("\nall_nodes with prefix, 2:\n");
    call_all_nodes_prefix(tlist, 2, "ca");
    printf("\nonly_leaves:\n");
    call_only_leaves(tlist);
    printf("\nonly_leaves with prefix:\n");
    call_only_leaves_prefix(tlist);
    printf("\nonly_words:\n");
    call_only_words(tlist);
    printf("\nonly_words with prefix:\n");
    call_only_words_prefix(tlist);
    printf("\nn_completions:\n");
    call_n_completions(tlist);
    return 0;
}

