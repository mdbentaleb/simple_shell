#include "shell.h"

/**
 * ft_eputs - prints string
 * @str: str
 * Return: void
 */
void ft_eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		ft_eputchar(str[i]);
		i++;
	}
}


/**
 * ft_eputchar - writes character
 * @c: char
 * Return: int
 */
int ft_eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buf[i++] = c;
	return (1);
}


/**
 * ft_putfd - writes character c
 * @c: char
 * @fd: filedescriptor
 * Return: int
 */
int ft_putfd(char c, int fd)
{
	static int i;
	static char buff[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(fd, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}


/**
 * ft_putsfd - prints an input string
 * @str: str
 * @fd: filedescriptor
 * Return: int
 */
int ft_putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += ft_putfd(*str++, fd);
	}
	return (i);
}
