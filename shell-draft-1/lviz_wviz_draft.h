/* Leaf and Word Visualization Sample Algorithm
Based on the Trie team design document V1.0
Made by Marco Harnam Kaisth */

// Leaf visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** lviz(trie_t* t, char path[], int level, char** return_arr, int* return_index);

// Word visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes doewn the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** wviz(trie_t* t, char path[], int level, char** return_arr, int* return_index);

// Print vizualization in correct format
void print_viz(char** to_print, int* num_items);

// Print with dashes
void print_w_dashes(char* str);
