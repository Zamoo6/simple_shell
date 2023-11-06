#include "main.h"
/**
 * get_path - get command path
 * @com: command
 */
char *get_path(char *com)
{
char *path, *copy_path, *token_path, *path_file;
int len, dir_len;
struct stat buf;
path = getenv("PATH");
if (path)
{
copy_path = strdup(path);
len = strlen(com);
token_path = strtok(copy_path, ":");
while (token_path != NULL)
{
dir_len = strlen(token_path);
path_file = malloc(len + dir_len + 2);
strcpy(path_file, token_path);
strcat(path_file, "/");
strcat(path_file, com);
strcat(path_file,"\0");
if (stat(path_file, &buf) == 0)
{
free(path_file);
return (path_file);
}
else
{
free(path_file);
token_path = strtok(NULL, ":");
}
}
free(copy_path);
if (stat(com, &buf) == 0)
{
return (com);
}
return (NULL);
}
return (NULL);
}
