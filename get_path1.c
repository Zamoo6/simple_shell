#include "main.h"
/**
 * _getpath - get path
 * @command: str
 * Return: char
 */
char *_getpath(char *command)
{
int i;
char *path_env, *full, *dir;
struct stat st;
for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (stat(command, &st) == 0)
return (_strdup(command));
return (NULL);
}
}
path_env = _getenv("PATH");
dir = strtok(path_env, ":");
while (dir)
{
full = malloc(_strlen(dir) * _strlen(command) + 2);
if (full)
{
_strcpy(full, dir);
_strcat(full, "/");
_strcat(full, command);
if (stat(full, &st) == 0)
{
free(path_env);
return (full);
}
free(full), full = NULL;
dir = strtok(NULL, ":");
}
}
free(path_env);
return (NULL);
}
