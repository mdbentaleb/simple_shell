#include "shell.h"

/**
 * ft_memset - fills memory
 * @s: the pointer to the memory
 * @b: char to fill *s
 * @n: number of bytes to be filled
 * Return: pointer to the memory area
 */
char *ft_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}


/**
 * ft_memfree - frees a string of strings
 * @str: string of strings
 * Return: void
 */
void ft_memfree(char **str)
{
	char **pt = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(pt);
}


/**
 * ft_realloc - reallocates memory
 * @ptr: pointer to previous mallocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to the old block.
 */
void *ft_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pt;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pt = malloc(new_size);
	if (!pt)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pt[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pt);
}
