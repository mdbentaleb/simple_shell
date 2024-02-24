#include "shell.h"


/**
 * ft_interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int ft_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * ft_isdelim - checks delimeter
 * @c: the char to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int ft_isdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}


/**
 * ft_isalpha - checks alphabetic character
 * @c: the input char
 * Return: 1 if c is alphabetic, otherwise 0
 */
int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1)
	else
		return (0);
}


/**
 * ft_atoi - converts string to integer
 * @str: string
 * Return: int
 */

int ft_atoi(char *str)
{
	int i;
	int sign = 1;
	int flag = 0;
	int output;
	unsigned int result = 0;

	for (i = 0;  str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
