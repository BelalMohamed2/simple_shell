#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
/*The two includes to add for the bool type and the define PATH_MAX*/
#include <stdbool.h>
#include <linux/limits.h>

/* Global variable */
extern char **environ;

/* Macros */


/* Functions protortypes */
char **split_command(char *path, char *limit);
void free_array(char **arr);
void execute_command(char **command);
void get_absolute_path(char **command);

/* Builtin prototypes */
void builtin_cd(char *path);
void builtin_pwd(void);
void builtin_echo(const char *input);
void builtin_exit();
int is_builtin(char *command);
void execute_builtin(char **builtin);
#endif /* SHELL_H */
