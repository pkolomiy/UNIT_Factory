/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:17:58 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 19:06:42 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

char	*nul(void)
{
	char	*s;

	s = (char*)malloc(7);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = '\0';
	return (s);
}

int		btod2(char *s)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = 0;
	b = 128;
	while (s[a])
	{
		c = c + (b * (s[a] - 48));
		b = b / 2;
		a++;
	}
	free(s);
	return (c);
}

int		btod(char *b, int *a)
{
	char	*s;
	int		c;

	c = 0;
	s = (char*)malloc(9);
	while (c != 8)
	{
		s[c] = b[(*a)];
		(*a)++;
		c++;
	}
	s[c] = '\0';
	return (btod2(s));
}

int		type_p(char *b, void *d, int f)
{
	int		a;
	t_t		*fl;

	a = 0;
	fl = str();
	while (b[a] != '%')
		a++;
	c_flag(b, (a + 1), &fl);
	ignor(&fl);
	fl->sh = 1;
	fl->p = 120;
	if (((size_t)(fl->n + a + f) > 2147483647))
		return (-1);
	return (type_x(b, (unsigned long)d, fl, 112));
}

int		any_type(char *b, char c, void *d, int f)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (type_sig(b, d, f, c));
	if (c == 'u' || c == 'U')
		return (type_uns(b, d, f, c));
	if (c == 'o' || c == 'O')
		return (type_8(b, d, f, c));
	if (c == 'x' || c == 'X')
		return (type_16(b, d, f, c));
	if (c == 'c' || c == 'C')
		return (type_c(b, d, f));
	if (c == 'p')
		return (type_p(b, d, f));
	if (c == 's' || c == 'S')
		return (type_s(b, d, f, c));
	return (-1);
}
