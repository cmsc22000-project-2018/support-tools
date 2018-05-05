/* is_node() Sample Algorithm
Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth */

// Based on https://www.geeksforgeeks.org/trie-insert-and-search/
// Takes a trie t and a str and returns true is the string is in the given trie
// and false if it is not
int is_node(trie_t* t, char* str)
{
	trie_t* search=t;

	for (int i = 0; i < strlen(str); i++)
	{
		int index = str[i]-'a';
		if (!search->children[index])
			return 0;

		search=search->children[index];
	}

	return (search!=NULL);
}