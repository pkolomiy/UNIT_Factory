/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:53:38 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/10 13:23:07 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	pr_st(char *s, int d, int *a)
{
	int		b;

	b = 0;
	if (d == -1)
	{
		while (s[b])
		{
			write(1, &s[b], 1);
			b++;
		}
	}
	while (d > 0 && s[b])
	{
		write(1, &s[b], 1);
		b++;
		d--;
	}
	(*a) = (*a) + b;
}

void	nbr_o(char *s, int num, int *a)
{
	int		c;

	c = 0;
	if (num)
		(*a) = pr_zs(num, (*a), 0);
	while (s[c])
	{
		write(1, &s[c], 1);
		c++;
	}
}

void	nbr_u(unsigned long n, int num, int *a)
{
	char c;

	if (num)
		(*a) = pr_zs(num, (*a), 0);
	if (n >= 10)
	{
		nbr_u((n / 10), 0, a);
		nbr_u((n % 10), 0, a);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

void	nbr_s(long n, int num, int *a)
{
	char c;

	if (n == (-9223372036854775807 - 1))
	{
		(num) ? write(1, "-", 1) && ((*a) = pr_zs(num, (*a), 0)) &&
			write(1, "9", 1) && (num = 0) : write(1, "-9", 2);
		n = 223372036854775808;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (num)
		(*a) = pr_zs(num, (*a), 0);
	if (n >= 10)
	{
		nbr_s((n / 10), 0, a);
		nbr_s((n % 10), 0, a);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}
