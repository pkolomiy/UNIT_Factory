/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:17:02 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/03 20:49:15 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	i = 0;
	dst_cp = dst;
	src_cp = src;
	if (n == 0)
		return (0);
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		if (src_cp[i] == (unsigned char)c)
			return ((void *)&dst_cp[i + 1]);
		i++;
	}
	return (0);
}
