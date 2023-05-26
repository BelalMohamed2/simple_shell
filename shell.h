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

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int che_builtin(char **cmd, char *buf);
void promp_user(void);
void handle_signal(int m);
char **tokenize(char *line);
char *testPath(char **path, char *command);
char *app_path(char *p, char *cmd);
int builtin_handling(char **cmd, char *line);
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

/* helper function for efficient free */
void free_buffers(char **buffer);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */

