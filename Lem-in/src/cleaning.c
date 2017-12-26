/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:28:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/24 19:52:25 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	del_room(t_lem *l, t_rooms **cur, t_rooms **prev)
{
	if (!*prev)
	{
		l->rooms = l->rooms->next;
		*prev = *cur;
		*cur = (*cur)->next;
		free((*prev)->name);
		free(*prev);
		*prev = NULL;
	}
	else
	{
		(*prev)->next = (*cur)->next;
		free((*cur)->name);
		free(*cur);
		*cur = (*prev)->next;
	}
}

void	del_link(t_lem *l, t_links **cur, t_links **prev)
{
	if (!*prev)
	{
		l->links = l->links->next;
		*prev = *cur;
		*cur = (*cur)->next;
		free((*prev)->first);
		free((*prev)->second);
		free(*prev);
		*prev = NULL;
	}
	else
	{
		(*prev)->next = (*cur)->next;
		free((*cur)->first);
		free((*cur)->second);
		free(*cur);
		*cur = (*prev)->next;
	}
}

void	remove_unlink_rooms(t_lem *l)
{
	t_links	*ln;
	t_rooms	*cur;
	t_rooms	*prev;

	cur = l->rooms;
	prev = NULL;
	while (cur)
	{
		ln = l->links;
		while (ln)
		{
			if (cmp(ln->first, cur->name) || cmp(ln->second, cur->name))
				break ;
			ln = ln->next;
		}
		if (!ln)
		{
			del_room(l, &cur, &prev);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void	remove_trash_links(t_lem *l)
{
	t_links	*cur;
	t_links	*prev;

	cur = l->links;
	prev = NULL;
	while (cur)
	{
		if (get_level(l->rooms, cur->first) < 0)
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

void	remove_trash_rooms(t_lem *l)
{
	t_rooms	*cur;
	t_rooms	*prev;

	cur = l->rooms;
	prev = NULL;
	while (cur)
	{
		if (cur->level == -1)
		{
			del_room(l, &cur, &prev);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
