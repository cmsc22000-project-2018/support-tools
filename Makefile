.PHONY: all, clean
CC = gcc
CFLAGS = -Wall -g -Wextra -std=c99 -D_GNU_SOURCE
SRC = src/features.c src/main.c src/viz_functions.c src/trie.c src/testables.c
# IMPL = viz_draft.c
OBJ = shell
VIZ_SRC = src/viz_main.c src/viz_functions.c src/trie.c src/testables.c
T_SRC = tests/vtests.c
VIZ_OBJ = viz


shell: 
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline 
viz:
	$(CC) $(CFLAGS) $(VIZ_SRC) -o $(VIZ_OBJ)

tests: shell
	$(CC) $(CFLAGS) $(T_SRC) -o tests

all: shell tests

clean:
	rm $(OBJ)

