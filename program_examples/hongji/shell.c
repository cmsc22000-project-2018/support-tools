#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    char *input;
    pid_t child_pid;
    int stat_loc;

    while (1) {
        input = readline("program> ");

        if (strcmp(input, "quit") == 0)
            return 0;

        child_pid = fork();
        if (child_pid == 0) {
            if (strcmp(input, "a") == 0) {
                printf("A\n");
            } else if (strcmp(input, "b") == 0) {
                printf("B\n");
            } else if (strcmp(input, "c") == 0) {
                printf("C\n");
            } else if (strcmp(input, "ls") == 0) {
                execvp("ls", argv);
            } else if (strcmp(input, "pwd") == 0) {
                execvp("pwd", argv);
            } else if (strcmp(input, "quit") == 0) {
                execvp("exit", argv);
            } else
                printf("Error: command not found.\n");
        } else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
    }

    return 0;
}