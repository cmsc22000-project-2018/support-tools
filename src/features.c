#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/features.h"
#include "../include/testables.h"
#include "../include/viz_functions.h"

/* Setup to allow for handler array */
typedef int (*command_function)(char** sups);


struct command
{
    char* command;
    command_function func;
};

/* Array containing existing commands and their relevant functions */
struct command features[] =
{
    {"print", tprint},
    {"insert", tinsert},
    {"new", tnew},
    {"help", help},
    {"quit", quit},
    {"q", quit},
};


/* Number of features */
int num_features = sizeof(features) / sizeof(struct command);



int exec(char* arg, char* sups[])
{
    for (int i = 0; i < num_features; i++)
    {
        if (strcmp(features[i].command, arg) == 0)
        {
            return features[i].func(sups);
        }
    }
    return 0;
}

int tnew(char** sups)
{
    char* trie_key = sups[0];
    char* to_add = sups[1];
    printf("key is %s\n",trie_key);
    printf("to_add is %s\n",to_add);
    if (trie_key == NULL)
    {
        printf("trie key was null\n");
        return 0;
    }
    trie_t* t = trie_new(trie_key);
    trie_insert(t,to_add);
    printf("trie is at location %x\n",t);
    int success = t ? 1 : 0;
    return success;
}


int tinsert(char** sups)
{
/*
    trie_t* t = get_trie(sups[0]);
    if (t == NULL)
    {
        return 0;
    }
    char* to_add = sups[1];
    if (to_add == NULL)
    {
        return 0;
    }
    int success = trie_insert(t, to_add);
    return success;
*/
    return 1;
}
    


int tprint(char** sups)
{
    etrie_t* t = get_etrie(sups[0]);
    if (t == NULL)
    {
	printf("t was null\n");
        return 0;
    }

    char* path = calloc(1000,1);
    int level = 0;
    unsigned int* return_index = malloc(sizeof(unsigned int));
    (*return_index) = 0;
    char** return_array = malloc(1000*sizeof(char*));

    int success;

    if (sups[1] == NULL)
    {
        success = print_all_nodes(t, sups[2], path, level, return_array, return_index);
    }
    else if (!strcmp(sups[1],"all-nodes"))
    {
        success = print_all_nodes(t, sups[2], path, level, return_array, return_index);
    }
    else if (!strcmp(sups[1],"all-nodes"))
    {
        success = print_all_nodes(t, sups[2], path, level, return_array, return_index);
    }
    else if (!strcmp(sups[1],"only-leaves"))
    {
        success = print_only_leaves(t, sups[2], path, level, return_array, return_index);
    }
    else if (!strcmp(sups[1],"only-words"))
    {
        success = print_only_words(t, sups[2], path, level, return_array, return_index);
    }
    else if (!strcmp(sups[1],"n-completions"))
    {
        unsigned int n = atoi(sups[3]);
        *return_index = n;
        success = print_n_completions(t, sups[2], path, level, return_array, n);
    }
    else
    {
        return 0;
    }

    print_viz(return_array, return_index);
    return success;
}

int quit(char** sups)
{
    sups++;
    return -2;
}

int help(char** sups)
{
    int argisprint;
    if (sups[0] == NULL)
    {
        std_indent("This tool provides a set of commands to visualize a trie.\n"
                   "The function takes in a main command, print, as well as a trie to be printed.\n"
                   "More arguments can be added to specify visualization types and to see subtries.\n"
                   "Usage: print <trie> [option] [prefix]\n"
                   "Visualize tries using either all-nodes, only-words, or only-leaves OPTION.\n"
                   "If no prefix is specified, the entire trie will be visualized.\n"
                   "Example: print trie1 only-words 'ab'\n\n"
                   "Options:\n"
                   "all-nodes\t prints out all nodes of the trie\n"
                   "only-words\t only prints out valid words of the trie\n"
                   "only-leaves\t only prints out the leaves of the trie\n"
                   "n-completions\t prints out n completions of a trie\n"
                   "Note: n completions must also be used with a number:\n"
                   "print <trie> n-completions [prefix] [n]\n"
                   "Type 'help [option]' for more information on each option.\n\n"
                   "Prefix:\n"
                   "Include the prefix in a trie to print out only the subtrie under that prefix.\n");
    }
    else
    {
        argisprint = !strcmp(sups[0],"print") ? 1 : 0;
        if ((!strcmp(sups[0],"all-nodes"))||(argisprint&&(!strcmp(sups[1],"all-nodes"))))
        {
            std_indent("To see all the nodes from a trie, type:\n"
                       "'print <trie>' or 'print <trie> all-nodes' where trie is the key of the trie you're printing\n"
                       "This will show an alphabetical visualization of every node in your trie\n"
                       "For example, the trie 'trie-ex' contains the, they, and we\n"
                       "Typing 'print trie-ex all-nodes' will return:\n"
                       "t\nt-h\nt-h-e\nt-h-e-y\nw\nw-e\n"
                       "Optionally, you can use it with a prefix to view all nodes of a subtrie by typing\n"
                       "'print <trie> all-nodes [prefix]' where [prefix] is replaced by your prefix\n"
                       "For example, typing 'print trie-ex all-nodes th' will return:\n"
                       "t-h\nt-h-e\nt-h-e-y\n");
        }
        else if ((!strcmp(sups[0],"only-leaves"))||(argisprint&&(!strcmp(sups[1],"only-leaves"))))
        {
            std_indent("To see only the leaves from a trie, type:\n"
                       "'print <trie> only-leaves' where trie is the key of the trie you're printing\n"
                       "This will show an alphabetical visualization of every leaf, all the way to the end\n"
                       "For example, the trie 'trie-ex' contains the, they, and we\n"
                       "Typing 'print trie-ex only-leaves' will return:\n"
                       "t-h-e-y\nw-e\n"
                       "Optionally, you can use it with a prefix to view leaves of a subtrie by typing\n"
                       "'print <trie> only-leaves [prefix]' where [prefix] is replaced by your prefix\n"
                       "For example, typing 'print trie-ex only-leaves th' will return:\n"
                       "t-h-e-y\n");
        }
        else if ((!strcmp(sups[0],"only-words"))||(argisprint&&(!strcmp(sups[1],"only-words"))))
        {
            std_indent("To see only the words from a trie, type:\n"
                       "'print <trie> only-words' where trie is the key of the trie you're printing\n"
                       "This will show an alphabetical visualization of every word, even if it is not the end of the leaf\n"
                       "For example, the trie 'trie-ex' contains the, they, and we\n"
                       "Typing 'print trie-ex only-words' will return:\n"
                       "t-h-e\nt-h-e-y\nw-e\n"
                       "Optionally, you can use it with a prefix to view words of a subtrie by typing\n"
                       "'print <trie> only-words [prefix]' where [prefix] is replaced by your prefix\n"
                       "For example, typing 'print trie-ex only-words th' will return:\n"
                       "t-h-e\nt-h-e-y\n");
        }
        else if (!strcmp(sups[0],"n-completions"))
        {
            std_indent("To see n completions of a prefix from a given trie, type:\n"
                       "'n-completions <trie> <n>' where trie is the key of the trie you're printing, and n is the number of completions you want\n"
                       "This will show the first n words in that trie that start with that prefix\n"
                       "For example, the trie 'trie-ex' contains the, they, and we\n"
                       "Typing 'print n-completions trie-ex 2 th' will return:\n"
                       "t-h-e\nt-h-e-y\n"
                       "Typing 'print n-completions trie-ex 1 th' will return:\n"
                       "t-h-e\n");
        }
        else if (!strcmp(sups[0],"quit"))
        {
            std_indent("Typing 'quit' or 'q' allows you to exit the shell\n");
        }
        else
        {
            return 0;
        }
    }

    return 1;
}
//137 to 205

etrie_t* get_etrie(char* index_str)
{
    etrie_t** etries = return_etrie_list();
    int index = atoi(index_str);
    return etries[index];
}

void std_indent(char* string)
{
    print_indented_n(string, 2);
}

void print_indented_n(char* string, int indent)
{
    int i = 0;
    int i_n = 0;
    char* new_str = calloc(1,2*strlen(string));
    for (; i_n < indent; i_n++)
        new_str[i_n] = ' ';
    while (string[i])
    {
        if (string[i] == '\n')
        {
            new_str[i_n++] = '\n';
            for (int j = 0; j < indent; j++)
                new_str[i_n++] = ' ';
        }
        else
        {
            new_str[i_n++] = string[i];
        }
        i++;
    }
    int len = strlen(new_str);
    for (int j = len; j >= len - indent; j--)
        new_str[j] = (new_str[j] == ' ') ? '\0' : ' ';
    printf("%s",new_str);
}

