#include "shell.h"
/*
 * _execute - function to exectue command's
 * Return: wating for now command
 */

void execute_com(const char *com)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid ==0)
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
