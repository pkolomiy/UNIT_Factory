/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:41:17 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 19:18:43 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

char	*split2(char *b, char *s, int e)
{
	int		a;
	int		c;

	a = len_m(b);
	c = len_m(s);
	c--;
	a--;
	while (a != -1)
	{
		if (e == 2)
			E1 ? (s[c] = b[a]) : 0;
		if (e == 3)
			E1 && E2 ? (s[c] = b[a]) : 0;
		if (e == 4)
			E1 && E2 && E3 ? (s[c] = b[a]) : 0;
		E1 && E2 && E3 ? (a--) : 0;
		c--;
	}
	return (s);
}

char	*split(char *b, int e)
{
	int		a;
	char	*s;

	a = 0;
	e == 2 ? (s = (char*)malloc(17)) : 0;
	e == 3 ? (s = (char*)malloc(25)) : 0;
	e == 4 ? (s = (char*)malloc(33)) : 0;
	while (1)
	{
		(e == 2) && (e != 3) && (e != 4) && (A1) ? (s[a] = '1') : 0;
		(e == 2) && (e != 3) && (e != 4) && B1 ? (s[a] = '0') : 0;
		(e == 3) && (e != 2) && (e != 4) && (A2) ? (s[a] = '1') : 0;
		(e == 3) && (e != 2) && (e != 4) && B2 ? (s[a] = '0') : 0;
		((e == 4) && (e != 2) && (e != 3)) && (A2 || A3) ? (s[a] = '1') : 0;
		(e == 4) && (e != 2) && (e != 3) && B2 && B3 ? (s[a] = '0') : 0;
		a++;
		if ((e == 2 && a == 16) || (e == 3 && a == 24) || (e == 4 && a == 32))
			break ;
	}
	s[a] = '\0';
	return (split2(b, s, e));
}

void	get_uni(char **s, int *c, int d, int e)
{
	char	*b;
	int		a;
	char	*f;

	b = tob(d, 2, &a, 0);
	f = split(b, e);
	free(b);
	a = 0;
	while (e)
	{
		(*s)[(*c)] = btod(f, &a);
		e--;
		(*c)++;
	}
	(*c)--;
	free(f);
}

int		nob(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	if (a >= 128 && a <= 2047)
		return (2);
	if (a >= 2048 && a <= 65535)
		return (3);
	return (4);
}

int		convert(char *b, wchar_t *d, t_t *fl)
{
	int		a;
	int		c;
	char	*s;

	a = -1;
	c = 0;
	if (!d)
		return (type_ps(b, nul(), fl, 1));
	while (d[++a])
		c = c + nob(d[a]);
	s = (char*)malloc(c + 1);
	s[c] = '\0';
	a = -1;
	c = 0;
	while (d[++a])
	{
		if ((nob(d[a])) == 1)
			s[c] = d[a];
		else
			get_uni(&s, &c, d[a], nob(d[a]));
		c++;
	}
	return (type_ps(b, s, fl, 1));
}
