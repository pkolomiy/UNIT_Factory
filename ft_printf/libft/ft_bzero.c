/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:20:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 19:20:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	t_byte	*mem;
	size_t	step;

	mem = (t_byte*)ptr;
	step = sizeof(size_t);
	while (size >= step)
	{
		*((size_t*)mem) = 0;
		size -= step;
		mem += step;
	}
	while (size > 0)
	{
		*mem = 0;
		size--;
		mem++;
	}
}
