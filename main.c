#include "main.h"

/**
 * main - check cide
 * @ac: args num
 * @argv: args
 * Return: 0
 */                                             int main(int ac, char **argv)
{
<<<<<<< HEAD
char *the_line = NULL;
char **command = NULL;
int status = 0, idx = 0;
(void)ac;
while (1)
{                                               the_line = _read();
if (the_line == NULL)
{
if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "\n", 1);
return (status);
}
idx++;
command = _token(the_line);
if (!command)
        continue;
status = _execution(command, argv, idx);
}

	char com[256];

	while (1)
	{
		print_prompt();
		read_com(com, sizeof(com));
		exec_com(com);
	}

	return 0;
>>>>>>> 4035660fb1df907bfc799e8036abf2777823d861
}
