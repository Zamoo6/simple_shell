#include "main.h"
/**
 * _execution - function to execute
 * @command: com
 * @av: st
 * Return: status
 */

int _execution(char **command, char **av)
{
	pid_t child;
	int status;

	child = fork();

	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			freearr(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearr(command);
	}
	return (WEXITSTATUS(status));
}
