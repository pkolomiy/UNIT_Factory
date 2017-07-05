/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:01:40 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:15:08 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		print2(int n, int a, char c, int m)
{
	n--;
	if (m == 1)
	{
		write(1, &c, 1);
		while (n-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (n-- > 0)
		{
			m == 2 ? write(1, " ", 1) : 0;
			m == 0 ? write(1, "0", 1) : 0;
		}
		write(1, &c, 1);
	}
	a == 0 ? a++ : 0;
	return (a);
}

t_c		*st(int n, int d, int c, int b)
{
	t_c			*fl;

	if ((size_t)(n + d + c) > 2147483647 &&
		(V1(b) && V2(b) && V3(b) && V4(b)))
		return (0);
	fl = (t_c*)malloc(sizeof(t_c));
	fl->m = 0;
	fl->zr = 0;
	fl->n = 0;
	return (fl);
}

int		print(t_c *fl, char *b, int c)
{
	int		a;
	int		d;

	a = 0;
	prs(b, &a);
	free(b);
	if (D1(c) || D2(c) || D3(c) || D4(c) || D5(c))
		return (a);
	fl->n == 0 ? a++ : 0;
	a = a + fl->n;
	if (fl->m == 1)
		d = print2(fl->n, a, c, fl->m);
	else if (fl->zr == 1)
		d = print2(fl->n, a, c, 0);
	else
		d = print2(fl->n, a, c, 2);
	free(fl);
	return (d);
}

int		just_char2(char *b, int a, int d)
{
	t_c			*fl;
	int			c;

	fl = st(0, 0, 0, 0);
	c = a - 1;
	while (b[a])
	{
		b[a] == 45 ? fl->m = 1 : 0;
		b[a] == 48 ? fl->zr = 1 : 0;
		(D4(b[a]) || D5(b[a])) ? (fl->n = get_num(b, &a)) : 0;
		if (b[a] == 46)
		{
			a++;
			while (D4(b[a]) || D5(b[a]) || b[a] == 48)
				a++;
			a--;
		}
		a++;
	}
	if (!st(fl->n, d, c, b[a - 1]))
	{
		free(b);
		return (-1);
	}
	return (print(fl, b, b[a - 1]));
}
