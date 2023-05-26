#include "shell.h"

/**
* print_environment - prints the environment string to stdout
*
* Return: 0
*/
void print_environment(void)
{
int x = 0;
char **env = environ;

while (env[x])
{
write(STDOUT_FILENO, (const void *)env[x], strlenght(env[x]));
write(STDOUT_FILENO, "\n", 1);
x++;
}
}

