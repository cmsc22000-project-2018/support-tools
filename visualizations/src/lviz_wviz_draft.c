/* Leaf and Word Visualization Sample Algorithm
Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth
Small modification from Hongji Liu*/

#include <string.h>
#include <stdio.h>
#include "../include/trie.h"

// Leaf visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** lviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
	if (!t->children)
		// If current node is a leaf
	{
		path[level] = '\0';
		//Set the current index of the string to terminal char
		return_arr[*return_index] = strdup(path);
		//Put the constructed string into the array of strings to be printed
		++*return_index;
		//Increment the current index of said array
	}

	for (int i = 0; i < 255; i++)
		// For all possible children
	{
		if (t->children[i])
			// If such a child exists
		{
			path[level] = t->children[i]->current;
			// Make the current index of the string whatever char is present
			lviz(t->children[i], path, ++level, return_arr, return_index);
			// Recursively call lviz on the child node
		}
	}

	return return_arr;
	// Return the array of constructed strings
}

// Word visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** wviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
	if (t->is_word)
		// If current node is a word
	{
		path[level] = '\0';
		// Set current char of string to terminating char
		return_arr[*return_index] = strdup(path);
		// Place string in constructed array to be printed
		++*return_index;
		// Increment index in said array
	}

	for (int i = 0; i < 255; i++)
		// For all possible characters
	{
		if (t->children[i])
		// If t has such a child
		{
			path[level] = t->children[i]->current;
			// Add it to the string
			wviz(t->children[i], path, ++level, return_arr, return_index);
			// Recursively call wviz on the current node
		}
	}

	return return_arr;
	// Return constructed array of strings
}

// Print viz
void print_viz(char** to_print, int* num_items)
{
	for (int i=0; i<*num_items; i++)
	{
		print_w_dashes(to_print[i]);
	}
}

// Print an individual string with correct hyphens
void print_w_dashes(char* str)
{
	if (!str) return;

	int i=0;

	while (str[i+1]!='\0')
	{
		printf("%c-",str[i]);
		i++;
	}

	printf("%c",str[i]);
}
