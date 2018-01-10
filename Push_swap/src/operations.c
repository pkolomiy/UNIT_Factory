/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 21:09:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/06 19:13:20 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		instructions(t_main *m, char *str, unsigned char len)
{
	t_ins	*tmp2;

	m->tmp = m->ins;
	while (m->tmp && m->tmp->next)
		m->tmp = m->tmp->next;
	tmp2 = (t_ins*)malloc(sizeof(t_ins));
	tmp2->len = len;
	tmp2->inst = str;
	tmp2->next = NULL;
	if (!m->tmp)
	{
		tmp2->prev = NULL;
		m->ins = tmp2;
	}
	else
	{
		tmp2->prev = m->tmp;
		m->tmp->next = tmp2;
	}
}

void		sa_sb_ss(char action, t_main *m)
{
	t_stack	*tmp;

	if ((action == SA || action == SS) && m->a_len > 1)
	{
		tmp = m->a;
		m->a = m->a->next;
		tmp->next = m->a->next;
		m->a->next = tmp;
		if (m->program == PUSH_SWAP)
			instructions(m, action == SA ? "sa" : "ss", 2);
	}
	if ((action == SB || action == SS) && m->b_len > 1)
	{
		tmp = m->b;
		m->b = m->b->next;
		tmp->next = m->b->next;
		m->b->next = tmp;
		if (m->program == PUSH_SWAP)
			instructions(m, action == SB ? "sb" : "ss", 2);
	}
}

void		pa_pb(char action, t_main *m)
{
	t_stack	*tmp;

	if (action == PA && m->b_len > 0)
	{
		tmp = m->b;
		m->b = m->b->next;
		tmp->next = m->a;
		m->a = tmp;
		m->b_len--;
		m->a_len++;
		if (m->program == PUSH_SWAP)
			instructions(m, "pa", 2);
	}
	if (action == PB && m->a_len > 0)
	{
		tmp = m->a;
		m->a = m->a->next;
		tmp->next = m->b;
		m->b = tmp;
		m->a_len--;
		m->b_len++;
		if (m->program == PUSH_SWAP)
			instructions(m, "pb", 2);
	}
}

void		ra_rb_rr(char action, t_main *m)
{
	t_stack	*tmp;

	if ((action == RA || action == RR) && m->a_len > 1)
	{
		tmp = m->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = m->a;
		m->a = m->a->next;
		tmp->next->next = NULL;
		if (m->program == PUSH_SWAP)
			instructions(m, action == RA ? "ra" : "rr", 2);
	}
	if ((action == RB || action == RR) && m->b_len > 1)
	{
		tmp = m->b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = m->b;
		m->b = m->b->next;
		tmp->next->next = NULL;
		if (m->program == PUSH_SWAP)
			instructions(m, action == RB ? "rb" : "rr", 2);
	}
}

void		rra_rrb_rrr(char action, t_main *m)
{
	t_stack	*tmp;

	if ((action == RRA || action == RRR) && m->a_len > 1)
	{
		tmp = m->a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = m->a;
		m->a = tmp->next;
		tmp->next = NULL;
		if (m->program == PUSH_SWAP)
			instructions(m, action == RRA ? "rra" : "rrr", 3);
	}
	if ((action == RRB || action == RRR) && m->b_len > 1)
	{
		tmp = m->b;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = m->b;
		m->b = tmp->next;
		tmp->next = NULL;
		if (m->program == PUSH_SWAP)
			instructions(m, action == RRB ? "rrb" : "rrr", 3);
	}
}
