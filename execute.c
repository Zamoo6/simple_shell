#include "main.h"
/*
 * exec - function to exectue command's
 * @com: string
 * Return: wating for now command
 */

void exec_com(const char *com)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execlp(com, com, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
