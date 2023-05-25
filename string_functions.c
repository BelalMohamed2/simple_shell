#include "shell.h"

/**
* strcomp - compares two strings
* @str_1: compare to str_2
* @str_2: compare to str_1
* Return: returns difference between strings
*/
int strcomp(char *str_1, char *str_2)
{
int i = 0, output;

while (*(str_1 + i) == *(str_2 + i) && *(str_1 + i) != '\0')
i++;

output = (*(str_1 + i) -*(str_2 + i));

return (output);
}

/**
* strlenght - returns the length of a string
* @s: string passed
*
* Return: returns length of string passed
*/
int strlenght(char *s)
{
int count = 0;

while (*s != '\0')
{
count++;
s++;
}
return (count);
}

/**
* str_n_cmp - compares two strings up to n bytes
* @str_1: compared to str_2
* @str_2: compared to str_1
* @n: number of bytes
*
* Return: difference between str_1 and str_2
*/
int str_n_cmp(char *str_1, char *str_2, int n)
{
int i;

for (i = 0; str_1[i] && str_2[i] && i < n; i++)
{
if (str_1[i] != str_2[i])
return (str_1[i] - str_2[i]);
}
return (0);
}

/**
* str_duplicate - duplicate string
* @s: to be duplicated
*
* Return: pointer string
*/
char *str_duplicate(char *s)
{
char *ptr;
int i, len;

if (s == NULL)
return (NULL);

len = strlenght(s);

ptr = malloc(sizeof(char) * (len + 1));
if (!ptr)
return (NULL);
for (i = 0; *s != '\0'; s++, i++)
ptr[i] = s[0];

ptr[i++] = '\0';
return (ptr);
}

/**
* str_locate - locates a character in a string
* @s: string to be checked
* @c: character to be located
* Return: returns pointer to first occurence of character
*/
char *str_locate(char *s, char c)
{
while (*s)
{
if (*s == c)
return (s);
s++;
}
if (!c)
return (s);
return (NULL);
}

