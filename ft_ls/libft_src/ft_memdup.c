/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:55:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 12:55:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t size)
{
	t_byte	*dst;

	dst = (t_byte*)malloc(size);
	ft_memcpy((void*)dst, src, size);
	return (dst);
}
