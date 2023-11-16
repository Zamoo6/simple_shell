#include "shell.h"

/**
 **_strncpy - copies a string
 *@d: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *d, char *src, int n)
{
	int i, j;
	char *s = d;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		d[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@str: the string to be parsed
 *@ch: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
/**
 **_strncat - concatenates two strings
 *@d: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *d, char *src, int n)
{
	int i, j;
	char *s = d;

	i = 0;
	j = 0;
	while (d[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		d[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		d[i] = '\0';
	return (s);
}
