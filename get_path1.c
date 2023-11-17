#include "shell.h"

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
/**
 * xfree - frees a string of strings
 * @pp: string of strings
 */
void xfree(char **pp)
{
        char **a = pp;

        if (!pp)
                return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**                                              * _realloc - real aloc
 * @ptr: ptr
 * @old_size: char *
 * @new_size: chat                               * Return: void                                  */                                             
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)                         {                                                       char *p;                                
        if (!ptr)                                               return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
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
