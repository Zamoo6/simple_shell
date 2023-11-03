#include "main.h"
/**
 * _printf - print string
 * @string: char
 * Return: void
 */
void _printf(const char *string)
{
write(STDOUT_FILENO, string, strlen(string));
}
