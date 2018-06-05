/* A trie data structure, in explicit format, taken from the redis-tries team */

#ifndef INCLUDE_ETRIE_H_
#define INCLUDE_ETRIE_H_

#define IN_ETRIE 1
#define NOT_IN_ETRIE 0 
#define PARTIAL_IN_ETRIE (-1)

#include <stdbool.h>

typedef struct etrie_t etrie_t;
struct etrie_t {
    /* The first etrie_t will be '/0' for any Trie. */
    char current; 
    
    /* ALPHABET_SIZE is 256 for all possible characters. */
    etrie_t **children;
    
    /* 
        If is_word is 1, indicates that this is the end of a word. 
        Otherwise 0.
     */
    int is_word; 
    
    /* Parent etrie_t for traversing backwards */
    etrie_t *parent;
    
    /* Array of characters that are contained in the node and its children */
    char *charlist;
};

/*
    Creates and allocates memory for new etrie_t.
    
    Parameters:
     - current: A char for the current character
    
    Returns:
     - A pointer to the trie, or NULL if a pointer 
       cannot be allocated
*/
etrie_t *etrie_new(char current);

/*
    Free an entire trie.
    Parameters:
     - t: A trie pointer
    
    Returns:
     - Always returns 0
*/
int etrie_free(etrie_t *t);


/*
    Creates new node in etrie_t.
    Parameters:
     - t: A pointer to the trie where the node is to be added   
     - current: A char indicating the character of the node being added
    
    Returns:
     - 0 on success, 1 if an error occurs.
    Details: 
     - Set t->children[current] to be current
     - is_word for new node set to 0.
*/
int etrie_add_node(etrie_t *t, char current);

/*
    Inserts word into trie.
    Parameters:
     - t: A pointer to the given trie
     - word: A char array to be inserted into the given trie
    
    Returns:
     - 0 on success, 1 if error occurs.
    
    Details:
     - For each trie, check if entry of the next character 
       exists in the children array:
          - If so, move into that node in the array
          - If not, add a new node and move into that node in the array
     - Then move on to the next character in string
     - Set the is_word of the last node to 1
*/
int etrie_insert_string(etrie_t *t, char *word);

/*
    Checks if a char exists in a trie 
    Parameters:
     - t: A pointer to the given trie
     - c: The character we want to check
    Returns:
     - true if c exists in t
     - false if it doesn't
*/
bool trie_char_exists(etrie_t *t, char c); 

/* 
    Searches for a word/prefix in a trie 
 
    Parameters:
     - t: A pointer to the given trie
     - word: A char array in which the end pointer is desired
    Returns: 
     - pointer to the last letter in the word/prefix if word/prefix is found. 
     - NULL if word/prefix is not found.
 */
etrie_t *etrie_get_subtrie(etrie_t *t, char* word);

/* 
    Searches for word in a trie 
 
    Parameters:
     - t: A pointer to the given trie
     - word: A char array that will be searched for in the trie 
    Returns: 
     - IN_TRIE if word is found. 
     - NOT_IN_TRIE  if word is not found at all.
     - PARTIAL_IN_TRIE if word is found but end node's is_word is 0.
 */
int etrie_search(etrie_t *t, char *word);

/*
    Count the number of different possible endings of a given prefix in a trie
    
    Parameters:
     - pre: a string of the prefix converned
     - t: a trie pointer
    Returns:
     - an integer of the number of endings if the prefix exists in the trie
     - 0 if the prefix does not exist in the trie
*/
int etrie_count_completion(etrie_t *t, char *pre);

#endif
