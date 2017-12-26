/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:56:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 22:01:53 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

_Bool	fill_ant(t_way *ways, unsigned ant)
{
	while (ways)
	{
		if (!ways->rooms->next->ant)
		{
			ways->rooms->next->ant = ant;
			return (1);
		}
		ways = ways->next;
	}
	return (0);
}

_Bool	move_ants(t_way *ways)
{
	t_rooms		*rooms;
	unsigned	i;
	_Bool		flag;

	flag = 0;
	while (ways)
	{
		i = 0;
		rooms = ways->rooms;
		while ((rooms = rooms->next))
		{
			rooms->ant ^= i;
			i ^= rooms->ant;
			rooms->ant ^= i;
			if (rooms->ant)
				flag = 1;
		}
		ways = ways->next;
	}
	return (flag);
}

void	draw(t_rooms *rooms, char *arr[])
{
	while ((rooms = rooms->next))
	{
		if (rooms->ant)
		{
			write(1, arr[rooms->ant % 7], 7);
			write(1, "L", 1);
			nbr(rooms->ant);
			write(1, "-", 1);
			write(1, rooms->name, len(rooms->name));
			write(1, arr[7], 4);
			write(1, " ", 1);
		}
	}
}

_Bool	draw_ants(t_way *ways, char *arr[], _Bool stat)
{
	_Bool	flag;
	t_way	*tmp;

	flag = 0;
	tmp = ways;
	while (stat && tmp)
	{
		if (!tmp->rooms->next->ant)
			flag = 1;
		tmp = tmp->next;
	}
	if (!flag)
	{
		while (ways)
		{
			draw(ways->rooms, arr);
			ways = ways->next;
		}
		write(1, "\n", 1);
	}
	return (flag);
}

void	print(t_lem *l)
{
	char		*arr[8];
	unsigned	count;

	count = 0;
	colors(arr);
	write(1, "\n", 1);
	while (++count)
	{
		if (!fill_ant(l->ways, count))
			move_ants(l->ways);
		if (!draw_ants(l->ways, arr, 1))
			move_ants(l->ways);
		if (count == l->ants)
		{
			draw_ants(l->ways, arr, 0);
			break ;
		}
	}
	while (move_ants(l->ways))
		draw_ants(l->ways, arr, 0);
}
