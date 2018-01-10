/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/09 00:24:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static _Bool	unsorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static void		show(t_ins *ins)
{
	while (ins)
	{
		write(1, ins->inst, ins->len);
		write(1, "\n", 1);
		ins = ins->next;
	}
}

int				main(int argc, char **argv)
{
	t_main	m;

	if (argc > 1)
	{
		init_main(&m);
		m.program = PUSH_SWAP;
		validate_arguments(argv, &m);
		if (m.a_len != 1 && unsorted(m.a))
		{
			m.len = m.a_len;
			sorting(&m, A);
			optimizer(&m);
			show(m.ins);
		}
	}
	else
		write(1, "usage:  ./push_swap [numbers]\n\t./push_swap 3 1 2 4\n", 51);
	return (0);
}
