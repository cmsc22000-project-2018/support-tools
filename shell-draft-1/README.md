Information about this set of files:

~ main.c creates the shell, parses input, and then calls "exec"

~ features.c contains the exec function, and all the functions called by exec
~ features.h contains data for use in functions.c, as well as relevant function headers

Other files that this program needs in order to run:
~ tries.h, which should contain the trie struct definition, called "trie_t"
~ testables.h, which should contain an array of pointers to tries called "tries", and an integer called "num_tries" that indicates the number of tries in the array"
~ viz_draft.h, which should contain the function headers for the visualization algorithms
~ viz_draft.c, which should contain the implementations of the functions from viz_draft.h

Right now, this is implemented with a dummy tries.h file and dummy eviz, lviz, wviz, and sviz.

Also, created a dummy testables file.
