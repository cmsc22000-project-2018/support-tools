.PHONY: all, clean
CC = gcc
CLFAGS = -Wall -Wextra -g
SRC = main.c
OBJ = main
INCL = -lreadline

reset: clean all

all: sample
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) $(INCL)
sample:
	$(CC) $(CFLAGS) -o sample extension.c

clean:
	rm $(OBJ) sample
