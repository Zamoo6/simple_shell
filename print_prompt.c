#include "main.h"
/**
 * print_prompt - print prompt
 * @ac: int
 * @av: cha
 * Return: void
 */
int print_prompt(int ac, char **av)
{
ssize_t end;
char *pro = "$ ";
char *lineptr;
size_t n = 0;
(void)ac;
(void)av;
while (true)
{
_printf(pro);
end = getline(&lineptr, &n, stdin);
if (end == -1)
{
_printf("SHELL EXIT\n");
return (-1);
}
_printf(lineptr);
free(lineptr);
}
return (0);
}
