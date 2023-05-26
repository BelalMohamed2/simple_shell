#include "shell.h"

/**
* tokenize - creates toke
* @line: to be tokenized
*
* Return: array of strings
*/
char **tokenize(char *line)
{
char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
char **tokens = NULL;
int token_size = 1;
size_t index = 0, flag = 0;

buf = str_duplicate(line);
if (!buf)
return (NULL);
bufp = buf;

while (*bufp)
{
if (str_locate(delim, *bufp) != NULL && flag == 0)
{
token_size++;
flag = 1;
}
else if (str_locate(delim, *bufp) == NULL && flag == 1)
flag = 0;
bufp++;
}
tokens = malloc(sizeof(char *) * (token_size + 1));
token = strtok(buf, delim);
while (token)
{
tokens[index] = str_duplicate(token);
if (tokens[index] == NULL)
{
free(tokens);
return (NULL);
}
token = strtok(NULL, delim);
index++;
}
tokens[index] = '\0';
free(buf);
return (tokens);
}

