/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 00:34:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/08 23:04:03 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				apply(t_main *m, const char *inst)
{
	if (inst[0] == 'p')
		pa_pb(inst[1] == 'a' ? PA : PB, m);
	else if (inst[0] == 's' && inst[1] != 's')
		sa_sb_ss(inst[1] == 'a' ? SA : SB, m);
	else if (inst[0] == 'r' && inst[1] != 'r')
		ra_rb_rr(inst[1] == 'a' ? RA : RB, m);
	else if (inst[1] == 's' || (inst[1] == 'r' && !inst[2]))
	{
		if (inst[0] == 's')
			sa_sb_ss(SS, m);
		else
			ra_rb_rr(RR, m);
	}
	else
	{
		if (inst[2] == 'r')
			rra_rrb_rrr(RRR, m);
		else
			rra_rrb_rrr(inst[2] == 'a' ? RRA : RRB, m);
	}
}

static void			checker(t_main *m)
{
	t_stack	*a;

	m->temp = 0;
	m->tmp = m->ins;
	while (m->tmp)
	{
		m->temp++;
		apply(m, m->tmp->inst);
		if (m->program == VISUALIZER)
			visualizer(m);
		m->tmp = m->tmp->next;
	}
	a = m->a;
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			break ;
		a = a->next;
	}
	if (m->b_len || a->next)
	{
		write(1, "\r\e[31;1mKO\e[0m\n\r", 16);
	}
	else
		write(1, "\r\e[32;1mOK\e[0m\n\r", 16);
}

static inline char	*valid_instruction(char *str)
{
	if (cmp(str, "pa"))
		return ("pa");
	else if (cmp(str, "pb"))
		return ("pb");
	else if (cmp(str, "sa"))
		return ("sa");
	else if (cmp(str, "sb"))
		return ("sb");
	else if (cmp(str, "ss"))
		return ("ss");
	else if (cmp(str, "ra"))
		return ("ra");
	else if (cmp(str, "rb"))
		return ("rb");
	else if (cmp(str, "rra"))
		return ("rra");
	else if (cmp(str, "rrb"))
		return ("rrb");
	else if (cmp(str, "rr"))
		return ("rr");
	else if (cmp(str, "rrr"))
		return ("rrr");
	write(2, "Error\n", 6);
	free(str);
	exit(1);
}

static void			get_instructions(t_main *m)
{
	char	*str;
	t_ins	*tmp;
	t_ins	*tmp2;

	tmp2 = NULL;
	while ((get_next_line(0, &str)) > 0)
	{
		if (!tmp2 && m->ins && m->ins->next)
			tmp2 = m->ins->next;
		tmp = (t_ins*)malloc(sizeof(t_ins));
		tmp->inst = valid_instruction(str);
		tmp->next = NULL;
		free(str);
		if (!m->ins)
			m->ins = tmp;
		else if (!m->ins->next)
			m->ins->next = tmp;
		else
		{
			tmp2->next = tmp;
			tmp2 = tmp2->next;
		}
	}
	free(str);
}

int					main(int argc, char **argv)
{
	t_main	m;

	if (argc > 1)
	{
		init_main(&m);
		m.program = cmp(argv[1], "-v") ? VISUALIZER : CHECKER;
		validate_arguments(((m.program == VISUALIZER && argc > 2) ?
		++argv : argv), &m);
		get_instructions(&m);
		if (m.ins)
		{
			m.tmp = m.ins;
			m.ins->prev = NULL;
			while (m.tmp->next)
			{
				m.tmp->next->prev = m.tmp;
				m.tmp = m.tmp->next;
			}
		}
		checker(&m);
	}
	else
		write(1, "usage:  ./checker -v [numbers]\n\t./checker 3 1 2 4\n"
		"\t[-v] - optional flag, enables visualizer\n", 92);
	return (0);
}
