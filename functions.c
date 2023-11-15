#include "main.h"
/**
 * _strdup - string duplecation
 * @s: string
 * Return: string
 */

char *_strdup(const char *s)
{
	char *ptr;
	int i, len = 0;
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		len++;
		s++;
	}
	s = s - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = s[i];
	return (ptr);
}

/**
 * _strcmp - string compare
 * @s1: string
 * @s2: string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int cmp;
	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * _strlen - count string length
 * @s: string
 * Return: int
 */

int _strlen(char *s)
{
	int n = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - str cut
 * @d: str
 * @src: str
 * Return: str
 */

char *_strcat(char *d, char *src)
{
<<<<<<< HEAD
	char *p = d;
	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (d);
=======
char *p = d;
while (*p)
	p++;
while (*src)
{
*p = *src;
p++;
src++;
}
*p = '\0';
return (d);
>>>>>>> 01bb5c24dddb201747462fc12fbaa06d624e8889
}

/**
 * _strcpy - str copy
 * @d: str
 * @src: str
 * Return: srr
 */

char *_strcpy(char *d, char *src)
{
	int i = 0;
	while (src[i])
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
