/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:58:09 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/06 16:22:54 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	get_map_height_and_width(char *str, t_mvar *mvr)
{
	VAR_INT(i, 0);
	VAR_INT(temp, 0);
	while (str[i])
	{
		while (str[i] != '\n' && str[i])
		{
			while (str[i] == ' ')
				i++;
			while (str[i] != ' ' && str[i] != '\n' && str[i])
				i++;
			mvr->map_width++;
		}
		if (!temp)
			temp = mvr->map_width;
		if (temp != mvr->map_width)
			put_error("Invalid map at:\n", str + i);
		mvr->map_width = 0;
		mvr->map_height++;
		if (str[i])
			i++;
	}
	mvr->map_width = temp;
}

static inline void	validate_map(t_var var)
{
	t_mvar mvr;

	VAR_INT(i, 0);
	mvr.map_width = 0;
	mvr.map_height = 0;
	while (var.str[i + 1])
	{
		if (var.str[i] == '\n' && var.str[i + 1] == '\n')
			put_error("Invalid map at:\n", var.str + i);
		i++;
	}
	get_map_height_and_width(var.str, &mvr);
	get_map(&var, &mvr);
	free(var.str);
	create_sprite_map(&var, &mvr);
	var.mvr = mvr;
	fill_var(var);
}

static inline void	validate_file(t_var var)
{
	VAR_INT(i, 0);
	while (var.str[i])
	{
		while (var.str[i] != '\n' && var.str[i])
		{
			while (var.str[i] == ' ')
				i++;
			if (!(var.str[i] >= '0' && var.str[i] <= '2') &&
				var.str[i] != 'b' && var.str[i] != 'c' && var.str[i] != 'd' &&
				var.str[i] != 'f' && var.str[i] != 'l' && var.str[i] != 'p' &&
				var.str[i] != ',' && var.str[i] != 's' && var.str[i])
				put_error("Invalid map at:\n", var.str + i);
			else
				i++;
		}
		if (var.str[i])
			i++;
	}
	validate_map(var);
}

void				read_file(char *file)
{
	char	buff[1024];
	t_var	var;

	VAR_INT(fd, 0);
	VAR_INT(file_size, 0);
	VAR_INT(bytes, 0);
	if ((fd = open(file, O_RDONLY)) < 0 || (read(fd, buff, 0)) < 0)
		put_error("Invalid file: ", file);
	while ((bytes = read(fd, buff, 1023)))
		file_size += bytes;
	if (!file_size)
		put_error("Empty file\n", 0);
	close(fd);
	var.str = (char*)malloc(file_size + 1);
	fd = open(file, O_RDONLY);
	read(fd, var.str, file_size);
	close(fd);
	var.str[file_size] = '\0';
	validate_file(var);
}
