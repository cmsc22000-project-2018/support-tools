#include <stdio.h> // printf
#include <string.h> // strlen
#include <stdlib.h> // exit
#include <unistd.h> // syscalls

// maxargs in struct cannot be a variable, use define
#define MAXARGS 128
#define MAXLENGTH 1024

char* prompt = "trie-viz> "; // command line prompt

struct command {
  int argc;               // number of args
  char* argv[MAXARGS];    // arguments list
  enum builtin_t {        // is argv[0] a builtin command?
    eviz, lviz, wviz, quit, capitalize, help, none } builtin;
};
typedef struct command command_t;

enum builtin_t parse_builtin(struct command* cmd) {
  if (!strcmp(cmd->argv[0], "eviz")) {
    return eviz;
  } else if (!strcmp(cmd->argv[0], "lviz")) {
    return lviz;
  } else if (!strcmp(cmd->argv[0], "wviz")) {
    return wviz;
  } else if (!strcmp(cmd->argv[0], "quit")) {
    return quit;
  } else if (!strcmp(cmd->argv[0], "capitalize")) {
    return capitalize;
  } else if (!strcmp(cmd->argv[0], "help")) {
    return help;
  } else {
    return none;
  }
}

void error(char* msg) {
  printf("Error: %s", msg);
  exit(0);
}

void run_system_command(command_t* cmd, int bg) {
  pid_t childPid;

  if ((childPid = fork()) < 0)
      error("fork() error");
  else if (childPid == 0) {
      if (execvp(cmd->argv[0], cmd->argv) < 0) {
        printf("%s: command not found\n", cmd->argv[0]);
        exit(0);
      }
  } else {
      if (bg)
        printf("Child in background [%d]\n", childPid);
      else
        wait(&childPid);
  }
}

void run_builtin_command(command_t* cmd, int bg) {

  switch (cmd->builtin) {

    case eviz:
      printf("b\n"
             "\n"
             "b-e\n"
             "\n"
             "b-e-t\n"
             "\n"
             "b-e-t-s\n"
             "\n"
             "b-e-t-t\n"
             "\n"
             "b-e-t-t-e\n"
             "\n"
             "b-e-t-t-e-r\n"
             "\n"
             "b-e-t-t-e-r-s\n"); break;

    case lviz:
      printf("b-e-t-t-e-r-e-d\n"
             "\n"
             "b-e-t-t-e-r-m-e-n-t\n"
             "\n"
             "b-e-t-t-e-r-s\n"); break;

    case wviz:
      printf("b-e-t\n"
             "\n"
             "b-e-t-s\n"
             "\n"
             "b-e-t-t-e-r\n"
             "\n"
             "b-e-t-t-e-r-s\n"
             "\n"
             "b-e-t-t-e-r-m-e-n-t\n"); break;

    case capitalize:
      if (cmd->argv[1] == NULL) {
        printf("please enter an lower case letter after capitalize\n");
      } else if (cmd->argv[1][0] < 97 || cmd->argv[1][0] > 122) {
        printf("please enter an lower case letter\n");
      } else {
        size_t size = strlen(cmd->argv[1]);
        for (int i = 0; i < size; i++) {
          printf("%c", cmd->argv[1][i] - 32);
        }

        printf("\n");
      } break;

    case help:
      printf("Here are the commands:");
      printf("\neviz\nlviz\nwviz\ncaptalize\nhelp\nquit\n");
      break;

    case quit: 
      printf("quitting...\n");
      exit(1);

    default: printf("%s: command not found, type 'help' to get available commands\n", cmd->argv[0]);
  }
}

int parse(const char *cmdline, command_t *cmd) {
  static char array[MAXLENGTH];        // local copy of command line
  const char delims[10] = " \t\r\n";   // argument delimiters
  char* line = array;                  // ptr that traverses command line
  char* token;                         // ptr to the end of the current arg
  char* endline;                       // ptr to the end of the cmdline string
  int is_bg;                           // background job?

  if (cmdline == NULL)
    error("command line is NULL\n");

  (void) strncpy(line, cmdline, MAXLENGTH);
  endline = line + strlen(line);

  // build argv list
  cmd->argc = 0;

  while (line < endline) {
    // skip delimiters
    line += strspn(line, delims);
    if (line >= endline) break;

    // find token delimiter
    token = line + strcspn (line, delims);

    // terminate the token
    *token = '\0';

    // record token as an argument
    cmd->argv[cmd->argc++] = line;

    // check if argv is full
    if (cmd->argc >= MAXARGS - 1) break;

    line = token + 1;
  }

  // argument list must end with a NULL pointer
  cmd->argv[cmd->argc] = NULL;

  if (cmd->argc == 0) // ignore blank line
    return 1;

  cmd->builtin = parse_builtin(cmd);

  // should job run in background
  if ((is_bg = (*cmd->argv[cmd->argc - 1] == '&')) != 0)
    cmd->argv[--cmd->argc] = NULL;

  return is_bg;
}

void eval(char* line) {
  int bg;
  command_t cmd;

  printf("Evaluating '%s'\n", line);

  // parse line into command struct
  bg = parse(line, &cmd);

  // parse error
  if (bg == -1) return;

  // empty line - ignore
  if (cmd.argv[0] == NULL) return;

  printf("Found command %s\n", cmd.argv[0]);

  if (cmd.builtin == none)
    run_system_command(&cmd, bg);
  else
    run_builtin_command(&cmd, bg);
}

int main(int argc, char* argv[]) {
  char line[MAXLENGTH]; // buffer for fgets

  printf("Welcome to the Trie-Viz shell!\n");

  while(1) {

    printf("%s", prompt);

    if ((fgets(line, MAXLENGTH, stdin) == NULL) && ferror(stdin))
      error("fgets error");

    if (feof(stdin)) { 
      printf("\n");
      exit(0);
    }

    // remove trailing line
    line[strlen(line) - 1] = '\0';

    // evaluate command line
    eval(line);
  }

  return 0;
}