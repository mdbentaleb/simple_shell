#include "shell.h"

/**
 * ft_bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 * Return: int
 */
int ft_bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
