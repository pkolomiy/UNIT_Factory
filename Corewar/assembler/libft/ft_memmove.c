/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:09:38 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/13 16:08:45 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(unsigned char *dst, const unsigned char *src)
{
	if (src < dst)
		return (1);
	else
		return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	i = 0;
	dst_cp = dst;
	src_cp = src;
	while (i < len)
	{
		if (check(dst_cp, src_cp) == 1)
			dst_cp[len - i - 1] = src_cp[len - i - 1];
		else
			dst_cp[i] = src_cp[i];
		i++;
	}
	return ((void *)dst_cp);
}
