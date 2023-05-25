#include "shell.h"

/**
* exit_command - exit command and free buffers
* @cmd: tokenized command
* @line: line from get line
*
* Return: no return
*/
void exit_command(char **cmd, char *line)
{
free(line);
free_buffers(cmd);
exit(0);
}
