/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:55:43 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/20 01:25:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = -1;
	if (dst && src && src < dst && dst < src + len)
		while (len--)
			*((t_uc*)dst + len) = *((t_uc*)src + len);
	else if (dst && src)
		while ((size_t)++i < len)
			*((t_uc*)dst + i) = *((t_uc*)src + i);
	if (dst && src)
		return (dst);
	return (0);
}
