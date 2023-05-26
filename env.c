#include "shell.h"

/**
 * env_var - a function
 * @var: var env
 */
void env_var(char *var)
{
struct passwd *pw = getpwuid(getuid());
char *alloc = NULL;

if (!strcmp(var, "HOME"))
{
alloc = (char *)calloc(sizeof(char), strlen(pw->pw_dir) +
strlen("HOME=") + 1);
if (alloc == NULL)
{
fprintf(stderr, "Cannot add HOME\n");
return;
}
strcat(alloc, "HOME=");
strcat(alloc, pw->pw_dir);
}
else if (!strcmp(var, "PATH"))
{
alloc = strdup("PATH=/bin:/usr/bin");
if (alloc == NULL)
{
fprintf(stderr, "Cannot add PATH\n");
return;
}
else if (!strcmp(var, "OLDPWD"))
{
alloc = strdup("OLDPWD=");
if (alloc == NULL)
{
fprintf(stderr, "Cannot add OLDPWD\n");
return;
}
}
else if (!strcmp(var, "PWD"))
{
alloc = builtin_pwd();
if (alloc == NULL)
{
fprintf(stderr, "Cannot add PWD\n");
return;
}
}
else if (!strcmp(var, "SHLVL"))
{
alloc = strdup("SHLVL=1");
if (alloc == NULL)
{
fprintf(stderr, "Cannot add OLDPWD\n");
return;
}
}
tail(alloc);
}
}

/**
 * env - a function
 *@env: the variable
 */

void env(char **env)
{
char *var_lst[] = {"PATH", "HOME", "OLDPWD", "PWD", "SHLVL", NULL};
ssize_t nb_element = 5;
int i;
for (i = 0; env[i]; i++)
{
tail(strdup(env[i]));

if (!strncmp(env[i], "PATH", 4))
var_lst[0] = NULL;
else if (!strncmp(env[i], "HOME", 4))
var_lst[1] = NULL;
else if (!strncmp(env[i], "OLDPWD", 6))
var_lst[2] = NULL;
else if (!strncmp(env[i], "PWD", 3))
var_lst[3] = NULL;
else if (!strncmp(env[i], "SHLVL", 5))
var_lst[4] = NULL;
}

for (i = 0; i < nb_element; i++)
{
if (var_lst[i] != NULL)
env_var(var_lst[i]);
}
}


/**
 * get_env_var - to get the environment variable
 *@var: the variable
 *
 *Return: string
 */
char *get_env_var(char *var)
{
t_env *tmp = first;
size_t len = 0;

len = strlen(var);

while (tmp)
{
if (!strncmp(var, tmp->var, len))
{
return (tmp->var);
}
tmp = tmp->next;
}
return (NULL);
}
