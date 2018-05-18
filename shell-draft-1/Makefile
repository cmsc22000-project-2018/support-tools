.PHONY: all, clean
CC = gcc
CFLAGS = -Wall -g -Wextra -std=c99
SRC = features.c main.c viz_draft.c
IMPL = viz_draft.c
OBJ = shell

all: implementation
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline 
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation

clean:
	rm $(OBJ)

