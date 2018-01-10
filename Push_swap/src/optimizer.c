/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:57:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/07 21:30:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline _Bool	check(char *first, char *second, _Bool flag)
{
	if (flag)
	{
		if ((cmp(first, "pa") && cmp(second, "pb")) ||
		(cmp(first, "pb") && cmp(second, "pa")) ||
		(cmp(first, "ra") && cmp(second, "rra")) ||
		(cmp(first, "rb") && cmp(second, "rrb")) ||
		(cmp(first, "rra") && cmp(second, "ra")) ||
		(cmp(first, "rr") && cmp(second, "rrr")) ||
		(cmp(first, "rrr") && cmp(second, "rr")) ||
		(cmp(first, "rrb") && cmp(second, "rb")) ||
		(cmp(first, "sa") && cmp(second, "sa")) ||
		(cmp(first, "sb") && cmp(second, "sb")))
			return (1);
	}
	else
	{
		if ((cmp(first, "sa") && cmp(second, "sb")) ||
		(cmp(first, "sb") && cmp(second, "sa")) ||
		(cmp(first, "ra") && cmp(second, "rb")) ||
		(cmp(first, "rb") && cmp(second, "ra")) ||
		(cmp(first, "rra") && cmp(second, "rrb")) ||
		(cmp(first, "rrb") && cmp(second, "rra")))
			return (1);
	}
	return (0);
}

static _Bool		first_optimizer(t_main *m)
{
	_Bool	flag;
	t_ins	*tmp;

	flag = 0;
	tmp = m->ins;
	while (tmp && tmp->next)
	{
		if (check(tmp->inst, tmp->next->inst, 1))
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next->next;
			if (tmp->next->next)
				tmp->next->next->prev = tmp->prev;
			free(tmp->next);
			free(tmp);
			tmp = m->ins;
			flag = 1;
		}
		else
			tmp = tmp->next;
	}
	return (flag);
}

static _Bool		second_optimizer(t_main *m)
{
	_Bool	flag;
	t_ins	*tmp;

	flag = 0;
	tmp = m->ins;
	while (tmp && tmp->next && tmp->next->next)
	{
		if ((cmp(tmp->inst, "ra") && cmp(tmp->next->inst, "pb") &&
		cmp(tmp->next->next->inst, "rra")) || (cmp(tmp->inst, "rb") &&
		cmp(tmp->next->inst, "pa") && cmp(tmp->next->next->inst, "rrb")))
		{
			tmp->inst = (tmp->inst[1] == 'a') ? "sa" : "sb";
			if (tmp->next->next->next)
				tmp->next->next->next->prev = tmp->next;
			tmp = tmp->next->next;
			tmp->prev->next = tmp->next;
			free(tmp);
			tmp = m->ins;
			flag = 1;
		}
		else
			tmp = tmp->next;
	}
	return (flag);
}

static _Bool		third_optimizer(t_main *m)
{
	_Bool	flag;
	t_ins	*tmp;

	flag = 0;
	tmp = m->ins;
	while (tmp && tmp->next)
	{
		if (check(tmp->inst, tmp->next->inst, 0))
		{
			if (tmp->inst[1] == 'r')
				tmp->inst = "rrr";
			else
				tmp->inst = tmp->inst[0] == 's' ? "ss" : "rr";
			if (tmp->next->next)
				tmp->next->next->prev = tmp;
			tmp = tmp->next;
			tmp->prev->next = tmp->next;
			free(tmp);
			tmp = m->ins;
			flag = 1;
		}
		else
			tmp = tmp->next;
	}
	return (flag);
}

void				optimizer(t_main *m)
{
	_Bool	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		if (first_optimizer(m))
			flag = 1;
		if (second_optimizer(m))
			flag = 1;
		if (third_optimizer(m))
			flag = 1;
	}
}
