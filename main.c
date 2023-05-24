#include "shell.h"
/**
 * separat_line - separate the line enterdd into array
 * @line: the input line from stdin
 * @arg_arr: the array that will be out
 * Return: pointer to array
 */
char **separat_line(char *line, char **arg_arr)
{
char *tok = NULL;
int i = 1;

tok = strtok(line, " \n");
arg_arr[0] = tok;
tok = strtok(NULL, " \n");
i = 1;
while (tok != NULL)
{
arg_arr = _realloc(arg_arr, sizeof(arg_arr), (i + 2) * sizeof(char *));
arg_arr[i] = tok;
tok = strtok(NULL, " \n");
i++;
}
arg_arr[i] = NULL;
return (arg_arr);
}
/**
 * main - get the line
 * Return: the number of characters and -1 if there is error
 */
int main(void)
{
char *line = NULL;
char **arg_arr;
size_t size = 0;
ssize_t nread = 0;
/*
 * extern char **environ;
 */
pid_t child_pid;
int stat;

arg_arr = malloc(2 * sizeof(char *));
while (1)
{
printf("#cisfun$ ");
nread = getline(&line, &size, stdin);
if (nread == -1)
break;
arg_arr = separat_line(line, arg_arr);
child_pid = fork();
if (child_pid == 0)
{
if (execve(arg_arr[0], arg_arr, NULL) == -1)
{
perror("./shell");
break;
}
}
else
{
wait(&stat);
continue;
}
}
free(line);
free(arg_arr);
return (0);
}
