.PHONY: all, clean
CC = gcc
CFLAGS = -Wall -g -Wextra -std=c99
SRC = src/features.c src/main.c src/viz_functions.c ../api/lib/redis-tries/src/trie.c src/testables.c
# IMPL = viz_draft.c
OBJ = shell
VIZ_SRC = src/viz_main.c src/viz_functions.c ../api/lib/redis-tries/src/trie.c src/testables.c
VIZ_OBJ = viz

all: #implementation
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline 
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation
viz:
	$(CC) $(CFLAGS) $(VIZ_SRC) -o $(VIZ_OBJ)

clean:
	rm $(OBJ)

