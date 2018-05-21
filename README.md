# Purpose
A tool which, when given a trie, will print out a visualization of the trie for debugging purposes.

# Method
Given a dictionary stored in a trie, we will use the shell to print out representations of the trie in alphabetical order. There will be four different types of visualizations.

## Exhaustive Visualization
The first will be exhaustive and print out all possible paths
### Use Cases
Debugging the flow of a trie
### Example
***
b

b-e

b-e-t

b-e-t-s

b-e-t-t

b-e-t-t-e

b-e-t-t-e-r

b-e-t-t-e-r-s
***

## Leaf Visualization
The second visualization will print out each leaf of the trie
### Use Cases:
Debugging how extensive the words the trie contains is
### Examples:
***
b-e-t-t-e-r-e-d

b-e-t-t-e-r-m-e-n-t

b-e-t-t-e-r-s
***

## Word Visualization
The third visualization will print out every word in the trie
### Use Cases:
Debugging whether words are correctly counted as words and not strings
### Example:
***
b-e-t

b-e-t-s

b-e-t-t-e-r

b-e-t-t-e-r-s

b-e-t-t-e-r-m-e-n-t
***

## Subtree Visualization
The fourth visualization will take a string (not necessarily a word) and print all of its children
### Use Cases:
Debugging spelling or whether a specific word has been misspelled.
### Examples:
***
input:

b-e-t-t


output:

b-e-t-t

b-e-t-t-e

b-e-t-t-e-r

b-e-t-t-e-r-m

b-e-t-t-e-r-m-e

b-e-t-t-e-r-m-e-n

b-e-t-t-e-r-m-e-n-t

b-e-t-t-e-r-s
***

# Shell Functionality

_API (These simply call the API for their functionality, and are written by their respective teams):_

+ trie_t* new_trie();
+ void import_trie(trie_t*);
+ void add_node(trie_t*);
+ void remove_node(trie_t*, node_t*);
+ void print_eviz(char**);
+ void print_lviz(char**);
+ void print_wviz(char**);
+ void print_sviz(char**);

Note: the print_viz functions will call the viz functions so that the user only has to call the print_viz functions. We will seperate the viz functions and include them in the .h file for testing purposes.

_Functions written from scratch:_
+ char** eviz(trie_t*, char path[], int level, char** return_arr, int* return_index);
+ char** lviz(trie_t*, char path[], int level, char** return_arr, int* return_index);
+ char** wviz(trie_t*, char path[], int level, char** return_arr, int* return_index);
+ char** sviz(trie_t*, char input[], char path[], int level, char** return_arr, int* return_index);
+ trie_t* trace(trie_t*, node_t*);
+ trie_t* isolate_subtree(trie_t*, node_t*);

**Elaborations:**

_eviz_ - Exhaustive visualization as described above.

_lviz_ - Leaf visualization as above.

_wviz_ - Word visualization as above.

_sviz_ - Subtree visualization as above.

_trace_ - This function takes a node and traces the path from that node to the head of the tree. It then produces this as a trie. For example, from the above tree and the node of the terminal "e" in "thee" it produces the full path from the head of the tree to that "e" as a seperate tree.

_isolate_subtree_ - This will take a trie and a node and output a pointer to a subtree with the given node as its head and all child entries as in the original tree.

## Interface

To enter the shell, the user will input:

    ./trie-viz [file]

From there they will see

    Welcome to the Trie-Viz shell!
Please either load in a trie or create a new one.


Here, they will be able to use the commands:

+ h - to view all commands possible
+ new - to create a new trie
+ import [file] - to import a trie
+ print_eviz - exhaustive visualization
+ print_lviz - leaf visualization
+ print_wviz - word visualization
+ print_sviz [node] - sub tree visualization
+ add [node] - add a node to the given tree
+ remove [node] - removes node from given tree
