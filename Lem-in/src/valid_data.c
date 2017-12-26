/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:41:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/21 18:32:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

_Bool	valid_int(char *str)
{
	_Bool			minus;
	unsigned char	i;
	int				count;
	long			nbr;

	nbr = 0;
	i = 0;
	count = len(str);
	if ((minus = str[0] == '-'))
		i++;
	while (count <= 11 && str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (((!minus && !i && count != 1) || (minus && i == 1)) &&
		str[i] == '0')
			return (0);
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	nbr = minus ? -nbr : nbr;
	if (str[i] || nbr < -2147483648 || nbr > 2147483647)
		return (0);
	return (1);
}

_Bool	valid_room(char *str)
{
	if (*str == 'L')
		return (0);
	while (*str)
	{
		if (*str == '-')
			return (0);
		str++;
	}
	return (1);
}

_Bool	valid_link(t_links links, t_lem *l)
{
	t_links		*tmp;
	t_rooms		*tmp_rooms;
	unsigned	count;

	count = (cmp(links.first, l->start) || cmp(links.first, l->end)) ? 1 : 0;
	count = (cmp(links.second, l->start) || cmp(links.second, l->end)) ?
	count + 1 : count;
	tmp_rooms = l->rooms;
	while (tmp_rooms)
	{
		count = (cmp(links.first, tmp_rooms->name) ||
		cmp(links.second, tmp_rooms->name)) ? count + 1 : count;
		tmp_rooms = tmp_rooms->next;
	}
	if (count != 2)
		return (0);
	tmp = l->links;
	while (tmp)
	{
		if ((cmp(links.first, tmp->first) && cmp(links.second, tmp->second)) ||
		(cmp(links.first, tmp->second) && cmp(links.second, tmp->first)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

_Bool	valid_link_string(const char *str)
{
	_Bool	flag;
	int		i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (((flag || !i) && str[i] == '-') || str[i] == ' ')
			return (0);
		if (!flag && str[i] == '-')
			flag = 1;
		i++;
	}
	return (flag);
}

_Bool	valid_comment(t_lem *l)
{
	if (l->str_len == 7 || l->str_len == 5)
		if (l->str[0] == '#' && l->str[1] == '#' &&
		(cmp(l->str, "##start") || cmp(l->str, "##end")))
			return (0);
	if (l->str[0] != '#')
		return (0);
	return (1);
}
