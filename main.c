#include "shell.h"

/**
 * main - entry point
 * @arc: arguments count
 * @arv: arguments vector
 * Return: int
 */
int main(int arc, char **arv)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				ft_eputs(av[0]);
				ft_eputs(": 0: Can't open ");
				ft_eputs(av[1]);
				ft_eputchar('\n');
				ft_eputchar(BUFF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
