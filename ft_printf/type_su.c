/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_su.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:49:12 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:20:12 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		print_su0(int a, unsigned long d, t_t *fl, int e)
{
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	(!fl->d2) ? fl->n = fl->n - e : 0;
	(!fl->d2) ? a++ : 0;
	if (fl->m)
	{
		fl->n = fl->n - fl->d;
		(!fl->d2) ? nbr_u(d, 0, &a) : 0;
		a = pr_zs(fl->d, a, 0);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	a = pr_zs(fl->n, a, 1);
	a = pr_zs(fl->d, a, 0);
	(!fl->d2) ? nbr_u(d, 0, &a) : 0;
	free(fl);
	return (a);
}

int		print_su2(int a, unsigned long d, t_t *fl, int e)
{
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	if ((fl->d = fl->d - e) < 0)
		fl->d = 0;
	fl->n = fl->n - e - fl->d;
	a = a + e;
	a = pr_zs(fl->n, a, 1);
	a = pr_zs(fl->d, a, 0);
	nbr_u(d, 0, &a);
	free(fl);
	return (a);
}

int		print_su(int a, unsigned long d, t_t *fl, int e)
{
	fl->d = fl->d - e;
	fl->d < 0 ? fl->d = 0 : 0;
	fl->n = fl->n - e;
	a = a + e;
	if (!fl->d)
	{
		nbr_u(d, 0, &a);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	a = pr_zs(fl->d, a, 0);
	nbr_u(d, 0, &a);
	a = pr_zs(fl->n, a, 1);
	free(fl);
	return (a);
}

int		type_su(char *b, unsigned long d, t_t *fl)
{
	int		a;
	int		e;

	a = 0;
	e = len_u(d);
	prs(b, &a);
	free(b);
	if (!d)
		return (print_su0(a, d, fl, e));
	if (fl->m)
		return (print_su(a, d, fl, e));
	return (print_su2(a, d, fl, e));
}

int		type_uns(char *b, void *d, int f, int c)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	ignor(&fl);
	c == 85 ? fl->l = 1 : 0;
	if (((size_t)(fl->n + a + f) > 2147483647) ||
		((size_t)(fl->d + a + f) > 2147483647))
		return (-1);
	if (fl->z || fl->j || fl->ll || fl->l)
		return (type_su(b, (unsigned long)d, fl));
	if (fl->h)
		return (type_su(b, (unsigned short)d, fl));
	if (fl->hh)
		return (type_su(b, (unsigned char)d, fl));
	return (type_su(b, (unsigned)d, fl));
}
