#include "shell.h"

/**
 *che_builtin- checks to see built_in function
 *@command: separate inputs
 *@input: line from get line
 *Return: 1 or 0.
 */
int che_builtin(char **command, char *input)
{
if (builtin_handling(command, input))
return (1);
else if (**command == '/')
{
execute_cmd(command[0], command);
return (1);
}
return (0);
}
