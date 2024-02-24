#include "shell.h"


/**
 * **ft_strtow - splits a string into words
 * @str: input str
 * @d: delimeter
 * Return: a pointer to an array of strings
 */

char **ft_strtow(char *str, char *d)
{
	int i, j, k, m, count = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!ft_isdelim(str[i], d) && (ft_isdelim(str[i + 1], d) || !str[i + 1]))
			count++;

	if (count == 0)
		return (NULL);
	s = malloc((1 + count) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < count; j++)
	{
		while (ft_isdelim(str[i], d))
			i++;
		k = 0;
		while (!ft_isdelim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **ft_strtow2 - splits a string into words
 * @str: input str
 * @d: delimeter
 * Return: a pointer to an array of strings
 */
char **ft_strtow2(char *str, char d)
{
	int i, j, k, m, count = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			count++;
	if (count == 0)
		return (NULL);
	s = malloc((1 + count) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < count; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
