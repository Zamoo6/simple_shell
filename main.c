#include "main.h"
/*
 * _main - privet program emulate CMD
 * Return: 0
 */

int main(void)
{
	char com[64];

	while (1)
	{
		print_prompt();
		read_com(char *com, size_t size);
		exec_com(const char *com);
	}

	return 0;
}
