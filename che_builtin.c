#include "shell.h"
/**
 *che_builtin- checks to see built_in function
 *@cmd: separate inputs
 *@buffer: line from get line
 *Return: 1 if cmd  0 if cmd is not
 */
int che_builtin(char **cmd, char *buffer)
{
if (builtin_handling(cmd, buffer))
return (1);
else if (**cmd == '/')
{
execute_cmd(cmd[0], cmd);
return (1);
}
return (0);
}
