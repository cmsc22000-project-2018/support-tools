/* Leaf and Word Visualization Sample Algorithm
Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth */

// Leaf visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** lviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
	if (!t->children)
	{
		path[level] = '\0';
		return_arr[return_index] = strdup(path); 
	}

	for (int i = 0; i < 255; i++)
	{
		if (t->children[i])
		{
			path[level]=i+'a';
			lviz(root->children[i], path, ++level);
		}
	}

	return return_arr;
}

// Word visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** wviz(trie_t* t, char path[], int level, char** return_arr, int* return_index)
{
	if (t->is_word)
	{
		path[level] = '\0';
		return_arr[return_index] = strdup(path); 
	}

	for (int i = 0; i < 255; i++)
	{
		if (t->children[i])
		{
			path[level]=i+'a';
			wviz(root->children[i], path, ++level);
		}
	}

	return return_arr;
}

// Print viz
void print_viz(char** to-print, int* num_items)
{
	for (int i=0; i<*num_items; i++)
	{
		print_w_dashes(to-print[i]);
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