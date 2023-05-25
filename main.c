#include "shell.h"

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
char **command = NULL;

input = (char *)calloc(sizeof(char), input_size);
if (input == NULL)
{
perror("Calloc failed");
return (EXIT_FAILURE);
}

write(1, message, sizeof(message));


while (getline(&input, &input_size, stdin) > 0)
{
command = split_command(input, " \n\t");
get_absolute_path(command);

if (command[0] == NULL)
printf("Command not found\n");
else
execute_command(command);

write(1, message, sizeof(message));
free_array(command);

}
free(input);
return (0);
}
