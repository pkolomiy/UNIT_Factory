/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:21:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/19 21:28:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void			compare(t_fil *f, unsigned char y, unsigned char x)
{
	unsigned char	i;
	unsigned char	j;
	unsigned short	sum;

	i = 0;
	sum = 0;
	while (i < f->fig_y)
	{
		j = 0;
		while (j < f->fig_x)
		{
			sum += f->dist_enemy[y + i][x + j];
			j++;
		}
		i++;
	}
	if (!f->sum || sum < f->sum)
	{
		f->sum = sum;
		f->x = x;
		f->y = y;
	}
}

static void			try(t_fil *f, unsigned char y, unsigned char x)
{
	unsigned char	i;
	unsigned char	j;
	unsigned char	flag;

	i = 0;
	flag = 0;
	while (i < f->fig_y)
	{
		j = 0;
		while (j < f->fig_x)
		{
			if (f->figure[i][j] == '*' && f->map[y + i][x + 4 + j] == f->enemy)
				return ;
			if (f->figure[i][j] == '*' && f->map[y + i][x + 4 + j] == f->me)
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 1)
		compare(f, y, x);
}

static inline void	nbr(unsigned char i)
{
	if (i >= 10)
		nbr(i / 10);
	if (i >= 10)
		nbr(i % 10);
	if (i < 10)
	{
		i += 48;
		write(1, &i, 1);
	}
}

static void			calculate(t_fil *f)
{
	unsigned char	i;
	unsigned char	j;

	f->x = 0;
	f->y = 0;
	f->sum = 0;
	i = 0;
	while (i < f->map_y)
	{
		j = 0;
		while (j < f->map_x)
		{
			if (j + f->fig_x <= f->map_x && i + f->fig_y <= f->map_y)
				try(f, i, j);
			j++;
		}
		i++;
	}
	nbr(f->y);
	write(1, " ", 1);
	nbr(f->x);
	write(1, "\n", 1);
}

int					main(void)
{
	t_fil			f;
	char			*str;
	unsigned char	i;

	get_next_line(0, &str);
	f.me = (str[10] == '1') ? 'O' : 'X';
	f.enemy = (f.me == 'O') ? 'X' : 'O';
	get_next_line(0, &str);
	i = 7;
	f.map_x = 0;
	while (str[++i] != ':')
	{
		if (str[i] == ' ' && (f.map_y = f.map_x))
			f.map_x = 0;
		else
			f.map_x = (f.map_x * 10) + (str[i] - 48);
	}
	f.flag = 0;
	while ((get_next_line(0, &str)) > 0)
	{
		read_map_and_piece(&f);
		make_distance_map(&f);
		calculate(&f);
	}
	return (0);
}
