.PHONY: all, clean
CC = gcc
CFLAGS = -Wall -g -Wextra 
SRC = features.c main.c lviz_wviz_draft.c
IMPL = lviz_wviz_draft.c
OBJ = shell

all: implementation
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation

clean:
	rm $(OBJ)

