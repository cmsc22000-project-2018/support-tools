/* All Visualizations Sample Algorithm
Based on the Trie team design document V1.0
Used Marco Harnam Kaisth's Leaf and Word Visualization Sample Algorithm
Edited by Richard Pei */

// Exhaustive visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes down the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** eviz(trie_t* t, char path[], int level, char** return_arr, int* return_index);

// Leaf visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes down the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** lviz(trie_t* t, char path[], int level, char** return_arr, int* return_index);

// Word visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t, an empty string path to fill as it goes down the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** wviz(trie_t* t, char path[], int level, char** return_arr, int* return_index);

// Subtree visualization
// Based on https://www.geeksforgeeks.org/trie-display-content/
// Takes a trie t
// An input/parent string 
// An empty string path to fill as it goes down the trie
// An int level indicating the current level of a trie
// A pointer to the array of strings returned, and the current index of that array
char** sviz(trie_t* t, char input[], char path[], int level, char** return_arr,
            int* return_index);

// Print vizualization in correct format
void print_viz(char** to_print, int* num_items);

// Print with dashes
void print_w_dashes(char* str);
