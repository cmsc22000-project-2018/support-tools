.PHONY: all, clean
CC = gcc
<<<<<<< HEAD
CFLAGS = -Wall -g -Wextra -std=c99
SRC = features.c main.c lviz_wviz_draft.c
IMPL = lviz_wviz_draft.c
=======
CFLAGS = -Wall -g -Wextra 
SRC = features.c main.c viz_draft.c
IMPL = viz_draft.c
>>>>>>> d92e4bb53fa3a15b342259db219c176839678d5a
OBJ = shell

all: implementation
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline 
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation

clean:
	rm $(OBJ)

