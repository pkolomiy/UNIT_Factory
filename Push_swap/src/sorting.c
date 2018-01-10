/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:21:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/06 23:51:56 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		count_pushing(_Bool stack, t_stack *tmp, int len, int pivot)
{
	int	counter;

	counter = 0;
	while (len)
	{
		if ((stack == A && tmp->nbr < pivot) ||
		(stack == B && tmp->nbr > pivot))
			counter++;
		len--;
		tmp = tmp->next;
	}
	return (counter);
}

static _Bool	check_middle(t_stack *a, int len, int pivot)
{
	int		i;
	int		from;
	int		to;

	from = 0;
	to = 0;
	i = 0;
	while (a)
	{
		if (i <= len && a->nbr < pivot)
			from++;
		else if (i > len && a->nbr < pivot)
			to++;
		i++;
		a = a->next;
	}
	return (to >> 1 > from);
}

static _Bool	pushing(t_main *m, int pivot, int counter, _Bool middle)
{
	_Bool	reverse;

	reverse = 0;
	while (counter)
	{
		if ((m->stack == A && m->a->nbr >= pivot) ||
		(m->stack == B && m->b->nbr <= pivot))
		{
			if (!middle && !reverse)
				m->temp = ((m->stack == A) ? m->a->nbr : m->b->nbr);
			reverse = (!middle && !reverse) ? (_Bool)1 : reverse;
			if (!middle)
				ra_rb_rr(m->stack == A ? RA : RB, m);
			else
				rra_rrb_rrr(RRA, m);
		}
		if ((m->stack == A && m->a->nbr < pivot) ||
		(m->stack == B && m->b->nbr > pivot))
		{
			pa_pb(m->stack == A ? PB : PA, m);
			counter--;
		}
	}
	return (reverse);
}

static int		push_to(t_main *m, _Bool stack)
{
	int		counter;
	int		pivot;
	_Bool	reverse;
	int		var;

	m->stack = stack;
	var = (stack == A) ? m->a_len : m->b_len;
	pivot = find_pivot(((stack == A) ? m->a : m->b), m->len);
	counter = count_pushing(stack, ((stack == A) ? m->a : m->b), m->len, pivot);
	reverse = pushing(m, pivot, counter, (m->stack == A && m->a_len == m->len) ?
	check_middle(m->a, m->len >> 1, pivot) : (_Bool)0);
	if (var != m->len && reverse)
		while ((stack == A ? m->a->nbr : m->b->nbr) != m->temp)
			rra_rrb_rrr(stack == A ? RRA : RRB, m);
	return (counter);
}

void			sorting(t_main *m, _Bool stack)
{
	int	len;
	int	pushed;

	len = m->len;
	if (m->len > 3)
	{
		pushed = push_to(m, stack);
		m->len = (stack == A) ? (len - pushed) : pushed;
		sorting(m, A);
		m->len = (stack == B) ? (len - pushed) : pushed;
		sorting(m, B);
	}
	else
		sort_3_elem(stack, m);
}
