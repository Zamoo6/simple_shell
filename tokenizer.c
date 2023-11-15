#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
/**                                              * _strcpy - copies a string
 * @dest: the destination                        * @src: the source
 *                                               * Return: pointer to destination                */
char *_strcpy(char *dest, char *src)            {
        int i = 0;

        if (dest == src || src == 0)
                return (dest);
        while (src[i])                                  {
                dest[i] = src[i];                               i++;
        }
        dest[i] = 0;
        return (dest);
}
/**                                              * _strlen - returns the length of a string      * @s: the string whose length to check          *                                               * Return: integer length of string              */                                             int _strlen(char *s)                            {                                                       int i = 0;                                                                                      if (!s)                                                 return (0);                                                                             while (*s++)                                            i++;
        return (i);
}
/**
 *_puts - prints an input string
 i*@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * xfree - frees a string of strings
 * @p: string of strings
 */
void xfree(char **p)
{
	char **a = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(a);
}
