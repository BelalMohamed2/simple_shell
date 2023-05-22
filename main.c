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
printf("cmd = %s\n", input);
write(1, message, sizeof(message));
}
free(input);
return (0);
}
