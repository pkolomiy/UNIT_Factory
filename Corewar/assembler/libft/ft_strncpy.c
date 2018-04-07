/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:12:57 by dmulish           #+#    #+#             */
/*   Updated: 2017/02/10 14:49:23 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!src)
		return (0);
	while (src[++i] && i < len)
		dst[i] = src[i];
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
