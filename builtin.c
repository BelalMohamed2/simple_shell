#include "shell.h"

/**
 * builtin_cd - a function that change directory
 *@path: the path
 *
 * Return: 0.
 */

void builtin_cd(char *path)
{
if (chdir(path) == -1)
{
perror("cd");
}
}

/**
 * builtin_pwd - a function that display the path
 */
void builtin_pwd(void)
{
char cwd[PATH_MAX];

if (getcwd(cwd, sizeof(cwd)) != NULL)
{
printf("%s\n", cwd);
}
else
{
perror("pwd");
}
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
