/* Leaf Visualization Sample Algorithm
Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth */

trie_t* trace(trie_t* t, node_t* n)
{
	trie_t* new=malloc(sizeof(trie_t*));
	// Create a new malloc'd trie

	while (n->parent)
	// While n has a parent
	{
		add_node(n->current, new);
		// Add n to the new return trie
		n=n->parent;
		// Set n to n's parent
	}

	return new;
	// Return the new trie
}

void print_singleton_trie(trie_t* t)
{
	if (!t) return;

	while (t->children[0])
	//While t has a child
	{
		printf("%c-",t->current);
		//Print the currnet char
		t=t->children[0];
		//Switch t to its child
	}
	printf("%c",t->current);
	//Print the last character, from the leaf node
}

void lviz(trie_t* t)
{
	char* path=malloc(sizeof(char*));

	if (t->children)
	// if the current node of the trie has children
	{
		for(int i=0; i<255; i++)
		{
			lviz(t->children[i])
			// Recursively run lviz on each child
		}
	}

	else
	{
		print_singleton_trie(trace(t));
		// Print the traced tree from the given childless leaf
	}
}

