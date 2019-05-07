/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:26:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 20:26:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memcpy(void *dst, void *src, size_t size)
{
	t_byte	*temp_dst;
	t_byte	*temp_src;
	size_t	step;

	temp_dst = (t_byte*)dst;
	temp_src = (t_byte*)src;
	step = sizeof(size_t);
	while (size >= step)
	{
		*((size_t*)temp_dst) = *((size_t*)temp_src);
		size -= step;
		temp_dst += step;
		temp_src += step;
	}
	while (size > 0)
	{
		*temp_dst = *temp_src;
		size--;
		temp_dst++;
		temp_src++;
	}
}
