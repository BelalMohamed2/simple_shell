include "shell.h"

/**
 **own_strncpy - copies a string
 *@destination: the destination
 *@source: the source
 *@n: le nombre de caractères à copier
 *Return: string dest + source
 */
char *own_strncpy(char *destination, char *source, int n)
{
int i, j;
char *s = destination;

i = 0;
while (source[i] != '\0' && i < n - 1)
{
destination[i] = source[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
destination[j] = '\0';
j++;
}
}
return (s);
}


/**
 **own_strncat - concatenates two strings
 *@destination: the first string
 *@source: the second string
 *@n: the amount of bytes to be maximally used
 *Return: string
 */
char *own_strncat(char *destination, char *source, int n)
{
int i, j;
char *s = destination;

i = 0;
j = 0;
while (destination[i] != '\0')
i++;
while (source[j] != '\0' && j < n)
{
destination[i] = source[j];
i++;
j++;
}
if (j < n)
destination[i] = '\0';
return (s);
}


/**
 **own_strchr - locates a character in a string
 *@string: the string to be parsed
 *@character: the character to look for
 *Return: string
 */
char *own_strchr(char *string, char character)
{
do {
if (*string == character)
return (string);
} while (*string++ != '\0');

return (NULL);
}
