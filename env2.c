#include "shell.h"


/**
 * ft_get_environ - returns the string array copy of our environ
 * @info: Structure
 * Return: int
 */
char **ft_get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = ft_list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}


/**
 * ft_unsetenv - Remove an environment variable
 * @info: Structure
 * Return: int
 * @var: the string env var property
 */
int ft_unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *pt;

	if (!node || !var)
		return (0);
	while (node)
	{
		pt = starts_with(node->str, var);
		if (pt && *pt == '=')
		{
			info->env_changed = ft_delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}


/**
 * ft_setenv - Initialize a new environment variable
 * @info: Structure
 * @var: the string env var property
 * @value: the string env var value
 * Return: int
 */
int ft_setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *pt;

	if (!var || !value)
		return (0);
	buff = malloc(ft_strlen(var) + ft_strlen(value) + 2);
	if (!buff)
		return (1);
	ft_strcpy(buff, var);
	ft_strcat(buff, "=");
	ft_strcat(buff, value);
	node = info->env;
	while (node)
	{
		pt = starts_with(node->str, var);

		if (pt && *pt == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	ft_add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
