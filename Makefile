.PHONY: all, clean
CC = gcc
CFLAGS = -Wall -g -Wextra -std=c99 -D_GNU_SOURCE
SRC = src/features.c src/main.c
# IMPL = viz_draft.c
OBJ = shell

all: #implementation
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline 
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation
viz:
	$(CC) $(CFLAGS) $(VIZ_SRC) -o $(VIZ_OBJ)

clean:
	rm $(OBJ)

