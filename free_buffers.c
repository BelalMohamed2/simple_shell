#include "shell.h"

/**
* free_buffers - frees buffers
* @buffer: buffer to be freed
*
* Return: no value returned
*/
void free_buffers(char **buffer)
{
int i = 0;

if (!buffer || buffer == NULL)
	return;
while (buffer[i])
{
	free(buffer[i]);
	i++;
}
free(buffer);
}
