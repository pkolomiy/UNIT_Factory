/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 15:16:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 22:33:58 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

_Bool	compare(t_rooms *rooms, t_way *ways)
{
	t_rooms	*tmp;
	t_rooms	*tmp2;

	while (ways)
	{
		tmp = ways->rooms->next;
		tmp2 = rooms->next;
		while (tmp2->level != -1 && tmp->level != -1)
		{
			if (cmp(tmp2->name, tmp->name))
				return (0);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		ways = ways->next;
	}
	return (1);
}

_Bool	find_unique(t_way *main, t_ways *ways)
{
	t_way	*tmp;

	while (main)
	{
		if (compare(main->rooms, ways->ways))
		{
			tmp = dublicate_rooms(main->rooms, main->len);
			tmp->next = ways->ways;
			ways->ways = tmp;
			return (1);
		}
		main = main->next;
	}
	return (0);
}

int		group_len(t_way *ways, _Bool flag, int sum)
{
	int	counter;

	counter = 0;
	while (ways)
	{
		counter = (flag == LEN) ? (counter + 1) : (counter + (ways->len * sum));
		ways = ways->next;
	}
	return (counter);
}

void	select_best_group(t_lem *l)
{
	t_ways	*tmp;
	t_way	*temp;
	int		sum;

	tmp = l->groups;
	sum = 0;
	while (l->ways)
	{
		temp = l->ways->next;
		free_rooms(&l->ways);
		free(l->ways);
		l->ways = temp;
	}
	while (tmp)
	{
		if (!sum || tmp->sum < sum)
		{
			l->ways = tmp->ways;
			sum = tmp->sum;
		}
		tmp = tmp->next;
	}
}

void	remove_intersection(t_lem *l)
{
	t_way	*ways;
	t_ways	*group;

	ways = l->ways;
	while (ways)
	{
		group = (t_ways*)malloc(sizeof(t_ways));
		group->ways = dublicate_rooms(ways->rooms, ways->len);
		while (1)
		{
			if (!find_unique(l->ways, group))
				break ;
		}
		group->len = group_len(group->ways, LEN, 0);
		group->sum = group_len(group->ways, SUM, l->ants / group->len);
		group->next = l->groups;
		l->groups = group;
		ways = ways->next;
	}
	select_best_group(l);
}
