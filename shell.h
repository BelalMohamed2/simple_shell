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
int limit(char c, char *limit);
int alpha(int c);
int atoi_style(char *s);
char **separat_line(char *line, char **arg_arr);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* Builtin prototypes */
void builtin_cd(char *path);
void builtin_pwd(void);
void builtin_echo(const char *input);
int is_builtin(char *command);
void execute_builtin(char **builtin);

char *own_strncpy(char *destination, char *source, int n);
char *own_strncat(char *destination, char *source, int n);
char *own_strchr(char *string, char character);

#endif /* SHELL_H */
