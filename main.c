#include "shell.h"


/**
 * split_command - a function that will store
 * our command (without spaces) in a char **.
 *@path: the path
 *@limit
 */

char **split_command(char *path, char *limit)
{
char *ptr = NULL;
char **command = NULL;
size_t index = 0;

ptr = strtok(path, limit);

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

  /** fork */
child_pid = fork();
if (child_pid == -1)
perror("fork failed");

else if (child_pid > 0)
{
waitpid(child_pid, &status, 0);
kill(child_pid, SIGTERM);
}
else
{
    /** The child process executes the command or exit if execve fails */
if (execve(command[0], command, NULL) == -1)
perror("./shell");
exit(EXIT_FAILURE);
}
}



/**
 * main - a function that makes a loop in which
 * we read STDIN : the user's command
 *
 * Return: 0.
 */

int main(void)
{
char *input = NULL;
size_t input_size = 2048;
char message[] = "#cisfun$ ";
char **command =  NULL;

  /** alloc buffer which will store the command entered by the user */
input = (char *)calloc(sizeof(char), input_size);
if (input == NULL)
{
perror("Calloc failed");
return (EXIT_FAILURE);
}
  /** writing a prompt */
write(1, message, sizeof(message));
  /** STDIN playback in a loop*/
while (getline(&input, &input_size, stdin) > 0)
{
command = split_command(input, "\n\t");

if (command[0] == NULL)
printf("Command not founf\n");
else if (is_builtin(command[0]) == 0)
{
get_absolute_path(command);
execute_command(command);
}
else
{
execute_builtin(command);
}
write(1, message, sizeof(message));
free_array(command);
}
free(input);
return (0);
}
