/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:19:13 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 17:19:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	ignor(t_t **fl)
{
	(*fl)->p ? ((*fl)->sp = 0) : 0;
	(*fl)->m ? ((*fl)->zr = 0) : 0;
	(*fl)->d2 ? ((*fl)->zr = 0) : 0;
	((*fl)->zr) && (!(*fl)->n) ? (*fl)->zr = 0 : 0;
}

void	prs(char *b, int *a)
{
	while (b[(*a)] != '%')
	{
		write(1, &b[(*a)], 1);
		(*a)++;
	}
}

int		pr_zs(int n, int a, int t)
{
	if (t)
	{
		while (n-- > 0)
		{
			write(1, " ", 1);
			a++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			write(1, "0", 1);
			a++;
		}
	}
	return (a);
}

int		empty(int c, int d)
{
	if (!c || (c == '%' && !d))
	{
		write(1, "", 0);
		return (1);
	}
	return (0);
}

int		len_s(long a)
{
	int		b;

	b = 0;
	if (!a)
		return (1);
	if (a == (-9223372036854775807 - 1))
		return (20);
	if (a < 0)
	{
		a *= -1;
		b++;
	}
	while (a)
	{
		a /= 10;
		b++;
	}
	return (b);
}
