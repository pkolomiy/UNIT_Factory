/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:33:03 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/18 13:02:04 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	t_var	v;

	v = ft_var();
	v.c = 1;
	v.b = 1;
	while (WS(str[v.a]))
		v.a++;
	(str[v.a] == 45) ? (v.c = -1) : 0;
	(str[v.a] == '+' || str[v.a] == '-') ? (v.a++) : 0;
	while (ft_isdigit(str[v.a]) && v.b == 1)
	{
		v.l = (v.l * 10) + ((int)str[v.a++] - 48);
		if (v.c == -1)
			(ft_nbrlen(v.l) == 19) && ft_isdigit(str[v.a]) ? (v.b = 0) : 0;
		else
			(ft_nbrlen(v.l) == 19) && ft_isdigit(str[v.a]) ? (v.b = -1) : 0;
		(v.c == -1 && v.l > MAXL) ? (v.b = 0) : 0;
		(v.c == 1 && v.l > MAXL) ? (v.b = -1) : 0;
	}
	if (v.b < 0)
		return (-1);
	return (((int)v.l * v.c) * v.b);
}
