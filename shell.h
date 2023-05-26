#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/** Structures */
struct info
{
  int final_exit;
  int ln_count;
} info;

struct flags
{
  bool interactive;
}
  
/* environments variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* builtins */
int che_builtin(char **command, char *input);
void promp_user(void);
void handle_signal(int m);
char **tokenize(char *line);
char *testPath(char **path, char *command);
char *app_path(char *p, char *cmd);
int builtin_handling(char **command, char *line);
void exit_command(char **cmd, char *line);

void print_environment(void);

/* string handlers */
int strcomp(char *s1, char *s2);
int strlenght(char *s);
int str_n_cmp(char *s1, char *s2, int n);
char *str_duplicate(char *s);
char *str_locate(char *s, char c);
void execute_cmd(char *cp, char **cmd);
char *path_finding(void);

/* free input */
void free_buffers(char **buffer);

struct builtin
{
	char *env;
	char *exit;
} builtin;


#endif /* SHELL_H */

