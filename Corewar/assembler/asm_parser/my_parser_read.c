/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:22:12 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:24:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void		ft_get_next_line_loop(char *line, int z, t_file *a_cop)
{
	t_file	*creat;

	creat = malloc(sizeof(t_file));
	creat->line = malloc(ft_strlen(line) + 1);
	creat->next = NULL;
	ft_strcpy(creat->line, line);
	creat->num = z;
	free(line);
	while (a_cop->next != NULL)
		a_cop = a_cop->next;
	a_cop->next = creat;
	a_cop = a_cop->next;
	a_cop->next = NULL;
}

t_file		*reader(char *name, int fd)
{
	char	*line;
	t_file	*a;
	t_file	*a_cop;
	int		z;

	a = malloc(sizeof(t_file));
	a_cop = a;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	get_next_line(fd, &line);
	a_cop->line = malloc(ft_strlen(line) + 1);
	a_cop->next = NULL;
	ft_strcpy(a_cop->line, line);
	free(line);
	z = 1;
	while (get_next_line(fd, &line))
	{
		ft_get_next_line_loop(line, z, a_cop);
		z++;
	}
	free(line);
	close(fd);
	return (a);
}
