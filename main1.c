#include "main.h"
/**
 * main - check cide
 * @ac: args num
 * @av: args
 * Return: 0
 */

int main(int ac, char **av)
{

	char *the_line = NULL;
	char **command = NULL;
	int status = 0;
	(void)ac;

	while (1)
	{
		the_line = _read();
		if (the_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
		return (status);
		}
		idx++
		command = _token(the_line);
		if (!command)
			continue;

		if (is_builtin(command[0]))
			handle_builtin(command, av, &static, idx);
		else
			status = _execution(command, av, idx);
	}
}
