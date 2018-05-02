
// Constructs a new trie tracing from node n to the head of trie t
trie_t* trace(trie_t* t, node_t* n);

// Prints all leaves in a given trie
void lviz(trie_t* t)

// Prints a singleton trie where all nodes are in the 0 index of their parents
// children array in the trie struct
void print_singleton_trie(trie_t* t)

