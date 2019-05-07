/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:00:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/07 16:00:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(t_gnl *gnl, char **line)
{
	size_t	len;

	if (gnl->start == NULL)
		return (0);
	len = gnl->middle - gnl->start;
	*line = (char *)malloc(len + 1);
	(*line)[len] = '\0';
	if (len)
	{
		while (--len)
			(*line)[len] = gnl->start[len];
		(*line)[len] = gnl->start[len];
	}
	if (gnl->middle == gnl->end ||
		gnl->middle + 1 == gnl->end)
	{
		free(gnl->start);
		gnl->start = NULL;
	}
	else
		gnl->middle++;
	return (1);
}

static void	join(t_gnl *gnl, const char *buff, size_t buff_len)
{
	char	*temp;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl->start ? gnl->end - gnl->start : 0;
	temp = (char*)malloc(len + buff_len + 1);
	while (i < len || i < buff_len)
	{
		if (gnl->start && i < len)
			temp[i] = gnl->start[i];
		if (i < buff_len)
			temp[i + len] = buff[i];
		i++;
	}
	temp[len + buff_len] = '\0';
	gnl->middle = temp + (gnl->start ? gnl->middle - gnl->start : 0);
	if (gnl->start)
		free(gnl->start);
	gnl->start = temp;
	gnl->end = temp + len + buff_len;
}

static int	reading(t_gnl *gnl, int fd, char **line)
{
	char	*buff;
	ssize_t	buff_len;

	buff = (char*)malloc(BUFF_SIZE + 1);
	while (1)
	{
		while (gnl->start && gnl->middle != gnl->end && *gnl->middle != '\n')
			gnl->middle++;
		if (gnl->start && *gnl->middle == '\n')
			break ;
		if ((buff_len = read(fd, (void*)buff, BUFF_SIZE)) <= 0)
			break ;
		buff[buff_len] = '\0';
		join(gnl, buff, buff_len);
	}
	free(buff);
	return (get_line(gnl, line));
}

int			get_next_line(int fd, char **line)
{
	static t_gnl	gnl = (t_gnl){NULL, NULL, NULL};

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (gnl.start != NULL)
	{
		gnl.end = gnl.start;
		while (*gnl.middle)
		{
			*gnl.end = *gnl.middle;
			gnl.middle++;
			gnl.end++;
		}
		*gnl.end = '\0';
		gnl.middle = gnl.start;
	}
	return (reading(&gnl, fd, line));
}
