.PHONY: all, clean
CC = gcc
CFLAGS = -Wall -g -Wextra
SRC = features.c main.c viz_functions.c trie.c testables.c
# IMPL = viz_draft.c
OBJ = shell
VIZ_SRC = viz_main.c viz_functions.c trie.c testables.c
VIZ_OBJ = viz

all: #implementation
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline 
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation
viz:
	$(CC) $(CFLAGS) $(VIZ_SRC) -o $(VIZ_OBJ)

clean:
	rm $(OBJ)

