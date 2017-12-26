/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:23:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 18:13:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

void	put(t_lem *l)
{
	write(1, l->str, l->str_len);
	write(1, "\n", 1);
	free(l->str);
	l->str = NULL;
	l->str_len = 0;
}

_Bool	stage_two(t_lem *l)
{
	if (!valid_comment(l))
	{
		if (valid_link_string(l->str))
		{
			if (!l->start || !l->end)
				error();
			l->stage = 3;
			return (0);
		}
	}
	return (1);
}

void	nbr(unsigned n)
{
	if (n >= 10)
		nbr(n / 10);
	if (n >= 10)
		nbr(n % 10);
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
	}
}

int		main(void)
{
	t_lem	l;

	l.start = NULL;
	l.end = NULL;
	l.rooms = NULL;
	l.links = NULL;
	l.ways = NULL;
	l.str = NULL;
	l.ptr = NULL;
	l.ants = 0;
	l.stage = 1;
	while ((get_next_line(0, &l.str)) > 0)
	{
		if (!(l.str_len = len(l.str)))
			error();
		if (l.stage == 1)
			get_ant(&l);
		else if (l.stage == 2 && stage_two(&l))
			get_room(&l);
		else
			get_links(&l);
	}
	if (final_validation(&l))
		lem_in(&l);
	return (0);
}
