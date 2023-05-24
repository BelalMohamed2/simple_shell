#include "shell.h"

/**
 * get_absolute_path - The function that gets the contents
 * of the $PATH variable and returns the absolute path
 *@command: the command enter by user.
 */

void get_absolute_path(char **command)
{

char *path = strdup(getenv("PATH"));
char **path_split = NULL;
char *bin = NULL;
int i;

if (path == NULL)
path = strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
if (command[0][0] != '/' && strncmp(command[0], "./", 2) != 0)
{
path_split = split_command(path, ":");
free(path);
path = NULL;


for (i = 0; path_split[i]; i++)
{
bin = (char *)calloc(sizeof(char), (strlen(path_split[i]) +
1 + strlen(command[0]) + 1));
if (bin == NULL)
break;

strcat(bin, path_split[i]);
strcat(bin, "/");
strcat(bin, command[0]);
if (access(bin, F_OK) == 0)
break;
free(bin);
bin = NULL;
}
free_array(path_split);

free(command[0]);
command[0] = bin;
}
else
{
free(path);
path = NULL;
}
}
