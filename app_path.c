#include "shell.h"
/**
 * app_path - adding path to the command
 * @p: path
 * @cmd:  command
 *
 * Return: bufferfer containing command with path on success
 * NULL on failure
 */
char *app_path(char *p, char *cmd)
{
char *buffer;
size_t i = 0, j = 0;

if (cmd == 0)
cmd = "";

if (p == 0)
p = "";

buffer = malloc(sizeof(char) * (strlenght(p) + strlenght(cmd) + 2));
if (!buffer)
return (NULL);

while (p[i])
{
buffer[i] = p[i];
i++;
}

if (p[i - 1] != '/')
{
buffer[i] = '/';
i++;
}
while (cmd[j])
{
buffer[i + j] = cmd[j];
j++;
}
buffer[i + j] = '\0';
return (buffer);
}

