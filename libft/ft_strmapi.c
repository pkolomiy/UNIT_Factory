/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:49:23 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/18 13:20:10 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	t_var	v;

	v.a = -1;
	if (src && (v.str = ft_strcpy(ft_strnew(ft_strlen(src)), src)))
		while (v.str[++v.a])
			v.str[v.a] = f((unsigned int)v.a, v.str[v.a]);
	if (src && v.str)
		return (v.str);
	return (0);
}
