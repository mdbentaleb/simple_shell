#include "shell.h"

/**
 * ft_list_len - determines length
 * @h: pointer to first node
 * Return: int
 */
size_t ft_list_len(const list_t *h)
{
	size_t index = 0;

	while (h)
	{
		h = h->next;
		index++;
	}
	return (index);
}


/**
 * ft_list_to_strings - returns an array of strings
 * @head: pointer to first node
 * Return: array
 */
char **ft_list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(ft_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = ft_strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * ft_print_list - prints all elements of a list
 * @h: pointer to first node
 * Return: int
 */
size_t ft_print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		ft_putstr(convert_number(h->num, 10, 0));
		ft_putchar(':');
		ft_putchar(' ');
		ft_putstr(h->str ? h->str : "(nil)");
		ft_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}


/**
 * ft_node_starts_with - returns node
 * @node: pointer to list head
 * @prefix: string
 * @c: the next character
 * Return: match node or null
 */
list_t *ft_node_starts_with(list_t *node, char *prefix, char c)
{
	char *a = NULL;

	while (node)
	{
		a = starts_with(node->str, prefix);
		if (a && ((c == -1) || (*a == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


/**
 * ft_get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1
 */
ssize_t ft_get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
