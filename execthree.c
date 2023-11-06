#include "main.h"
/**
 * execthree - execute the function
 * @argv: argumen5
 */
void execthree(char **argv)
{
char *com = NULL, *actual_com = NULL;
if (argv)
{
com = argv[0];
actual_com = get_path(com);
if (execve(actual_com, argv, NULL) == -1)
{
perror("Error");
}
}
}
