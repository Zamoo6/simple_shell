#include "main.h"
#include <sys/wait.h>
/**
 * _execute - function to exectue command's
 * Return: wating for now command
 */

void exec_com(const char *com)
{
	pid_t child_pid = fork();
	
	if (child_pid == -1)
	{
		_printf("Warrning: Error process forking");
		exit(EXIT_FAILURE);
	}
	else if (child_pid ==0)
	{
		char *args[256];
		int arg_count = 0;
		
		char *token = strtok((char *)com, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execvp(args[0], args);

		_printf("Warrning: Error comand executing.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
