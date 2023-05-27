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


struct builtin
{
  char *env;
  char *exit;
} builtin;

/** Structures*/
struct flags
{
  bool interactive;
} flags;

struct info
{
  int final_exit;
  int ln_count;
} info;

typedef struct informations
{
  int argc;
  char **argv;
  char *args;
  char *chemin;
  unsigned int line_count;
  int histcount;
  int linecount_flag;
  char **environ;
  int env_changed;
  char **cmd_entree;
  int err_num;
  int readfd;
  int status;
  char *fname;
  int cmd_buf_type;
} my_info;

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#define ENTREE 1024
#define TAILLE_ENTREE 1024
#define FLASH -1
#define CMD_NORM 0
#define LINE 0

/* builtins */
int che_builtin(char **cmd, char *buf);
void promp_user(void);
void handle_signal(int m);
char **tokenize(char *line);
char *testPath(char **path, char *command);
char *app_path(char *p, char *cmd);
int builtin_handling(char **cmd, char *line);
void exit_command(char **cmd, char *line);
ssize_t my_input(my_info *info, char **entree, size_t *longueur);
void print_environment(void);

/* string functions */
int strcomp(char *s1, char *s2);
int strlenght(char *s);
int str_n_cmp(char *s1, char *s2, int n);
char *str_duplicate(char *s);
char *str_locate(char *s, char c);
void execute_cmd(char *cp, char **cmd);
char *path_finding(void);

/* free memory */
void free_buffers(char **buffer);


#endif /* SHELL_H */

