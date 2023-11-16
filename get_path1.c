#include "shell.h"
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _memset - fills memory with a constant byte
 * @str: he pointer to the memory area
 * @ba: the byte to fill *s with
 * @num: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */

char *_memset(char *str, char ba, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		str[i] = ba;
	return (str);
}
