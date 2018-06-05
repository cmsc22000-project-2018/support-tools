#adapted from Lab5

CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2 -g -I../include/
LDFLAGS = -L../ -Wl,-rpath,.
RM = rm -f
BIN = test-supporttools
LDLIBS = -lcriterion

SRCS = main.c  viz_tests.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${BIN}

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o$(BIN) $(LDLIBS)

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${BIN} ${OBJS} $(SRCS:.c=.d)

