/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:46:05 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:39:48 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		type_ps(char *b, char *s, t_t *fl, int c)
{
	int		a;
	int		e;

	a = 0;
	prs(b, &a);
	(!s) ? (s = nul()) : 0;
	e = len_m(s);
	fl->d > e ? (fl->d = e) : 0;
	fl->d2 ? (fl->n = fl->n - fl->d) : 0;
	!fl->d2 ? (fl->n = fl->n - e) : 0;
	if (!fl->m)
	{
		fl->zr ? (a = pr_zs(fl->n, a, 0)) : 0;
		!fl->zr ? (a = pr_zs(fl->n, a, 1)) : 0;
	}
	fl->d2 ? pr_st(s, fl->d, &a) : pr_st(s, -1, &a);
	fl->m ? (a = pr_zs(fl->n, a, 1)) : 0;
	(c) ? free(s) : 0;
	free(fl);
	free(b);
	return (a);
}

int		type_pp(int a, unsigned long d, t_t *fl)
{
	(fl->zr) ? (fl->d = fl->n - 2) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	(!fl->d2) ? fl->n = fl->n - 1 : 0;
	(!fl->d2) ? a++ : 0;
	a = a + 2;
	fl->n = fl->n - 2;
	fl->d < 0 ? fl->d = 0 : 0;
	if (fl->m)
	{
		write(1, "0x", 2);
		fl->n = fl->n - fl->d;
		(!fl->d2) ? nbr_u(d, 0, &a) : 0;
		a = pr_zs(fl->d, a, 0);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	fl->d < 0 ? fl->d = 0 : 0;
	a = pr_zs(fl->n, a, 1);
	write(1, "0x", 2);
	a = pr_zs(fl->d, a, 0);
	(!fl->d2) ? nbr_u(d, 0, &a) : 0;
	free(fl);
	return (a);
}

int		type_pc(char *b, char d, t_t *fl)
{
	int		a;

	a = 0;
	prs(b, &a);
	fl->n--;
	a++;
	(fl->zr) ? (fl->d = fl->n) : 0;
	if (fl->m)
	{
		fl->n = fl->n - fl->d;
		write(1, &d, 1);
		a = pr_zs(fl->d, a, 0);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	a = pr_zs(fl->n, a, 1);
	a = pr_zs(fl->d, a, 0);
	write(1, &d, 1);
	free(b);
	free(fl);
	return (a);
}

int		type_s(char *b, void *d, int f, int c)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	fl->m ? (fl->zr = 0) : 0;
	(fl->zr) && (!fl->n) ? (fl->zr = 0) : 0;
	if (((size_t)(fl->n + a + f) > 2147483647))
		return (-1);
	if (fl->l || c == 83)
		return (convert(b, (wchar_t*)d, fl));
	return (type_ps(b, (char*)d, fl, 0));
}

int		type_c(char *b, void *d, int f)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	fl->m ? fl->zr = 0 : 0;
	fl->d = 0;
	fl->d2 = 0;
	if (((size_t)(fl->n + a + f) > 2147483647))
		return (-1);
	return (type_pc(b, (char)d, fl));
}
