/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_levels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:59:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/24 12:41:36 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_level(t_rooms *rooms, char *room)
{
	while (rooms)
	{
		if (cmp(rooms->name, room))
			return (rooms->level);
		rooms = rooms->next;
	}
	return (0);
}

void	set_level(char *room, int level, t_lem *l)
{
	t_rooms	*tmp;

	tmp = l->rooms;
	while (tmp)
	{
		if (cmp(room, tmp->name) && tmp->level < 0)
		{
			tmp->level = level;
			break ;
		}
		tmp = tmp->next;
	}
}

_Bool	level_operation(_Bool action, char *room, int level, t_lem *l)
{
	t_links	*ln;

	ln = l->links;
	while (ln)
	{
		if (cmp(room, ln->first) &&
		!cmp(ln->second, l->start) && !cmp(ln->second, l->end))
		{
			if (action == SET)
				set_level(ln->second, level, l);
			else if (action == GET && get_level(l->rooms, ln->second) < 0)
				return (1);
		}
		else if (cmp(room, ln->second) &&
		!cmp(ln->first, l->start) && !cmp(ln->first, l->end))
		{
			if (action == SET)
				set_level(ln->first, level, l);
			else if (action == GET && get_level(l->rooms, ln->first) < 0)
				return (1);
		}
		ln = ln->next;
	}
	return (0);
}

_Bool	check_level(int level, t_lem *l)
{
	t_rooms	*rm;

	rm = l->rooms;
	while (rm)
	{
		if (rm->level == level)
		{
			if (level_operation(GET, rm->name, level, l))
				return (1);
		}
		rm = rm->next;
	}
	return (0);
}

void	set_levels(t_lem *l)
{
	t_rooms	*rm;
	int		level;

	level = 1;
	level_operation(SET, l->start, level, l);
	while (check_level(level, l))
	{
		rm = l->rooms;
		while (rm)
		{
			if (rm->level == level)
				level_operation(SET, rm->name, level + 1, l);
			rm = rm->next;
		}
		level++;
	}
}
