#include "shell.h"                              /**                                              * starts_with - checks if needle starts with haystack                                           * @haystack: string to search                   * @needle: the substring to find                *                                               * Return: address of next char of haystack or NULL                                              */                                             char *starts_with(const char *haystack, const char *needle)                                     {                                                       while (*needle)                                         if (*needle++ != *haystack++)                           return (NULL);                  return ((char *)haystack);              }                                               /**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
                s[i] = b;
        return (s);
}
