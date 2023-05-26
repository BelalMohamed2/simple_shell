#include "shell.h"

/**
 * builtin_cd - a function that change directory
 *@path: the path
 *
 * Return: Nothing.
 */

void builtin_cd(char *path)
{
char *previous_pwd = NULL;
char *pwd = NULL;
char *pwd_ptr = NULL;

if (path == NULL)
return;
if (chdir(path) == 0)
{
pwd = strrchr(get_env_var("PWD="), '=') + 1;
previous_pwd = strrchr(get_env_var("previous_pwd="), '=') + 1;

if (previous_pwd != NULL && pwd != NULL)
{
strcpy(previous_pwd, pwd);
}
if (pwd != NULL)
{
pwd = &pwd[-strlen("PWD=")];
pwd_ptr = builtin_pwd();
strcpy(pwd, pwd_ptr);
free(pwd_ptr);
pwd_ptr = NULL;
}
}
else
{
perror("chdir");
}
}



/**
 * builtin_pwd - a function that display the path
 *
 * Return: string
 */
char *builtin_pwd(void)
{
char *cwd = NULL;

cwd = (char *)calloc(sizeof(char), PATH_MAX + strlen("PWD=") + 1);
if (cwd == NULL)
return (NULL);
strcat(cwd, "PWD=");
if (getcwd(&cwd[4], PATH_MAX) == NULL)
{
perror("getcwd()");
}
return (cwd);
}



/**
 * builtin_echo - a function that display a message
 * @input: the message to print
 */
void builtin_echo(const char *input)
{
int length = strlen(input);
int i;

for (i = 0; i < length; i++)
{
putchar(input[i]);
}
putchar('\n');
}


/**
 * is_builtin - the built-in for it to use the environment.
 * @command: the command
 *
 * Return: 0
 */
int is_builtin(char *command)
{
const char *builtin[] = {"pwd", "cd", NULL};
int i;

for (i = 0; builtin[i]; i++)
{
if (!strcmp(builtin[i], command))
return (1);
}
return (0);
}


/**
  * execute_builtin - the built-in for it to use the environment.
  * @builtin: the builtin
  *
  *Return: Nothing
  */
void execute_builtin(char **builtin)
{
if (!strcmp(builtin[0], "pwd"))
builtin_pwd();
else if (!strcmp(builtin[0], "cd"))
builtin_cd(builtin[1]);
}
