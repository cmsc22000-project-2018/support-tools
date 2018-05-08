/* is_node() Sample Algorithm
Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth */

#include <string.h>
#include <stdio.h>

// Based on https://www.geeksforgeeks.org/trie-insert-and-search/
// Takes a trie t and a str and returns true is the string is in the given trie
// and false if it is not
int is_node(trie_t* t, char* str)
{
	trie_t* search=t;
	// Create a new trie to look through without losing our original pointer

	for (int i = 0; i < strlen(str); i++)
	// For all chars in the string
	{
		int index = str[i]-'a';
		// Convert the char to an int
		if (!search->children[index])
			return 0;
		// If no such node exists return false

		search=search->children[index];
		// Continue searching through the trie
	}

	return (search!=NULL);
	// If you go all the way through the trie, return true. Else, false.
}