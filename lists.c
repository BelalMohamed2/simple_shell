#include "shell.h"


char **list_elm_array(void)
{
  char **array = NULL;
  t_env *tmp = first;
  size_t index = 0;

  while (tmp) {
    index++;
    tmp= tmp->next;
  }

  array = (char **)calloc(sizeof(char *), index + 1);
  if (array == NULL) {
    perror("calloc");
    exit(-1);
  }

  tmp = first;
  index = 0;

  while (tmp) {
    array[index] = tmp->var;
    tmp = tmp->next;
    index++;
  }

  return (array);
}



/***/

void free_list(void)
{
  t_env*idx = first;
  t_env*tmp = idx;

  while (idx != NULL) {
    tmp = idx;
    idx = idx->next;
    free(tmp->var);
    tmp->var = NULL;
    free(tmp);
    tmp = NULL;
  }
}
