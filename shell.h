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

/* Global variable */
extern char **environ;

/* Macros */
#define PATH_MAX 1024

/* functions protortypes */
char **split_command(char *path, char *limit);
void free_array(char **arr);
void execute_command(char **command);
void get_absolute_path(char **command);

#endif /* SHELL_H */
