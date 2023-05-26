#include "shell.h"

/**
 * app_path - adding path to the command
 * @p: path
 * @cmd:  command
 *
 * Return: string input
 */
char *app_path(char *p, char *cmd)
{
char *input;
size_t i = 0, j = 0;

if (cmd == 0)
cmd = "";

if (p == 0)
p = "";
input = malloc(sizeof(char) * (strlenght(p) + strlenght(cmd) + 2));
if (!input)
return (NULL);
while (p[i])
{
input[i] = p[i];
i++;
}

if (p[i - 1] != '/')
{
input[i] = '/';
i++;
}
while (cmd[j])
{
input[i + j] = cmd[j];
j++;
}
input[i + j] = '\0';
return (input);
}

