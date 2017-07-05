/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:16:59 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/21 18:12:54 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(dst);
	if ((dst && src) && i > size)
		return (size + ft_strlen(src));
	(dst && src) && ((int)(size - i - 1) >= 0) ?
		ft_strncat(dst, src, size - i - 1) : 0;
	if (dst && src)
		return (i + ft_strlen(src));
	return (0);
}
