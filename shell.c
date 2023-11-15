#include "shell.h"

/**
 * sh - main shell loop
 * @inf: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int sh(info_t *inf, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && bultin_ret != -2)
	{
		info_clear(info);
		if (interact(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = mnl_get_input(info);
		if (r != -1)
		{
			info_set(info, argv);
			builtin_ret = find_bultin(info);
			if (builtin_ret == -1)
				find_cm(info);
		}
		else if (interact(info))
			_putchar('\n');
		info_free(info, 0);
	}
	write_e_hist(info);
	info_free(info, 1);
	if (!interact(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_bultin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_bultin(info_t *info)
{
	int i, built_int_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _weexit},
		{"env", _ourenv},
		{"help", _wehelp},
		{"history", _ourhistory},
		{"setenv", _oursetenv},
		{"unsetenv", _ourunsetenv},
		{"cd", _wecd},
		{"alias", _ouralias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_int_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cm - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cm(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
                info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = path_find(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cm(info);
	}
	else
	{
		if ((interact(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cm(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			write_error(info, "not found\n");
		}
	}
}

/**
 * fork_cm - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cm(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_str_env(info)) == -1)
		{
			info_free(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		} 
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				write_error(info, "Permission denied\n");
		}
	}
}
