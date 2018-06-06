/* A etrie data structure */
	

	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>
	#include <math.h>
	#include "../include/etrie.h"
	#include "utils.h"
	#include <stdbool.h>
	

	/* See etrie.h */
	etrie_t *etrie_new(char current)
	{
	    etrie_t *t = calloc(1, sizeof(etrie_t));
	    
	    if (t == NULL) {
	        error("Could not allocate memory for etrie_t");
	        return NULL;
	    } 
	

	    t->current = current;
	

	    t->children = calloc(256, sizeof(etrie_t*));
	    if (t->children == NULL) {
	        error("Could not allocate memory for t->children");
	        return NULL;
	    }
	

	    t->is_word = 0;
	    t->parent = NULL;
	    t->charlist = calloc(256, sizeof(char));
	

	    return t;
	}
	

	int etrie_free(etrie_t *t)
	{
	    assert(t != NULL);
	

	    for (int i = 0; i < 256; i++) {
	        if (t->children[i] != NULL)
	            etrie_free(t->children[i]);
	    }
	    free(t->charlist);
	    free(t);
	

	    return EXIT_SUCCESS;
	}
	

	int etrie_add_node(etrie_t *t, char current)
	{
	    assert(t != NULL);
	

	    unsigned int c = (unsigned)current;
	

	    if (t->children[c] == NULL)
	        t->children[c] = etrie_new(current);
	

	    return EXIT_SUCCESS;  
	}
	

	int etrie_insert_string(etrie_t *t, char *word)
	{
	    assert(t != NULL);
	

	    if (*word == '\0') {
	        t->is_word = 1;
	        return EXIT_SUCCESS;
	

	    } else {
	        int len = strlen(word);
	        int index;
	

	        /* 
	           For loop that goes through the string
	           and adds all the unique characters to the
	           etrie's wordlist field
	         */
	        for (int i = 0; i < len; i++) {
	            index = (int)word[i];
	            t->charlist[index] = word[i];
	        }
	

	        char curr = word[0];
	        index = (int)curr;
	

	        int rc = etrie_add_node(t, curr);
	        if (rc != 0) {
	            error("Fail to add_node");
	            return EXIT_FAILURE;
	        }
	        
	        word++;
	        return etrie_insert_string(t->children[index],word);
	    }
	}
	

	bool etrie_char_exists(etrie_t *t, char c) 
	{
	    assert(t != NULL);
	    assert(t->charlist != NULL);
	

	    int index = (int)c;
	

	    return (t->charlist[index] != '\0');
	}
	

	etrie_t *etrie_get_subetrie(etrie_t *t, char* word)
	{
	    int len;
	    etrie_t* curr;
	    etrie_t** next;
	

	    len = strlen(word);
	    curr = t;
	    next = t->children;
	

	    /* 
	       Iterates through each character of the word
	       and goes to child of current etrie with index
	       of the current character casted as an int
	     */
	    for (int i = 0; i < len; i++) {
	        int j = (int)word[i];
	        curr = next[j];
	        if (curr == NULL)
	            return NULL;
	        next = next[j]->children;
	    }
	

	    return curr;
	}
	

	int etrie_search(etrie_t *t, char* word)
	{
	    etrie_t *end = etrie_get_subetrie(t, word);
	

	    if (end == NULL)
	        return NOT_IN_ETRIE;
	

	    if (end->is_word == 1) 
	        return IN_ETRIE;
	  
	    return PARTIAL_IN_ETRIE;
	}
	

	int etrie_count_completion_recursive(etrie_t *t)
	{
		int acc = 0;
	

		if (t == NULL)
			return acc;
	

		if (t->is_word == 1)
			acc++;
	

		for (int i = 0; i < 256; i++)
			acc += etrie_count_completion_recursive(t->children[i]);
	

		return acc;
	}
	

	int etrie_count_completion(etrie_t *t, char *pre)
	{
		etrie_t *end = etrie_get_subetrie(t, pre);
	

		if (end == NULL)
			return 0;
	

		return etrie_count_completion_recursive(end);
	}

