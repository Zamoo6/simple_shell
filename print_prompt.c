#include "main.h"
/**
 * print_prompt - print prompt
 * @ac: int
 * @av: cha
 * Return: void
 */
void print_prompt(int ac, char **av)
{
char *pro = "$ ";
char *lineptr;
size_t n = 0;
(void)ac;
(void)av;
_printf(pro);
getline(&lineptr, &n, stdin);
_printf(lineptr);
free(lineptr);
}
