/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:50:35 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 13:00:06 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dst || !src)
		return (0);
	while (++i < len && src[i])
		dst[i] = src[i];
	--i;
	while (++i < len)
		dst[i] = 0;
	return (dst);
}
