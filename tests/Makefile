#adapted from Lab5

CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2 -g -I../include/
RM = rm -f
LDLIBS = -lcriterion
SRCS = main.c  viz_tests.c
OBJS = $(SRCS:.c=.o)
BIN = test-support_tools

.PHONY: all
all: ${BIN}

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o$(BIN) $(LDLIBS) 
$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@


.PHONY: clean
clean:
	-${RM} ${BIN} ${OBJS} $(SRCS:.c=.d)

