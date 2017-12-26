/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:24:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/21 18:35:42 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_link(char *str, _Bool pos)
{
	int		i;
	int		j;
	char	*dst;
	char	*tmp;

	i = 0;
	tmp = str;
	while (*str && !(pos == FIRST && *str == '-'))
		if ((i = (*str == '-') ? 0 : i + 1) >= 0)
			str++;
	!(dst = (char*)malloc((unsigned)(i + 1))) ? exit(8) : 0;
	i = -1;
	j = 0;
	while (tmp[++i] && !(pos == FIRST && tmp[i] == '-'))
	{
		if (pos == FIRST || j)
			dst[i - j] = tmp[i];
		if (pos == SECOND && tmp[i] == '-')
			j = i + 1;
	}
	dst[i - j] = '\0';
	return (dst);
}

void	get_links(t_lem *l)
{
	t_links	links;
	t_links	*tmp;

	if (!valid_comment(l))
	{
		(!valid_link_string(l->str)) ? error() : 0;
		links.first = get_link(l->str, FIRST);
		links.second = get_link(l->str, SECOND);
		if (cmp(links.first, links.second) || !valid_link(links, l))
			error();
		tmp = l->links;
		while (tmp)
			tmp = tmp->next;
		tmp = (t_links*)malloc(sizeof(t_links));
		tmp->first = links.first;
		tmp->second = links.second;
		tmp->next = l->links;
		l->links = tmp;
	}
	put(l);
}

char	*get_valid_room(t_lem *l, _Bool flag)
{
	int		i;
	t_rooms	*tmp;

	i = -1;
	while (l->ptr && l->ptr[++i])
		free(l->ptr[i]);
	(l->ptr) ? free(l->ptr) : 0;
	l->ptr = split(l, l->str);
	(!valid_room(l->ptr[0]) || !valid_int(l->ptr[1]) || !valid_int(l->ptr[2]) ||
	cmp(l->ptr[0], l->start) || cmp(l->ptr[0], l->end)) ? error() : 0;
	tmp = l->rooms;
	while (tmp)
	{
		if (cmp(l->ptr[0], tmp->name))
			error();
		tmp = tmp->next;
	}
	if (!flag)
		return (copy(l->ptr[0]));
	!(tmp = (t_rooms*)malloc(sizeof(t_rooms))) ? exit(8) : 0;
	tmp->name = copy(l->ptr[0]);
	tmp->level = -1;
	tmp->next = l->rooms;
	l->rooms = tmp;
	return (0);
}

void	get_room(t_lem *l)
{
	if (!valid_comment(l))
	{
		if (cmp(l->str, "##start"))
		{
			(l->start) ? error() : 0;
			put(l);
			if ((get_next_line(0, &l->str)) <= 0 ||
			!(l->str_len = len(l->str)) || valid_comment(l) ||
			!(l->start = get_valid_room(l, 0)))
				error();
		}
		else if (cmp(l->str, "##end"))
		{
			(l->end) ? error() : 0;
			put(l);
			if ((get_next_line(0, &l->str)) <= 0 ||
			!(l->str_len = len(l->str)) || valid_comment(l) ||
			!(l->end = get_valid_room(l, 0)))
				error();
		}
		else
			get_valid_room(l, 1);
	}
	put(l);
}

void	get_ant(t_lem *l)
{
	unsigned char	i;

	if (!valid_comment(l))
	{
		i = 0;
		while (l->str_len <= 10 && l->str[i] &&
		l->str[i] >= '0' && l->str[i] <= '9')
		{
			if (!i && l->str[i] == '0')
				error();
			l->ants = (l->ants * 10) + (l->str[i] - 48);
			i++;
		}
		if (!l->ants || l->ants > 4294967295 || l->str[i])
			error();
		l->stage = 2;
	}
	put(l);
}
