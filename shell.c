#include "shell.h"
/**
* main - main function
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
char *line = NULL, *pathcommand = NULL, *path = NULL;
size_t buffer_size = 0;
ssize_t linesize = 0;
char **command = NULL, **paths = NULL;
(void)envp, (void)av;
if (ac < 1)
return (-1);
signal(SIGINT, handle_signal);
while (1)
{
free_buffers(command);
free_buffers(paths);
free(pathcommand);
promp_user();
linesize = getline(&line, &buffer_size, stdin);
if (linesize < 0)
break;
info.ln_count++;
if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';
command = tokenize(line);
if (command == NULL || *command == NULL || **command == '\0')
continue;
if (che_builtin(command, line))
continue;
path = path_finding();
paths = tokenize(path);
pathcommand = testPath(paths, command[0]);
if (!pathcommand)
perror(av[0]);
else
execute_cmd(pathcommand, command);
}
if (linesize < 0 && flags.interactive)
write(STDERR_FILENO, "\n", 1);
free(line);
return (0);
}

