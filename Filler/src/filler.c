/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 21:21:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/19 21:29:54 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned char	get_min(t_fil *f, unsigned char y, unsigned char x)
{
	short	min[2];
	short	i;
	short	j;

	i = -1;
	min[1] = -1;
	while (++i < f->map_y)
	{
		j = -1;
		while (++j < f->map_x)
		{
			if (f->enemy_buf[i][j])
			{
				min[0] = (y - i) < 0 ? -(y - i) : (y - i);
				min[0] += ((x - j) < 0 ? -(x - j) : (x - j));
				if (min[1] < 0)
					min[1] = min[0];
				else if (min[0] < min[1])
					min[1] = min[0];
			}
		}
	}
	return ((unsigned char)min[1]);
}

static void				continue_making_distance_map(t_fil *f)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	while (i < f->map_y)
	{
		j = 0;
		while (j < f->map_x)
		{
			f->dist_enemy[i][j] = get_min(f, i, j);
			j++;
		}
		i++;
	}
}

void					make_distance_map(t_fil *f)
{
	short	i;
	short	j;

	if (!f->flag)
	{
		f->dist_enemy = (unsigned char**)malloc(sizeof(char *) * f->map_y);
		f->enemy_buf = (unsigned char**)malloc(sizeof(char *) * f->map_y);
	}
	i = -1;
	while (++i < f->map_y)
	{
		if (!f->flag)
		{
			f->dist_enemy[i] = (unsigned char*)malloc(f->map_x);
			f->enemy_buf[i] = (unsigned char*)malloc(f->map_x);
		}
		j = -1;
		while (++j < f->map_x)
			f->enemy_buf[i][j] = (f->map[i][j + 4] == f->enemy) ? 1 : 0;
	}
	if (!f->flag)
		f->flag = 1;
	continue_making_distance_map(f);
}

static inline void		read_arr(char **arr, unsigned char i)
{
	unsigned char	j;

	j = 0;
	while (1)
	{
		i--;
		get_next_line(0, &arr[j]);
		j++;
		if (!i)
			break ;
	}
}

void					read_map_and_piece(t_fil *f)
{
	char			*str;
	unsigned char	i;
	unsigned char	j;

	f->flag ? get_next_line(0, &str) : 0;
	i = f->map_y;
	f->map = (char**)malloc(sizeof(char*) * i);
	read_arr(f->map, i);
	get_next_line(0, &str);
	i = 5;
	j = 0;
	while (str[++i] != ' ')
		j = (j * 10) + (str[i] - 48);
	f->figure = (char**)malloc(sizeof(char*) * j);
	read_arr(f->figure, j);
	f->fig_y = j;
	f->fig_x = 0;
	while (f->figure[0][f->fig_x])
		f->fig_x++;
}
