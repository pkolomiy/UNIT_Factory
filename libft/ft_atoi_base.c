/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:39:07 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/19 18:44:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi_base(const char *str, char base)
{
	t_var	v;

	if (base < 2 || base > 36 || !str)
		return (0);
	v = ft_var();
	v.c = 1;
	v.a = 1;
	while (WS(str[v.i]))
		v.i++;
	(str[v.i] == 45) ? (v.c = -1) : 0;
	(str[v.i] == '+' || str[v.i] == '-') ? (v.i++) : 0;
	v.b = ft_base_converter(str[v.i++]);
	while (v.b >= 0 && v.b < base && v.a == 1)
	{
		v.l = (v.l * base) + v.b;
		v.b = ft_base_converter(str[v.i++]);
		(v.c == -1 && v.l > MAXL + 1) ? (v.a = 0) : 0;
		(v.c == 1 && v.l > MAXL) ? (v.a = -1) : 0;
	}
	if (v.a < 0)
		return (-1);
	return ((v.l * v.c) * v.a);
}
