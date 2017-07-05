/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:05:45 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 18:09:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		just_char(char *b, int d)
{
	int		a;

	a = 0;
	while (b[a] != '%' && b[a])
		a++;
	if (!b[a] || !b[a + 1])
	{
		if (a < 2147483647)
		{
			a = -1;
			while (b[++a] && b[a] != '%')
				write(1, &b[a], 1);
			free(b);
			return (a);
		}
		free(b);
		return (-1);
	}
	return (just_char2(b, a + 1, d));
}

int		find(const char *s, int *d, int *g)
{
	int		e;

	e = 1;
	while (s[(*d)] && s[(*d)] != '%')
		if (s[(*d)++] != '%')
			e++;
	if (s[(*d)] == '%')
	{
		e++;
		(*d)++;
		(*g) = 1;
	}
	while ((D1(s[(*d)]) || D2(s[(*d)]) || D3(s[(*d)]) ||
			D4(s[(*d)]) || D5(s[(*d)])) && s[(*d)])
	{
		e++;
		(*d)++;
	}
	return (e);
}

char	*arr(int *e, int d, int *a, const char *s)
{
	char	*b;

	d = 0;
	s[(*a) + 1] == 0 ? (*e) = 1 : 0;
	b = (char*)malloc((*e) + 1);
	while (d < (*e) && s[(*a)])
		b[d++] = s[(*a)++];
	b[d] = '\0';
	return (b);
}

int		first(const char *s, int *a, va_list ap, int f)
{
	char	*b;
	int		d;
	int		e;
	int		g;
	
	g = 0;
	while (s[(*a)])
	{
		d = (*a);
		e = find(s, &d, &g);
		b = arr(&e, d, a, s);
		e--;
		if ((C1(b[e]) || C2(b[e]) || C3(b[e]) || C4(b[e])) && g)
			return (any_type(b, b[e], va_arg(ap, void *), f));
		else
			return (just_char(b, f));
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	int			a;
	int			b;
	int			d;

	a = 0;
	d = 0;
	va_start(ap, s);
	if (empty(s[a], s[a + 1]))
		return (0);
	while (s[a])
	{
		if ((b = first(s, &a, ap, d)) != -1)
			d = d + b;
		else
			return (-1);
	}
	va_end(ap);
	return (d);
}
