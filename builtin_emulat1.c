#include "shell.h"


/**
 * ft_myexit - exits the shell
 * @info: Structure
 * Return: int
 */
int ft_myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = ft_erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			ft_print_error(info, "Illegal number: ");
			ft_eputs(info->argv[1]);
			ft_eputchar('\n');
			return (1);
		}
		info->err_num = ft_erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}



/**
 * ft_mycd - changes the current directory of the process
 * @info: Structure
 * Return: Always 0
 */
int ft_mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		ft_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = ft_getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = ft_getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (ft_strcmp(info->argv[1], "-") == 0)
	{
		if (!ft_getenv(info, "OLDPWD="))
		{
			ft_puts(s);
			ft_putchar('\n');
			return (1);
		}
		ft_puts(ft_getenv(info, "OLDPWD=")), ft_putchar('\n');
		chdir_ret =
			chdir((dir = ft_getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		ft_print_error(info, "can't cd to ");
		ft_eputs(info->argv[1]), ft_eputchar('\n');
	}
	else
	{
		ft_setenv(info, "OLDPWD", ft_getenv(info, "PWD="));
		ft_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * ft_myhelp - changes the current directory of the process
 * @info: Structure
 * Return: int
 */
int ft_myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	ft_puts("help call works. Function not yet implemented \n");
	if (0)
		ft_puts(*arg_array);
	return (0);
}
