/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:03:52 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/20 01:34:21 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	t_var	v;

	if (str)
	{
		v.i = 0;
		v.a = ft_strlen(str) - 1;
		while (WS(str[v.i]))
			v.i++;
		while (v.a > 0 && WS(str[v.a]))
			v.a--;
		if (!v.i && (v.a == (int)ft_strlen(str) - 1))
			return (ft_strdup(str));
		else if (v.i == ft_strlen(str) && v.a < 1)
			return (ft_strnew(1));
		return (ft_strsub(str, v.i, (v.a - v.i + 1)));
	}
	return (0);
}
