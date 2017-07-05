/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 00:02:28 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:18:06 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		print_st0(int a, long d, t_t *fl, int e)
{
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	(!fl->d2) ? fl->n = fl->n - e : 0;
	(!fl->d2) ? a++ : 0;
	if (fl->m)
	{
		fl->n = fl->n - fl->d;
		(!fl->d2) ? nbr_s(d, 0, &a) : 0;
		a = pr_zs(fl->d, a, 0);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	(fl->p || fl->sp) ? fl->n-- : 0;
	fl->n = fl->n - fl->d;
	a = pr_zs(fl->n, a, 1);
	fl->p ? (write(1, "+", 1)) && (a++) : 0;
	fl->sp && !fl->p ? (write(1, " ", 1)) && (a++) : 0;
	((fl->p) || (fl->sp)) && (fl->zr) && (fl->d != 1) ? fl->d-- : 0;
	a = pr_zs(fl->d, a, 0);
	(!fl->d2) ? nbr_s(d, 0, &a) : 0;
	free(fl);
	return (a);
}

int		print_st2(int a, long d, t_t *fl, int e)
{
	if (!d)
		return (print_st0(a, d, fl, e));
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	d < 0 ? fl->d++ : 0;
	((d < 0) || (fl->p) || (fl->sp)) && (fl->zr) ? fl->d-- : 0;
	if ((fl->d = fl->d - e) < 0)
		fl->d = 0;
	(fl->p || fl->sp) && d > 0 ? fl->n-- : 0;
	(fl->p || fl->sp) && d > 0 ? a++ : 0;
	fl->n = fl->n - e - fl->d;
	a = a + e;
	a = pr_zs(fl->n, a, 1);
	(fl->p) && d > 0 ? write(1, "+", 1) : 0;
	(fl->sp) && d > 0 ? write(1, " ", 1) : 0;
	d > 0 ? a = pr_zs(fl->d, a, 0) : 0;
	d < 0 ? nbr_s(d, fl->d, &a) : nbr_s(d, 0, &a);
	free(fl);
	return (a);
}

int		print_st(int a, long d, t_t *fl, int e)
{
	if (!d)
		return (print_st0(a, d, fl, e));
	d < 0 ? fl->d++ : 0;
	fl->d = fl->d - e;
	fl->d < 0 ? fl->d = 0 : 0;
	fl->n = fl->n - e;
	a = a + e;
	if (!fl->d)
	{
		nbr_s(d, 0, &a);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	d > 0 ? a = pr_zs(fl->d, a, 0) : 0;
	d < 0 ? nbr_s(d, fl->d, &a) : nbr_s(d, 0, &a);
	a = pr_zs(fl->n, a, 1);
	free(fl);
	return (a);
}

int		type_st(char *b, long d, t_t *fl)
{
	int		a;
	int		e;

	a = 0;
	e = len_s(d);
	prs(b, &a);
	free(b);
	if (fl->m)
	{
		if ((fl->p || fl->sp) && d >= 0)
		{
			fl->p ? write(1, "+", 1) : 0;
			fl->sp && !fl->p ? write(1, " ", 1) : 0;
			fl->n--;
			a++;
		}
		return (print_st(a, d, fl, e));
	}
	return (print_st2(a, d, fl, e));
}

int		type_sig(char *b, void *d, int f, int c)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	ignor(&fl);
	c == 68 ? fl->l = 1 : 0;
	if (((size_t)(fl->n + a + f) > 2147483647) ||
		((size_t)(fl->d + a + f) > 2147483647))
		return (-1);
	if (fl->z || fl->j || fl->ll || fl->l)
		return (type_st(b, (long)d, fl));
	if (fl->h)
		return (type_st(b, (short)d, fl));
	if (fl->hh)
		return (type_st(b, (char)d, fl));
	return (type_st(b, (int)d, fl));
}
