/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:19:04 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:02:29 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	c_flag3(char *b, int *a, t_t **fl)
{
	int		h;
	int		l;

	h = 0;
	l = 0;
	while (b[(*a)] == 104)
	{
		(*a)++;
		h++;
	}
	while (b[(*a)] == 108)
	{
		(*a)++;
		l++;
	}
	(!(h % 2)) && (h) ? ((*fl)->hh = 1) : 0;
	(h % 2) && (h) && (h != 1) ? (*fl)->h = 1 : 0;
	(h % 2) && (h) && (h != 1) ? (*fl)->hh = 1 : 0;
	(h == 1) ? ((*fl)->h = 1) : 0;
	(!(l % 2)) && (l) ? ((*fl)->ll = 1) : 0;
	(l % 2) && (l) && (l != 1) ? (*fl)->ll = 1 : 0;
	(l % 2) && (l) && (l != 1) ? (*fl)->l = 1 : 0;
	(l == 1) ? ((*fl)->l = 1) : 0;
}

void	c_flag2(char c, t_t **fl)
{
	c == 32 ? (*fl)->sp = 1 : 0;
	c == 35 ? (*fl)->sh = 1 : 0;
	c == 43 ? (*fl)->p = 1 : 0;
	c == 45 ? (*fl)->m = 1 : 0;
	c == 48 ? (*fl)->zr = 1 : 0;
	c == 106 ? (*fl)->j = 1 : 0;
	c == 122 ? (*fl)->z = 1 : 0;
}

void	c_flag(char *b, int a, t_t **fl)
{
	while (b[a])
	{
		(D1(b[a]) || D2(b[a]) || D3(b[a])) ? c_flag2(b[a], fl) : 0;
		(D4(b[a]) || D5(b[a])) ? (*fl)->n = get_num(b, &a) : 0;
		if (b[a] == 104 || b[a] == 108)
		{
			c_flag3(b, &a, fl);
			a--;
		}
		if (b[a] == 46)
		{
			(*fl)->d2 = 1;
			(*fl)->d = 0;
			a++;
			while (b[a] == 48)
				a++;
			(D4(b[a]) || D5(b[a])) ? (*fl)->d = get_num(b, &a) : a--;
		}
		a++;
	}
}

int		get_num(char *b, int *a)
{
	size_t	c;
	int		d;

	c = b[(*a)] - 48;
	(*a)++;
	while (D4(b[(*a)]) || D5(b[(*a)]) || b[(*a)] == 48)
	{
		c = (c * 10) + (b[(*a)] - 48);
		(*a)++;
	}
	(*a)--;
	d = c;
	if (d < 0)
		d = 0;
	return (d);
}

t_t		*str(void)
{
	t_t		*l;

	l = (t_t*)malloc(sizeof(t_t));
	l->n = 0;
	l->d = 0;
	l->d2 = 0;
	l->m = 0;
	l->p = 0;
	l->sp = 0;
	l->zr = 0;
	l->sh = 0;
	l->h = 0;
	l->hh = 0;
	l->l = 0;
	l->ll = 0;
	l->j = 0;
	l->z = 0;
	return (l);
}
