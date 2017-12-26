/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:57:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 21:59:45 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_ways(t_lem *l)
{
	t_way	*cur;
	t_way	*prev;

	cur = l->ways;
	prev = NULL;
	while (cur)
	{
		if (cur->rooms->level)
		{
			del_way(l, &cur, &prev);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void	prepare(t_way *ways)
{
	t_rooms	*rooms;

	while (ways)
	{
		rooms = ways->rooms;
		while (rooms)
		{
			rooms->ant = 0;
			rooms = rooms->next;
		}
		ways = ways->next;
	}
}

int		count_ways(t_way *ways)
{
	int	i;

	i = 0;
	while (ways)
	{
		i++;
		ways = ways->next;
	}
	return (i);
}

void	show_ways(t_way *ways)
{
	t_rooms	*tmp;

	write(1, "\n", 1);
	while (ways)
	{
		tmp = ways->rooms;
		while (tmp)
		{
			write(1, "\e[37;1m[\e[0m\e[33;1m", 19);
			write(1, tmp->name, len(tmp->name));
			write(1, "\e[0m\e[37;1m]\e[0m", 16);
			if (tmp->level != -1)
				write(1, "\e[34;1m -> \e[0m", 15);
			tmp = tmp->next;
		}
		write(1, "\n", 1);
		ways = ways->next;
	}
}
