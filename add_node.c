#include "shell.h"

/**
 * node_add - add node
 * @h: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *node_add(list_t **h, const char *str, int num)
{
	list_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * node_add_end - adds a node to the end of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *node_add_end(list_t **h, const char *str, int num)
{
	list_t *new_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*h = new_node;
	return (new_node);
}

/**
 * write_str_list - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t write_str_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * remove_index_node - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int remove_index_node(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * list_free - free all nodes of a list
 * @h_ptr: address of pointer to head node
 *
 * Return: void
 */
void list_free(list_t **h_ptr)
{
	list_t *node, *next_node, *h;

	if (!h_ptr || !*h_ptr)
		return;
	h = *h_ptr;
	node = h;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*h_ptr = NULL;
}
