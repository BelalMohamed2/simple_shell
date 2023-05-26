#include "shell.h"

/**
 * builtin_handling - handles builtin functions
 * @command: arr of commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */
int builtin_handling(char **command, char *line)
{
struct builtin builtin = {"env", "exit"};

if (strcomp(*command, builtin.env) == 0)
{
print_environment();
return (1);
}
else if (strcomp(*command, builtin.exit) == 0)
{
exit_command(command, line);
return (1);
}
return (0);
}

