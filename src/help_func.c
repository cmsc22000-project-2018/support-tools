#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "features.h"
#include "viz_functions.h"
#include "testables.h"

int main() {
    printf("This tool provides a set of commands to visualize a trie.\n"
            "The function takes in a main command, print, as well as a trie to be printed.\n"
            "Additional arguments can be added in order to specify types of visualizations and to see certain subtries.\n"
            "Usage: print <trie> [option] [prefix]\n"
            "Visualize trie using either all-nodes, only-words, or only-leaves OPTION. If no prefix is specified, the entire trie will be visualized.\n"
            "Example: print trie1 only-words 'ab'\n\n"
            "Options:\n"
            "all-nodes\t prints out all nodes of the trie\n"
            "only-words\t only prints out valid words of the trie\n"
            "only-leaves\t only prints out the leaves of the trie\n"
            "Type 'help --[option]' for more information on each option.\n\n"
            "Prefix:\n"
            "Include the prefix in a trie in order to print out only the subtrie under that prefix.\n");
    return 0;
}

