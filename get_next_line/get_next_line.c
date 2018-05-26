/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:52:10 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/05/26 17:54:25 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	join(t_gnl *lst, const char *buff, int bytes)
{
	int		i;
	int		j;
	char	*new_str;

	i = -1;
	j = 0;
	lst->len = lst->end - lst->start;
	new_str = (char*)malloc(lst->len + bytes + 1);
	while (++i < lst->len)
		*(new_str + i) = *(lst->str + lst->start + i);
	while (j < bytes)
	{
		*(new_str + i) = *(buff + j);
		i++;
		j++;
	}
	*(new_str + i) = '\0';
	lst->end -= lst->start;
	lst->len += bytes;
	lst->start = 0;
	free(lst->str);
	lst->str = new_str;
}

static int	reading(t_gnl *lst, char **buffer)
{
	int	bytes_read;

	while (lst->str && *(lst->str + lst->end))
	{
		if (*(lst->str + lst->end) == '\n')
			return (0);
		lst->end++;
	}
	if (*buffer == NULL)
		if (!(*buffer = (char*)malloc(BUFF_SIZE + 1)))
			return (-1);
	if (!(bytes_read = read(lst->fd, *buffer, BUFF_SIZE)))
		return (0);
	if (lst->str == NULL)
	{
		(*buffer)[bytes_read] = '\0';
		lst->str = *buffer;
		*buffer = NULL;
		lst->len = bytes_read;
	}
	else
		join(lst, *buffer, bytes_read);
	return (1);
}

static int	final_check(t_gnl *lst)
{
	if (lst->end != lst->len)
		lst->end++;
	lst->start = lst->end;
	if (lst->end == lst->len)
	{
		free(lst->str);
		lst->str = NULL;
		lst->start = 0;
		lst->end = 0;
		lst->len = 0;
	}
	return (1);
}

static int	processing(t_gnl *lst, char **line)
{
	int		i;
	char	*buff;

	buff = NULL;
	while ((i = reading(lst, &buff)) != 0)
		if (i == -1)
			return (i);
	if (buff)
		free(buff);
	if (lst->str)
	{
		if (!(*line = (char*)malloc(lst->end - lst->start + 1)))
			return (-1);
		while (i < lst->end - lst->start)
		{
			*((*line) + i) = *(lst->str + lst->start + i);
			i++;
		}
		*((*line) + i) = '\0';
		return (final_check(lst));
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*temp;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	temp = list;
	while (temp)
	{
		if (temp->fd == fd)
			return (processing(temp, line));
		temp = temp->next;
	}
	if (!(temp = (t_gnl*)malloc(sizeof(t_gnl))))
		return (-1);
	temp->fd = fd;
	temp->start = 0;
	temp->end = 0;
	temp->len = 0;
	temp->str = NULL;
	temp->next = list;
	list = temp;
	return (processing(temp, line));
}
