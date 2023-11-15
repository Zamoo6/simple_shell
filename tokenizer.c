#include "main.h"
/**
 * _token - tokenize
 * @line: str
 * Return: str
 */
char **_token(char *line)
{
int i = 0;
char **command = NULL;
int n = 0;
char *token = NULL, *tmp = NULL;
if (!line)
	return (NULL);
tmp = _strdup(line);
token = strtok(tmp, DELIM);
if (token == NULL)
{
free(line), line = NULL;
free(tmp), tmp = NULL;
return (NULL);
}
while (token)
{
n++;
token = strtok(NULL, DELIM);
}
free(tmp), tmp = NULL;
command = malloc(sizeof(char *) * (n + 1));
if (!command)
{
free(line);
line = NULL;
return (NULL);
}
token = strtok(line, DELIM);
while (token)
{
command[i] = _strdup(token);
token = strtok(NULL, DELIM);
i++;
}
free(line), line = NULL;
command [i] = NULL;
return (command);
}
