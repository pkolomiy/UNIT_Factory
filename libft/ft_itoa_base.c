/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:22:19 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/18 15:57:17 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(unsigned long n, t_var *v)
{
	(n >= (t_ul)v->b) ? convert(n / v->b, v) : 0;
	v->str[v->i++] = (v->c == 1) ? v->tmp[(n % v->b)] : v->tmp2[(n % v->b)];
}

char		*ft_itoa_base(unsigned long n, char base, char size)
{
	t_var	v;

	v = ft_var();
	v.b = base;
	v.c = size;
	v.tmp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	v.tmp2 = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (v.b < 2 || v.b > 36 || !(v.str = (char*)malloc(65)))
		return (0);
	convert(n, &v);
	v.str[v.i] = 0;
	return (v.str);
}
