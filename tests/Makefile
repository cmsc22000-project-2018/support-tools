CC = gcc
CFLAGS = -Wall -g -Wextra -std=c99 -D_GNU_SOURCE
SRC = ../src/viz_functions.c trie.c vtests.c
OBJ = tests

all: tests
tests:
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

clean:
	rm $(OBJ)

