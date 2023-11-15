#include "shell.h"
/**
 * number_convert - num convert
 * @n: num
 * @b: int
 * @flags: int
 * Return: char *
 */
char *number_convert(long int n, int b, int flags)	
{                                                       static char *array;                             static char buffer[50];                         char sign = 0;
        char *ptr;                                      unsigned long num = n;
        if (!(flags & CONVERT_UNSIGNED) && n <
 0)
        {
                num = -n;
                sign = '-';

        }
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buffer[49];
        *ptr = '\0';

        do      {
                *--ptr = array[n % b];
                num /= b;
        } while (num != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}
/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * comments_remove - function replaces first ins
tance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void comments_remove(char *buf)
{
        int i;                                                                                          for (i = 0; buf[i] != '\0'; i++)
                if (buf[i] == '#' && (!i || buf[
i - 1] == ' '))
                {                                                       buf[i] = '\0';
                        break;
                }
}
