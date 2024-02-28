#include "shell.h"

/**
 * ft_get_history_file - gets the history file
 * @info: struct
 * Return: str
 */

char *ft_get_history_file(info_t *info)
{
	char *buff, *dir;

	dir = ft_getenv(info, "HOME=");
	if (!dir)
	return (NULL);
	buff = malloc(sizeof(char) * (ft_strlen(dir) + ft_strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	ft_strcpy(buff, dir);
	ft_strcat(buff, "/");
	ft_strcat(buff, HIST_FILE);
	return (buff);
}



/**
 * ft_write_history - creates a file
 * @info: struct
 * Return: int
 */
int ft_write_history(info_t *info)
{
	ssize_t fd;
	char *filename = ft_get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		ft_putsfd(node->str, fd);
		ft_putfd('\n', fd);
	}
	ft_putfd(BUFF_FLUSH, fd);
	close(fd);
	return (1);
}



/**
 * ft_read_history - reads history from file
 * @info: struct
 * Return: int
 */
int ft_read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = ft_get_history_file(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			ft_build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		ft_build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		ft_delete_node_at_index(&(info->history), 0);
	ft_renumber_history(info);
	return (info->histcount);
}


/**
 * ft_build_history_list - adds entry to a history
 * @info: Structure
 * @buf: buffer
 * @linecount: the history linecount
 * Return: int
 */
int ft_build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
	node = info->history;
	ft_add_node_end(&node, buf, linecount);

	if (!info->history)
	info->history = node;
	return (0);
}



/**
 * ft_renumber_history - renumbers the history
 * @info: Structure
 * Return: int
 */
int ft_renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
