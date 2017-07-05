/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:34:09 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/20 01:59:09 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(t_var v)
{
	while (*v.str)
	{
		while (*v.str && *v.str == v.c)
			v.str++;
		(*v.str) && (*v.str != v.c) ? (v.a++) : 0;
		while (*v.str && *v.str != v.c)
			v.str++;
	}
	return (v.a);
}

static char	*array(char *str, t_var v)
{
	v.a = 0;
	while (str[v.a] != v.c && str[v.a])
		v.a++;
	return (ft_strncpy(ft_strnew(v.a), str, v.a));
}

char		**ft_strsplit(char const *str, char c)
{
	t_var	v;

	v.c = c;
	v.a = 0;
	v.str = (char*)str;
	if (str && c)
	{
		v.str2 = (char**)malloc(sizeof(char*) * (count(v) + 1));
		while (v.str2 && *v.str)
		{
			while (*v.str && *v.str == v.c)
				v.str++;
			(*v.str) && (*v.str != v.c) ? (v.str2[v.a++] = array(v.str, v)) : 0;
			while (*v.str && *v.str != v.c)
				v.str++;
		}
		v.str2 ? (v.str2[v.a] = 0) : 0;
		return (v.str2);
	}
	return (0);
}
