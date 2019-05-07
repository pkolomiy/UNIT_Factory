/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:52:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 16:52:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(str);
	dst = (char*)malloc(len + 1);
	ft_memcpy((void*)dst, str, len);
	dst[len] = '\0';
	return (dst);
}
