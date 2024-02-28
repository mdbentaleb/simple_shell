#include "shell.h"


/**
 * ft_myenv - prints the current environment
 * @info: Structure containing potential arguments
 * Return: int
 */
int ft_myenv(info_t *info)
{
	ft_print_list_str(info->env);
	return (0);
}


/**
 * ft_getenv - gets the value of an environ variable
 * @info: Structure
 * @name: env var name
 * Return: the value
 */
char *ft_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pt;

	while (node)
	{
		pt = starts_with(node->str, name);
		if (pt && *p)
			return (pt);
		node = node->next;
	}
	return (NULL);
}


/**
 * ft_mysetenv - Initialize a new environment variable
 * @info: Structure
 * Return: Always 0
 */
int ft_mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		ft_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (ft_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


/**
 * ft_myunsetenv - Remove an environment variable
 * @info: Structure
 * Return: Always 0
 */
int ft_myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		ft_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		ft_unsetenv(info, info->argv[i]);
	return (0);
}


/**
 * ft_populate_env_list - populates env linked list
 * @info: Structure
 * Return: Always 0
 */
int ft_populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ft_add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
