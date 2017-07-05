/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:50:18 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 12:52:18 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (src && ++i != n)
		if (((t_uc*)src)[i] == (t_uc)c)
			return (((t_uc*)src) + i);
	return (0);
}
