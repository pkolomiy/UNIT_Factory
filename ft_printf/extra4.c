/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:19:20 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 17:19:20 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		len_m(char *s)
{
	int		a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

void	fx(unsigned long d, unsigned long b, char *s, int *a)
{
	char	*ss;

	ss = "0123456789abcdef";
	(d >= b) ? fx(d / b, b, s, a) : 0;
	s[(*a)++] = ss[(d % b)];
}

void	fxb(unsigned long d, unsigned long b, char *s, int *a)
{
	char	*ss;

	ss = "0123456789ABCDEF";
	(d >= b) ? fxb(d / b, b, s, a) : 0;
	s[(*a)++] = ss[(d % b)];
}

char	*tob(unsigned long d, int b, int *e, int c)
{
	int				a;
	char			*s;

	a = 0;
	s = (char*)malloc(32);
	c == 120 ? fx(d, b, s, &a) : fxb(d, b, s, &a);
	s[a] = '\0';
	(*e) = a;
	return (s);
}

int		len_u(unsigned long a)
{
	int		b;

	b = 0;
	if (!a)
		return (1);
	while (a)
	{
		a /= 10;
		b++;
	}
	return (b);
}
