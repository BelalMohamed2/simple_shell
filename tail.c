#include "shell.h"

/**
 * tail - a function that add tail
 * @var: the variable
 */
void tail(char *var)
{
t_env *ptr = first;
t_env *new_node = NULL;

new_node = (t_env *)calloc(sizeof(t_env), 1);
if (new_node == NULL) {
printf("Alloc failure\n");
return ;
}

new_node->var = var;
new_node->next = NULL;

if (ptr == NULL)
{
first = new_node;
}
else
{
while (ptr->next != NULL)
ptr = ptr->next;
ptr->next = new_node;
}
}
