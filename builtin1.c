#include "shell.h"

/**
 * builtin_env - a function that display a env
 */

void builtin_env(void)
{
t_env *tmp = first;

while (tmp)
{
printf("%s\n", tmp->var);
tmp = tmp->next;
}
}
