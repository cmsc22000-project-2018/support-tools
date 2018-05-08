#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"

int main(int argc, char *argv[]) {
  char *cmd;
  char line[MAX_LENGTH];

  while (1) {
    char cwd[1024];
    if (getcwd(cwd,sizeof(cwd)) != NULL)
        printf("\nin %s\n$ ", cwd);
    else
        perror("getcwd() error");
    if (!fgets(line, MAX_LENGTH, stdin)) break;

    // Parse and execute command
    if ((cmd = strtok(line, DELIMS))) {
      // Clear errors
      errno = 0;

      if (strcmp(cmd, "cd") == 0) {
        char *arg = strtok(0, DELIMS);

        if (!arg) fprintf(stderr, "cd missing argument.\n");
        else chdir(arg);

      } else if (strcmp(cmd, "help") == 0) {
          printf("Richard Pei's somewhat more advanced shell\n");
          printf("Current directory is displayed above the command line\n");
          printf("You can use the following functions:\n");
          printf("\ncd\nhelp\nexit\n");
   
      } else if (strcmp(cmd, "exit") == 0) {
          break;

      } else system(line);

      if (errno) perror("Command failed");
    }
  }

  return 0;
}
