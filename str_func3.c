#include "shell.h"

/**
 * ft_strncpy - copies a string
 * @dest: the destination to which the copy will be made
 * @src: the source string
 * @n: number of chars to be copied
 * Return: the concatenated string
 */
char ft_strncpy(char *dest, char *src, int n)
{
	char *str = dest;
	int i, j;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}

	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}



/**
 * ft_strncat - concatenates 2 strs
 * @dest: first string
 * @src: second string
 * @n: int
 * Return: the concatenated string
 */
char *ft_strncat(char *dest, char *src, int n)
{
	char *str = dest;
	int i, j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		des[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (str);
}



/**
 * ft_strchar - locates a char in astring
 * @str: string
 * @c: char
 * Return: pointer to str
 */
char *ft_strchar(char *str, char c)
{
	di {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
