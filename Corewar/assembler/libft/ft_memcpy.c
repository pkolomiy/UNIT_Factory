/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:22:03 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/26 20:06:18 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	i = 0;
	dst_cp = dst;
	src_cp = src;
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		i++;
	}
	dst_cp[i] = '\0';
	return ((void *)dst_cp);
}
