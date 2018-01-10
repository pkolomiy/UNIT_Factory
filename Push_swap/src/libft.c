/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:08:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/07 23:31:37 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		nbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		nbr(n / 10);
	if (n >= 10)
		nbr(n % 10);
	if (n < 10 && n > -1)
	{
		n += 48;
		write(1, &n, 1);
	}
}

_Bool		cmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

void		init_main(t_main *m)
{
	m->a = NULL;
	m->b = NULL;
	m->ins = NULL;
	m->a_len = 0;
	m->b_len = 0;
	m->final = 0;
}
