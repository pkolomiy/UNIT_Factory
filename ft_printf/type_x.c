/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:50:55 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:27:11 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		print_x0(int a, unsigned long d, t_t *fl, int e)
{
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	(!fl->d2) ? fl->n = fl->n - e : 0;
	(!fl->d2) ? a++ : 0;
	fl->sh && fl->d > 0 && fl->d2 ? a++ : 0;
	fl->sh && fl->d > 0 && fl->d2 ? fl->n-- && fl->d-- : 0;
	fl->d < 0 ? fl->d = 0 : 0;
	if (fl->m)
	{
		fl->sh && fl->d > 0 && fl->d2 ? write(1, "0", 1) : 0;
		fl->n = fl->n - fl->d;
		(!fl->d2) ? nbr_u(d, 0, &a) : 0;
		a = pr_zs(fl->d, a, 0);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	fl->d < 0 ? fl->d = 0 : 0;
	a = pr_zs(fl->n, a, 1);
	fl->sh && fl->d > 0 && fl->d2 ? write(1, "0", 1) : 0;
	a = pr_zs(fl->d, a, 0);
	(!fl->d2) ? nbr_u(d, 0, &a) : 0;
	free(fl);
	return (a);
}

int		print_x2(int a, char *s, t_t *fl, int e)
{
	fl->sh ? (a = a + 2) : 0;
	fl->sh ? (fl->n = fl->n - 2) : 0;
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	if ((fl->d = fl->d - e) < 0)
		fl->d = 0;
	fl->n = fl->n - e - fl->d;
	a = a + e;
	a = pr_zs(fl->n, a, 1);
	fl->sh && fl->p == 120 ? (write(1, "0x", 2)) : 0;
	fl->sh && fl->p == 88 ? (write(1, "0X", 2)) : 0;
	a = pr_zs(fl->d, a, 0);
	nbr_o(s, 0, &a);
	free(s);
	free(fl);
	return (a);
}

int		print_x(int a, char *s, t_t *fl, int e)
{
	fl->d = fl->d - e;
	fl->n = fl->n - e;
	fl->sh && fl->p == 120 ? (write(1, "0x", 2)) : 0;
	fl->sh && fl->p == 88 ? (write(1, "0X", 2)) : 0;
	fl->sh ? (a = a + 2) : 0;
	fl->sh ? (fl->n = fl->n - 2) : 0;
	fl->d < 0 ? fl->d = 0 : 0;
	a = a + e;
	if (!fl->d)
	{
		nbr_o(s, 0, &a);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	a = pr_zs(fl->d, a, 0);
	nbr_o(s, 0, &a);
	a = pr_zs(fl->n, a, 1);
	free(s);
	free(fl);
	return (a);
}

int		type_x(char *b, unsigned long d, t_t *fl, int c)
{
	int		a;
	int		e;
	char	*s;

	a = 0;
	prs(b, &a);
	free(b);
	if (c == 112 && !d)
		return (type_pp(a, d, fl));
	s = tob(d, 16, &e, fl->p);
	if (!d)
	{
		free(s);
		return (print_x0(a, d, fl, e));
	}
	if (fl->m)
		return (print_x(a, s, fl, e));
	return (print_x2(a, s, fl, e));
}

int		type_16(char *b, void *d, int f, int c)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	ignor(&fl);
	fl->p = c;
	if (((size_t)(fl->n + a + f) > 2147483647) ||
		((size_t)(fl->d + a + f) > 2147483647))
		return (-1);
	if (fl->z || fl->j || fl->ll || fl->l)
		return (type_x(b, (unsigned long)d, fl, 0));
	if (fl->h)
		return (type_x(b, (unsigned short)d, fl, 0));
	if (fl->hh)
		return (type_x(b, (unsigned char)d, fl, 0));
	return (type_x(b, (unsigned)d, fl, 0));
}
