/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:55:45 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/15 23:05:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (!s1 || !s2)
		return (0);
	while (a < n)
	{
		if (*s1 != *s2)
			return (0);
		if (!*s1 && !*s2)
			return (1);
		s1++;
		s2++;
		a++;
	}
	return (1);
}
