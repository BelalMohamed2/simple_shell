#include "shell.h"

/**
 * builtin_handling - handles builtin functions
 * @cmd: arr of commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */
int builtin_handling(char **cmd, char *line)
{
struct builtin builtin = {"env", "exit"};

if (strcomp(*cmd, builtin.env) == 0)
{
print_environment();
return (1);
}
else if (strcomp(*cmd, builtin.exit) == 0)
{
exit_command(cmd, line);
return (1);
}
return (0);
}

