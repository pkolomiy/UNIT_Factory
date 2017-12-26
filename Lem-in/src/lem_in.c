/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 12:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 22:22:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		count_links(t_links *ln, char *room, int level)
{
	int		counter;

	counter = 0;
	while (ln)
	{
		if ((cmp(ln->first, room) && ln->lvl2 == level) ||
		(cmp(ln->second, room) && ln->lvl1 == level))
		{
			counter++;
		}
		ln = ln->next;
	}
	return (counter);
}

void	add_connection(t_links **ln, t_way *ways, t_rooms *tmp)
{
	while (*ln)
	{
		if ((*ln)->lvl2 == ways->rooms->level - 1 &&
		cmp((*ln)->first, ways->rooms->name))
		{
			tmp = (t_rooms*)malloc(sizeof(t_rooms));
			tmp->name = copy((*ln)->second);
			tmp->level = (*ln)->lvl2;
			tmp->next = ways->rooms;
			ways->rooms = tmp;
			break ;
		}
		else if ((*ln)->lvl1 == ways->rooms->level - 1 &&
		cmp((*ln)->second, ways->rooms->name))
		{
			tmp = (t_rooms*)malloc(sizeof(t_rooms));
			tmp->name = copy((*ln)->first);
			tmp->level = (*ln)->lvl1;
			tmp->next = ways->rooms;
			ways->rooms = tmp;
			break ;
		}
		*ln = (*ln)->next;
	}
	*ln = *ln ? (*ln)->next : NULL;
}

_Bool	find_all_ways(t_lem *l, char *room, int level)
{
	int		links;
	t_links	*ln;
	t_way	*ways;
	t_rooms	*tmp;

	if (!(links = count_links(l->links, room, level - 1)))
		return (0);
	if (links != 1)
		dublicate_way(l->ways, room, links - 1);
	ways = l->ways;
	ln = l->links;
	tmp = NULL;
	while (ways && ln)
	{
		if (cmp(ways->rooms->name, room))
		{
			add_connection(&ln, ways, tmp);
		}
		ways = ways->next;
	}
	return (1);
}

void	make_way_from_end(t_lem *l)
{
	t_links	*ln;

	ln = l->links;
	while (ln)
	{
		if (cmp(ln->first, l->end))
		{
			add_end(l, ln->second, ln->lvl2);
		}
		else if (cmp(ln->second, l->end))
		{
			add_end(l, ln->first, ln->lvl1);
		}
		ln = ln->next;
	}
}

void	lem_in(t_lem *l)
{
	t_way	*ways;

	l->groups = NULL;
	make_way_from_end(l);
	ways = l->ways;
	while (ways)
	{
		if (!ways->rooms->level ||
		!(find_all_ways(l, ways->rooms->name, ways->rooms->level)))
		{
			ways = ways->next;
		}
	}
	clean_ways(l);
	if (count_ways(l->ways) > 1)
		remove_intersection(l);
	prepare(l->ways);
	show_ways(l->ways);
	print(l);
}
