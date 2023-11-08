#include "main.h"
/**
 * _free - free array of strings
 * @arr: array
 * Return: void
 */
void _free(char **arr)
{
int i;
if (!arr)
	return;
for (i = 0; arr[i]; i++)
{	
free(arr[i]);
arr[i] = NULL;
}
free(arr), arr = NULL;
}
