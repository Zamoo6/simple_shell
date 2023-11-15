#include "shell.h"

/**
 **_strncpy - copies a string
 *@d: the destination string to be copied to
 *@s: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *d, char *s, int n)
{
	int i, j;
	char *str = d;

	i = 0;
	while (s[i] != '\0' && i < n - 1)
	{
		d[i] = s[i];
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
	return (str);
}
/**                                              **_strchr - locates a character in a string
 *@str: the string to be parsed                  *@char: the character to look for               *Return: (s) a pointer to the memory area s     */                                             char *_strchr(char *str, char char)             {                                                       do {                                                    if (*str == char)                                       return (str);                   } while (*str++ != '\0');                                                                       return (NULL);                          }
/**
 **_strncat - concatenates two strings
 *@d: the first string
 *@s: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *d, char *s, int n)
{
	int i, j;
	char *str = d;

	i = 0;
	j = 0;
	while (d[i] != '\0')
		i++;
	while (s[j] != '\0' && j < n)
	{
		d[i] = s[j];
		i++;
		j++;
	}
	if (j < n)
		d[i] = '\0';
	return (str);
}
