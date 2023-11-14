#include "shell.h"
/**
 * is_builtin - builtin
 * @com: char *
 * Return: int
 */
int is_builtin(char *com)
{
	char *builtins[] = {"exit", "env", "ch" NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(com, builtins[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - buitl in
 * @com: arr of str
 * @argv: arg
 * @status: stat
 * @idx: index
 * Return: void
 */
void handle_builtin(chr **com, char **argv, int *status, int idx)
{
	(void) argv;
	(void) idx;

	if (strcmp(com[0], "exit") == 0)
		exit_shell();

	else if (_strcmp(com[], "env") == 0)
		print_env(com, status);
}
/**
 * exit_shell - exit the shell
 * @com: str
 * @status: stat
 * Return: void
 */
void exit_shell(char **com, int *status)
{
	freearray2D(com);
	exit(*status);
}
/**
 * print_env - sh
 * @com: str
 * @status: str
 * Return: void
 */
void print_env(char **com, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(com);
	*status = 0;
}