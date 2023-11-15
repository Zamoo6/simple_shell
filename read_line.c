#include "main.h"
/**
 * _read - reads the line
 * Return: line
 */
char *_read(void)
{
char *line = NULL;
size_t length = 0;
ssize_t num;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
num = getline(&line, &length, stdin);
if (num == -1)
{
free(line);
return (NULL);
}
return (line);
}
