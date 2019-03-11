/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 20:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/08 20:53:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memmove(void *dst, void *src, size_t size)
{
	t_byte	*temp_dst;
	t_byte	*temp_src;

	temp_dst = (t_byte*)dst;
	temp_src = (t_byte*)src;
	if (temp_src < temp_dst && temp_dst < temp_src + size)
	{
		temp_dst += size;
		temp_src += size;
		while (size > 0)
		{
			temp_dst--;
			temp_src--;
			*temp_dst = *temp_src;
			size--;
		}
	}
	else
		ft_memcpy(dst, src, size);
}
