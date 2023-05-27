#include "shell.h"

/**
 * entree - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: octects lus
 */
ssize_t entree(my_info *info)
{
char **buf_p = &(info->args), *p;
static size_t i, j, longueur;
ssize_t r = 0;
static char *buf;
putchar(FLASH);
r = my_input(info, &buf, &longueur);
if (r == -1)
return (-1);
if (longueur)
{
j = i;
p = buf + i;
check_chain(info, buf, &j, i, longueur);
while (j < longueur)
{
if (is_chain(info, buf, &j))
break;
j++;
}
i = j + 1;
if (i >= longueur)
{
i = longueur = 0;
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p;
return (strlen(p));
}
*buf_p = buf;
return (r);
}



/**
 * lire_entree - lire une entrée
 * @info: parameter struct
 * @entree: entreefer
 * @n: size
 *
 * Return: r
 */
ssize_t lire_entree(my_info *info, char *entree, size_t *n)
{
ssize_t r = 0;
if (*n)
return (0);
r = read(info->readfd, entree, TAILLE_ENTREE);
if (r >= 0)
*n = r;
return (r);
}


/**
 * _getline - gets the next line of input from STDIN
* @info: parameter one
* @pointee: parameter two
* @longueur: parameter 3
* Return: string
 */
int _getline(my_info *info, char **pointee, size_t *longueur)
{
size_t k;
char *p = NULL, *new_p = NULL, *c;
ssize_t r = 0, s = 0;
static char buf[READ_BUF_SIZE];
static size_t i, len;
p = *pointee;
if (p && longueur)
s = *longueur;
if (i == len)
i = len = 0;
r = lire_entree(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);
c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + k : k + 1);
if (!new_p)
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buf + i, k - i);
else
_strncpy(new_p, buf + i, k - i + 1);
s += k - i;
i = k;
p = new_p;
if (longueur)
*longueur = s;
*pointee = p;
return (s);
}


/**
 * control_c - controle c function
 * @sig_num: param 1
 *
 * Return: Nothing
 */
void control_c(__attribute__((unused))int sig_num)
{
puts("\n");
puts("$ ");
putchar(BUF_FLUSH);
}


/**
 * my_input - buffers chained commands
 * @info: param one
 * @entree: param two
 * @longueur: param three
 *
 * Return: nombres d'octects lus
 */
ssize_t my_input(my_info *info, char **entree, size_t *longueur)
{
size_t longueur_p = 0;
ssize_t r = 0;
if (!*longueur)
{
free(*entree);
*entree = NULL;
signal(SIGINT, sigintHandler);
USE_GETLINE
r = getline(entree, &longueur_p, stdin);
r = _getline(info, entree, &longueur_p);
if (r > 0)
{
if ((*entree)[r - 1] == '\n')
{
(*entree)[r - 1] = '\0';
r--;
}
info->linecount_flag = 1;
remove_comments(*entree);
build_history_list(info, *entree, info->histcount++);
{
*longueur = r;
info->cmd_entree = entree;
}
}
}
return (r);
}
