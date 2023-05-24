#include "shell.h"

/**
 * limit - checks if character is a limit
 * @c: the char to check
 * @limit: the delimeter string
 * Return: 1
 */
int limit(char c, char *limit)
{
while (*limit)
if (*limit++ == c)
return (1);
return (0);
}

/**
 * alpha - checks for alphabetic character
 * @c: The character to input
 * Return: 0.
 */

int alpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * atoi_style - converts a string to an integer
 * @s: the string to be converted
 * Return: 0.
 */

int atoi_style(char *s)
{
int i, signe = 1, drapeau = 0, output;
unsigned int res = 0;

for (i = 0; s[i] != '\0' && drapeau != 2; i++)
{
if (s[i] == '-')
signe *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
drapeau = 1;
res *= 10;
res += (s[i] - '0');
}
else if (drapeau == 1)
drapeau = 2;
}

if (signe == -1)
output = -res;
else
output = res;

return (output);
}
