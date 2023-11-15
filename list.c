#include "shell.h"

/**
 * length_list - count  length of linked list
 * @ptr: first node pointer
 * Return: size of list
 */
size_t length_list(const list_t *ptr)
{
	size_t i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/**
 * strings_list - returns an array of strings of the list->str
 * @h: pointer to first node
 *
 * Return: array of strings
 */
char **strings_list(list_t *h)
{
	list_t *node = h;
	size_t i = length_list(h), j;
	char **strs;
	char *str;

	if (!h || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * write_list - pri1nts all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t write_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * starts_node_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *starts_node_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * node_index - gets the index of a node
 * @h: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t node_index(list_t *h, list_t *node)
{
	size_t i = 0;

	while (h)
	{
		if (h == node)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}
