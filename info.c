#include "shell.h"

/**
 * info_clear - initializes info_t struct
 * @info: struct address
 */
void info_clear(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * info_set - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void info_set(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strsup(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		rep_alias_tkz(info);
		rep_vars_tkz(info);
	}
}

/**
 * info_free - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void info_free(info_t *info, int all)
{
	xfree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			list_free(&(info->env));
        	if (info->history)
			list_free(&(info->history));
		if (info->alias)
			list_free(&(info->alias));
		xfree(info->environ);
			info->environ = NULL;
		ptrfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
