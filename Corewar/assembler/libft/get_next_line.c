/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:47:39 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/16 14:34:09 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		if_n(char **tmp, char **line)
{
	if ((*tmp = ft_strchr(*line, '\n')))
	{
		(*tmp)[0] = '\0';
		*tmp = ft_strdup((*tmp) + 1);
		return (1);
	}
	return (0);
}

int		f_read(int fd, char **tmp, char **line)
{
	int		res;
	char	buf[BUFF_SIZE + 1];

	ft_bzero((char*)buf, BUFF_SIZE + 1);
	if ((if_n(tmp, line)))
		return (1);
	while ((res = read(fd, buf, BUFF_SIZE)) != -1 && res != 0)
	{
		(*tmp) = (*line);
		*line = ft_strjoin(*line, buf);
		free(*tmp);
		if ((if_n(tmp, line)))
			return (1);
		ft_bzero((char*)buf, BUFF_SIZE + 1);
	}
	if ((*line) && (*line)[0])
		return (1);
	return (res);
}

t_line	*to_lst(int fd, t_line *c_file, t_line **c_fd)
{
	if (!c_file)
	{
		c_file = (t_line*)malloc(sizeof(t_line));
		c_file->buf = 0;
		c_file->fd = fd;
		c_file->next = *c_fd;
		*c_fd = c_file;
	}
	return (c_file);
}

int		get_next_line(const int fd, char **line)
{
	t_line			*c_file;
	static t_line	*c_fd = NULL;

	if (fd < 0 || (read(fd, NULL, 0)) < 0)
		return (-1);
	if (!c_fd)
	{
		c_fd = (t_line*)malloc(sizeof(t_line));
		c_fd->buf = 0;
		c_fd->fd = fd;
		c_fd->next = 0;
	}
	c_file = c_fd;
	while (c_file && c_file->fd != fd)
		c_file = c_file->next;
	c_file = to_lst(fd, c_file, &c_fd);
	*line = c_file->buf == 0 ? ft_strdup("\0") : c_file->buf;
	return (f_read(fd, &c_file->buf, line));
}
