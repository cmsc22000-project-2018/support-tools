.PHONY: all, clean
CC = gcc
LIB = redisApi
CFLAGS = -Wall -g -Wextra -std=c99 -D_GNU_SOURCE
LDFLAGS = -Wl,-rpath,lib/api/
LIB = 
SRC = src/features.c src/main.c
# IMPL = viz_draft.c
OBJ = shell

all: #implementation
	$(CC) -Llib/api/ $(LDFLAGS) $(CFLAGS) $(SRC) -o $(OBJ) -lreadline -lredisApi
# implementation:
#	$(CC) $(CLFLAGS) -c $(IMPL) -o implementation
viz:
	$(CC) $(CFLAGS) $(VIZ_SRC) -o $(VIZ_OBJ)

clean:
	rm $(OBJ)

