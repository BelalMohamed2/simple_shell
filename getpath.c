#include "shell.h"

/**
 * get_absolute_path - The function that gets the contents of the $PATH variable and returns the absolute path
 *@command: the command enter by user.
 */

void get_absolute_path(char **command){
char *path = strdup(getenv("PATH"));
char **path_split = NULL;
char *bin = NULL;
int i;

/** if the path is null, we create a path */
if (path == NULL)
  path = strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");

/** if command is not the absolute path,
 * we look for the absolute path of binary
 * with the environment variable PATH
 */
 if (command[0][0] != '/' && strncmp(command[0], "./", 2) != 0){

   /** We split the path to check where the binary is located*/
path_split = split_command(path, ":");
free(path);
path = NULL;

/** We split the path to check where the binary is located */
for(i = 0; path_split[i]; i++){
  /** alloc len of path + '/' + len of binary + 1 for the '\0'*/
bin = (char *)calloc(sizeof(char), (strlen(path_split[i]) + 1 + strlen(command[0]) + 1));
if (bin == NULL)
break;

/** We concatenate the path , the '/' and the binary name */
strcat(bin, path_split[i]);
strcat(bin, "/");
strcat(bin, command[0]);

/** Check the existence of the file and exit the loop if access returns 0
 */
if (access(bin, F_OK) == 0)
break;

/** free memory*/
free(bin);
bin = NULL;
}
free_array(path_split);

/** The binary is replaced by the absolute path or NULL if the binary does not exist */

free(command[0]);
command[0] = bin;
}else{
free(path);
path = NULL;
}
}
