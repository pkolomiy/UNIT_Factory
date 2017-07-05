/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:09:14 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/19 19:26:12 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	t_var	v;

	v = ft_var();
	str ? (v.str = ft_strdup(str)) : 0;
	v.str ? (v.i = ft_strlen(v.str) - 1) : 0;
	while (v.str && v.j < v.i)
	{
		v.c = v.str[v.j];
		v.str[v.j++] = v.str[v.i];
		v.str[v.i--] = v.c;
	}
	return (v.str);
}
