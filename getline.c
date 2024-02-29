#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: struct
 * @buf: address of buffer
 * @len: address of len var
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, ft_sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = ft_getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			ft_remove_comments(*buf);
			ft_build_history_list(info, *buf, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}



/**
 * get_input - gets a line minus the newline
 * @info: struct
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	ft_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;
		ft_check_chain(info, buf, &j, i, len);

		while (j < len)
		{
			if (ft_is_chain(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (ft_strlen(p));
	}
	*buf_p = buf;
	return (r);
}



/**
 * read_buf - reads a buffer
 * @info: struct
 * @buf: buffer
 * @i: size
 * Return: int
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUFF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}



/**
 * ft_getline - gets the next line of input
 * @info: struct
 * @ptr: address of pointer to buffer
 * @length: size of preallocated ptr buffer
 * Return: int
 */
int ft_getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUFF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;
	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
	return (-1);
	c = ft_strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = ft_realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		ft_strncat(new_p, buf + i, k - i);
	else
		ft_strncpy(new_p, buf + i, k - i + 1);
	s += k - i;
	i = k;
	p = new_p;
	if (length)
	*length = s;
	*ptr = p;
	return (s);
}



/**
 * ft_sigintHandler - blocks ctrl-C
 * @sig_num: number
 * Return: void
 */
void ft_sigintHandler(__attribute__((unused))int sig_num)
{
	ft_puts("\n");
	ft_puts("$ ");
	ft_putchar(BUFF_FLUSH);
}
