#include "shell.h"
/**
 * number_convert - num convert
 * @n: num
 * @b: int
 * @flags: int
 * Return: char
 */

char *number_convert(long int n, int b, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long num = n;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[num % b];
		num /= b;
	} while (num != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * comments_remove - function replaces first ins
 * tance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */

void comments_remove(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
