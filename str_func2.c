#include "shell.h"

/**
 * ft_strcpy - copies a string
 * @dest: the destination
 * @src: Source string for copying
 * Return: pointer to destination
 */
char *ft_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src == 0 || dest == src)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



/**
 * ft_strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to duplicated string
 */
char *ft_strdup(const char *str)
{
	char *dest;
	int len, i;

	if (str == NULL)
		return (NULL);

	len = ft_strlen(str);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}



/**
 * ft_putstr - prints the input string
 * @str: the string to be printed
 * Return: void
 */
void ft_putstr(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}



/**
 * ft_putchar - display characters in standard output
 * @c: the char to print
 * Return: int
 */
int ft_putchar(char c)
{
	static int i;
	static char buff[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}
