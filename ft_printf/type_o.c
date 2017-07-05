/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:59:19 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:26:42 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		print_o0(int a, unsigned long d, t_t *fl, int e)
{
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	(!fl->d2) ? fl->n = fl->n - e : 0;
	(!fl->d2) ? a++ : 0;
	fl->sh && fl->d < 1 && fl->d2 ? a++ : 0;
	fl->sh && fl->d < 1 && fl->d2 ? fl->n-- && fl->d-- : 0;
	fl->d < 0 ? fl->d = 0 : 0;
	if (fl->m)
	{
		fl->sh && fl->d < 1 && fl->d2 ? write(1, "0", 1) : 0;
		fl->n = fl->n - fl->d;
		(!fl->d2) ? nbr_u(d, 0, &a) : 0;
		a = pr_zs(fl->d, a, 0);
		a = pr_zs(fl->n, a, 1);
		return (a);
	}
	fl->n = fl->n - fl->d;
	fl->d < 0 ? fl->d = 0 : 0;
	a = pr_zs(fl->n, a, 1);
	fl->sh && fl->d < 1 && fl->d2 ? write(1, "0", 1) : 0;
	a = pr_zs(fl->d, a, 0);
	(!fl->d2) ? nbr_u(d, 0, &a) : 0;
	free(fl);
	return (a);
}

int		print_o2(int a, char *s, t_t *fl, int e)
{
	(fl->zr) ? (fl->d = fl->n) : 0;
	(fl->zr) ? (fl->d2 = 1) : 0;
	if ((fl->d = fl->d - e) < 0)
		fl->d = 0;
	fl->n = fl->n - e - fl->d;
	a = a + e;
	fl->sh && !fl->d ? fl->n-- && a++ && fl->d-- : 0;
	a = pr_zs(fl->n, a, 1);
	fl->sh && fl->d < 1 ? write(1, "0", 1) : 0;
	a = pr_zs(fl->d, a, 0);
	nbr_o(s, 0, &a);
	free(s);
	free(fl);
	return (a);
}

int		print_o(int a, char *s, t_t *fl, int e)
{
	fl->d = fl->d - e;
	fl->d < 0 ? fl->d = 0 : 0;
	fl->n = fl->n - e;
	fl->sh && !fl->d ? (write(1, "0", 1)) && fl->n-- && a++ && fl->d-- : 0;
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

int		type_o(char *b, unsigned long d, t_t *fl)
{
	int		a;
	int		e;
	char	*s;

	a = 0;
	s = tob(d, 8, &e, 0);
	prs(b, &a);
	free(b);
	if (!d)
	{
		free(s);
		return (print_o0(a, d, fl, e));
	}
	if (fl->m)
		return (print_o(a, s, fl, e));
	return (print_o2(a, s, fl, e));
}

int		type_8(char *b, void *d, int f, int c)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	ignor(&fl);
	c == 79 ? fl->l = 1 : 0;
	if (((size_t)(fl->n + a + f) > 2147483647) ||
		((size_t)(fl->d + a + f) > 2147483647))
		return (-1);
	if (fl->z || fl->j || fl->ll || fl->l)
		return (type_o(b, (unsigned long)d, fl));
	if (fl->h)
		return (type_o(b, (unsigned short)d, fl));
	if (fl->hh)
		return (type_o(b, (unsigned char)d, fl));
	return (type_o(b, (unsigned)d, fl));
}
