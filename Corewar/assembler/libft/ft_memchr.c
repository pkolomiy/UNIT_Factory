/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:14:24 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/04 13:30:18 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cp;

	s_cp = (unsigned char *)s;
	while (n--)
	{
		if (*s_cp == (unsigned char)c)
			return ((void *)s_cp);
		s_cp++;
	}
	return (0);
}
