#include "shell.h"
/**
 * _strcat - concatenates two strings
 * * @dest: the destination buffer
 * * @src: the source buffer
 * *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _realloc - real aloc
 * @ptr: ptr
 * @old_size: char *
 * @new_size: chat
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)                         {                                                       char *p;                                                                                        if (!ptr)                                               return (malloc(new_size));              if (!new_size)                                          return (free(ptr), NULL);
        if (new_size == old_size)
                return (ptr);

        p = malloc(new_size);
        if (!p)
                return (NULL);

        old_size = old_size < new_size ? old_size : new_size;
        while (old_size--)
                p[old_size] = ((char *)ptr)[old_size];
        free(ptr);
        return (p);
}
