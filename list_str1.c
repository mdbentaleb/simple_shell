#include "shell.h"

/**
 * ft_add_node - adds a node
 * @head: address of pointer to head node
 * @str: str
 * @num: node index
 * Return: size of list
 */
list_t *ft_add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	ft_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = ft_strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}


/**
 * ft_add_node_end - adds a node to the end
 * @head: address of pointer to head node
 * @str: str
 * @num: node index
 * Return: size of list
 */
list_t *ft_add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	ft_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = ft_strdup(str);
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
		*head = new_node;
	return (new_node);
}


/**
 * ft_print_list_str - prints the str element
 * @h: pointer to first node
 * Return: size of list
 */
size_t ft_print_list_str(const list_t *h)
{
	size_t index = 0;

	while (h)
	{
		ft_putstr(h->str ? h->str : "(nil)");
		ft_putstr("\n");
		h = h->next;
		index++;
	}
	return (index);
}


/**
 * ft_delete_node_at_index - deletes node
 * @head: address of pointer to first node
 * @index: index of node
 * Return: int
 */
int ft_delete_node_at_index(list_t **head, unsigned int index)
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
 * ft_free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 * Return: void
 */
void ft_free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
