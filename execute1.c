#include "main.h"
/**
 * _execute - execute the program
 * @command: str
 * @argv: str
<<<<<<< HEAD
 * @idx: int parameter
 * Return: in
=======
 * @idx: int
 * Return: int
>>>>>>> 01bb5c24dddb201747462fc12fbaa06d624e8889
 */

int _execute(char **command, char **argv, int idx)
{
<<<<<<< HEAD
	char *full;
	pid_t child;
	int status;

	full = _getpath(command[0]);

	if (!full)
	{
		print_error(argv[0], command[0], int idx);
		freearr(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full, command, environ) == -1)
		{
			free(full);
			full = NULL;
			freearr(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearr(command);
		free(full), full = NULL;
	}
	return (WEXITSTATUS(status));
=======
char *full;
pid_t child;
int status;
full = _getpath(command[0]);
if (!full)
{
print_error(argv[0], command[0], int idx);
freearr(command);
return (127);
}
child = fork();
if (child == 0)
{
if (execve(full, command, environ) == -1)
{
free(full);
full = NULL;
freearr(command);
}
}
else
{
waitpid(child, &status, 0);
freearr(command);
free(full), full = NULL;
}
return (WEXITSTATUS(status));
>>>>>>> 01bb5c24dddb201747462fc12fbaa06d624e8889
}
