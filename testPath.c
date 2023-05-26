#include "shell.h"

/**
* testPath - checks the path validitiy
* @path: the separated path
* @command: command
*
* Return: path appended with command on success
* NULL on failure
*/
char *testPath(char **path, char *command)
{
int i = 0;
char *outputvalue;

while (path[i])
{
outputvalue = app_path(path[i], command);
if (access(outputvalue, F_OK | X_OK) == 0)
return (outputvalue);
free(outputvalue);
i++;
}
return (NULL);
}

