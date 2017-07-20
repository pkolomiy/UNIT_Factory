/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:19:27 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/07/21 00:58:42 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		search_or_strlen(char *str, int action, int *index)
{
	int		nbr;

	nbr = 0;
	if (action == SEARCH_NEWLINE)
	{
		while (str && str[(*index)])
		{
			if (str[(*index)] == '\n')
				return (1);
			(*index)++;
		}
	}
	else if (action == STRING_LENGTH)
	{
		while (str[nbr])
			nbr++;
		return (nbr);
	}
	return (0);
}

char	*copy_or_crop_string(char *str, int action, int nbr)
{
	int		index;
	char	*temp;

	index = -1;
	temp = 0;
	if (action == MAKE_A_COPY)
	{
		temp = (char*)malloc(nbr + 1);
		while (++index != nbr)
			temp[index] = str[index];
		temp[index] = '\0';
	}
	else if (action == CROP_STRING && str[0] && str[nbr])
	{
		temp = (char*)malloc(search_or_strlen(str, STRING_LENGTH, 0) - nbr + 1);
		while (str[++nbr])
			temp[++index] = str[nbr];
		temp[++index] = '\0';
	}
	return (temp);
}

char	*join(char *str, char *temp, int nbr)
{
	char	*newstr;
	int		index;
	int		other_index;

	if (!str)
		return (copy_or_crop_string(temp, MAKE_A_COPY, nbr));
	newstr = (char*)malloc(search_or_strlen(str, STRING_LENGTH, 0) +
						search_or_strlen(temp, STRING_LENGTH, 0) + 1);
	index = 0;
	other_index = 0;
	while (str[index])
	{
		newstr[index] = str[index];
		index++;
	}
	while (other_index != nbr)
	{
		newstr[index] = temp[other_index];
		other_index++;
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}

int		reading(t_var var, char **line)
{
	var.index = 0;
	while (!(search_or_strlen(var.lst->str, SEARCH_NEWLINE, &var.index)) &&
		(var.nbr = read(var.lst->fd, var.buff, BUFF_SIZE)))
	{
		var.temp = var.lst->str;
		var.lst->str = join(var.temp, var.buff, var.nbr);
		if (var.temp)
			free(var.temp);
	}
	if (var.lst->str)
	{
		var.nbr = 0;
		while (var.lst->str[var.nbr] != '\n' && var.lst->str[var.nbr])
			var.nbr++;
		*line = copy_or_crop_string(var.lst->str, MAKE_A_COPY, var.nbr);
		var.first_char = var.lst->str[0];
		var.temp = var.lst->str;
		var.lst->str = copy_or_crop_string(var.temp, CROP_STRING, var.nbr);
		free(var.temp);
		if (*line[0] || var.first_char == '\n')
			return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*lst = 0;
	t_var			var;

	var.lst = lst;
	if (fd < 0 || read(fd, var.buff, 0) < 0)
		return (-1);
	while (var.lst)
	{
		if (var.lst->fd == fd)
			return (reading(var, line));
		var.lst = var.lst->next;
	}
	if (!(var.lst = (t_lst*)malloc(sizeof(t_lst))))
		return (-1);
	var.lst->fd = fd;
	var.lst->str = 0;
	var.lst->next = lst;
	lst = var.lst;
	return (reading(var, line));
}
