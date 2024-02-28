#include "shell.h"

/**
 * ft_is_cmd - determines if a file is an executable command
 * @info: struct
 * @path: path to the file
 * Return: int
 */
int ft_is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * ft_dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char *ft_dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
	if (pathstr[i] != ':')
		buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * ft_find_path - finds this cmd in the PATH str
 * @info: struct
 * @pathstr: str path
 * @cmd: cmd to find
 * Return: str
 */
char *ft_find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((ft_strlen(cmd) > 2) && check_start_with(cmd, "./"))
	{
		if (ft_is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = ft_dup_chars(pathstr, curr_pos, i);
			if (!*path)
				ft_strcat(path, cmd);
			else
			{
				ft_strcat(path, "/");
				ft_strcat(path, cmd);
			}
			if (ft_is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
