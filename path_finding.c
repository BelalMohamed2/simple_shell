#include "shell.h"

/**
 * path_finding - path from the enviroment variable
 * Return: NULL if path is not found or path if path is found.
 */
char *path_finding(void)
{
int x;
char **environment = environ, *path = NULL;

while (*environment)
{
if (str_n_cmp(*environment, "PATH=", 5) == 0)
{
path = *environment;
while (*path && x < 5)
{
path++;
x++;
}
return (path);
}
environment++;
}
return (NULL);
}

