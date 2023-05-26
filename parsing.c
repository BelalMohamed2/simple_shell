#include "shell.h"


/**
 * split_command - a function that will store
 * our command (without spaces) in a char **.
 *@token: the path
 *@limit: the limit
 *
 * Return: 0.
 */
char **split_command(char *token, char *limit)
{
char *ptr = NULL;
char **command = NULL;
size_t index = 0;

ptr = strtok(token, limit);

while (ptr)
{
command = (char **)realloc(command, ((index + 1) * sizeof(char *)));
command[index] = strdup(ptr);
ptr = strtok(NULL, limit);
++index;
}
command = (char **)realloc(command, ((index + 1) * sizeof(char *)));
command[index] = NULL;
return (command);
}


/**
 * free_array - a function that will free our allocation.
 *@arr: an array of command
 */
void free_array(char **arr)
{
int i;
for (i = 0; arr[i]; i++)
{
free(arr[i]);
arr[i] = NULL;
}
free(arr);
arr = NULL;
}


/**
 * execute_command - a function that executes our command with execve.
 *@command: the commant to execute
 */
void execute_command(char **command)
{
pid_t child_pid = 0;
int status = 0;

child_pid = fork();
if (child_pid == -1)
perror("fork");
else if (child_pid > 0)
{
waitpid(child_pid, &status, 0);
kill(child_pid, SIGTERM);
}
else
{
if (execve(command[0], command, NULL) == -1)
perror("shell");
exit(EXIT_FAILURE);
}
}
