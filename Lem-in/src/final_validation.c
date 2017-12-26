/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:51:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 18:08:11 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

_Bool	start_end_with_links(t_lem *l)
{
	t_links	*t;
	_Bool	flag[2];

	flag[0] = 0;
	flag[1] = 0;
	t = l->links;
	while (t && (!flag[0] || !flag[1]))
	{
		if (!flag[0] && (cmp(t->first, l->start) || cmp(t->second, l->start)))
			flag[0] = 1;
		if (!flag[1] && (cmp(t->first, l->end) || cmp(t->second, l->end)))
			flag[1] = 1;
		t = t->next;
	}
	if (!flag[0] || !flag[1])
		return (0);
	return (1);
}

_Bool	start_end_way_exist(t_lem *l)
{
	t_links	*ln;

	ln = l->links;
	while (ln)
	{
		if (cmp(ln->first, l->end))
		{
			if (get_level(l->rooms, ln->second) > 0)
				return (1);
		}
		else if (cmp(ln->second, l->end))
		{
			if (get_level(l->rooms, ln->first) > 0)
				return (1);
		}
		ln = ln->next;
	}
	return (0);
}

void	save_levels(t_lem *l)
{
	t_links	*ln;

	ln = l->links;
	while (ln)
	{
		if (cmp(ln->first, l->start) || cmp(ln->first, l->end))
			ln->lvl1 = cmp(ln->first, l->start) ? 0 : -1;
		else
			ln->lvl1 = get_level(l->rooms, ln->first);
		if (cmp(ln->second, l->start) || cmp(ln->second, l->end))
			ln->lvl2 = cmp(ln->second, l->start) ? 0 : -1;
		else
			ln->lvl2 = get_level(l->rooms, ln->second);
		ln = ln->next;
	}
}

void	remove_hight_links(t_lem *l, char *room)
{
	t_links	*cur;
	t_links	*prev;

	cur = l->links;
	prev = NULL;
	while (cur)
	{
		if ((cmp(cur->first, room) && cur->lvl1 < cur->lvl2) ||
		(cmp(cur->second, room) && cur->lvl2 < cur->lvl1))
		{
			del_link(l, &cur, &prev);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

_Bool	final_validation(t_lem *l)
{
	t_links	*ln;

	if (!l->start || !l->end || !l->links || !start_end_with_links(l))
		error();
	remove_unlink_rooms(l);
	if (!one_way(l))
	{
		set_levels(l);
		if (!start_end_way_exist(l))
			error();
		remove_trash_links(l);
		remove_trash_rooms(l);
		save_levels(l);
		ln = l->links;
		while (ln)
		{
			if (cmp(ln->first, l->end))
				remove_hight_links(l, ln->second);
			else if (cmp(ln->second, l->end))
				remove_hight_links(l, ln->first);
			ln = ln->next;
		}
		return (1);
	}
	return (0);
}
