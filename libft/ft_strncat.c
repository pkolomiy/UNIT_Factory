/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:49:06 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 13:00:06 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	t_var	v;

	if (!s1)
		return (0);
	if (s2)
	{
		v.i = ft_strlen(s1);
		v.j = 0;
		while (v.j < n && s2[v.j])
			s1[v.i++] = s2[v.j++];
		s1[v.i] = '\0';
	}
	return (s1);
}
