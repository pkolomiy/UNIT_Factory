/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:54:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 14:26:43 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_rooms(t_way **way)
{
	t_rooms	*tmp;

	while ((*way)->rooms)
	{
		tmp = (*way)->rooms->next;
		free((*way)->rooms->name);
		free((*way)->rooms);
		(*way)->rooms = tmp;
	}
}

void	del_way(t_lem *l, t_way **cur, t_way **prev)
{
	if (!*prev)
	{
		l->ways = l->ways->next;
		*prev = *cur;
		*cur = (*cur)->next;
		free_rooms(prev);
		free(*prev);
		*prev = NULL;
	}
	else
	{
		(*prev)->next = (*cur)->next;
		free_rooms(cur);
		free(*cur);
		*cur = (*prev)->next;
	}
}

void	add_end(t_lem *l, char *room, int level)
{
	t_way	*w;

	w = (t_way*)malloc(sizeof(t_way));
	w->len = level;
	w->rooms = (t_rooms*)malloc(sizeof(t_rooms));
	w->rooms->name = copy(room);
	w->rooms->level = level;
	w->rooms->next = (t_rooms*)malloc(sizeof(t_rooms));
	w->rooms->next->name = copy(l->end);
	w->rooms->next->level = -1;
	w->rooms->next->next = NULL;
	w->next = l->ways;
	l->ways = w;
}

t_way	*dublicate_rooms(t_rooms *rooms, int len)
{
	t_way	*way;
	t_rooms	*rm;

	way = (t_way*)malloc(sizeof(t_way));
	way->len = len;
	way->rooms = (t_rooms*)malloc(sizeof(t_rooms));
	rm = way->rooms;
	while (rooms)
	{
		rm->name = copy(rooms->name);
		rm->level = rooms->level;
		if ((rooms = rooms->next))
		{
			rm->next = (t_rooms*)malloc(sizeof(t_rooms));
			rm = rm->next;
		}
		else
		{
			rm->next = NULL;
		}
	}
	way->next = NULL;
	return (way);
}

void	dublicate_way(t_way *ways, char *room, int links)
{
	t_way	*tmp;

	while (ways)
	{
		if (cmp(ways->rooms->name, room))
			break ;
		ways = ways->next;
	}
	while (ways && links)
	{
		tmp = dublicate_rooms(ways->rooms, ways->len);
		tmp->next = ways->next;
		ways->next = tmp;
		links--;
	}
}
