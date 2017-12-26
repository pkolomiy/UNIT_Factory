/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:26:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 21:51:08 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		colors(char *arr[])
{
	arr[0] = "\e[31;1m";
	arr[1] = "\e[32;1m";
	arr[2] = "\e[33;1m";
	arr[3] = "\e[34;1m";
	arr[4] = "\e[35;1m";
	arr[5] = "\e[36;1m";
	arr[6] = "\e[37;1m";
	arr[7] = "\e[0m";
}

static void	print_way(unsigned ants, char *end)
{
	char		*arr[8];
	unsigned	count;
	unsigned	end_len;

	count = 0;
	end_len = len(end);
	colors(arr);
	write(1, "\n", 1);
	while (++count)
	{
		write(1, arr[count % 7], 7);
		write(1, "L", 1);
		nbr(count);
		write(1, "-", 1);
		write(1, end, end_len);
		write(1, arr[7], 4);
		write(1, " ", 1);
		if (count == ants)
			break ;
	}
	write(1, "\n", 1);
}

_Bool		one_way(t_lem *l)
{
	_Bool	flag;
	t_links	*tmp;

	flag = 0;
	tmp = l->links;
	while (tmp && !flag)
	{
		if ((cmp(tmp->first, l->start) && cmp(tmp->second, l->end)) ||
		(cmp(tmp->second, l->start) && cmp(tmp->first, l->end)))
			flag = 1;
		tmp = tmp->next;
	}
	if (flag)
	{
		print_way((unsigned)l->ants, l->end);
	}
	return (flag);
}
