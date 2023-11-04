#include "main.h"
/*
 * _u_input - function that recive
 * user input parameters
 * Return: 
 */

void read_com(char *com, size_t size)
{
	if (fgets(com, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_printf("Reading inputs ERROR!.\n");
			exit(EXIT_FAILURE);
		}
	}
	com[strcspn(com, "\n")] = '\0';
}

