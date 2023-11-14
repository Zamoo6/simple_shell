#include "main.h"

/**                                              * main - check cide
 * @ac: args num
 * @argv: args
 * Return: 0
 */                                             int main(int ac, char **argv)
{
char *the_line = NULL;
char **command = NULL;
int status = 0, idx = 0;
(void)ac;
while (1)
{                                               the_line = _read();
if (the_line == NULL)
{
if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "\n", 1);
return (status);
}
idx++;
command = _token(the_line);
if (!command)
        continue;
status = _execution(command, argv, idx);
}
}
