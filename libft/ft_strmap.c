/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:17:23 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 13:51:33 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *src, char (*f)(char))
{
	t_var	v;

	v.a = -1;
	if (src && (v.str = ft_strcpy(ft_strnew(ft_strlen(src)), src)))
		while (v.str[++v.a])
			v.str[v.a] = f(v.str[v.a]);
	if (src && v.str)
		return (v.str);
	return (0);
}
