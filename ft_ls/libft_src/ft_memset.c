/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/01 20:53:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *ptr, t_byte b, size_t size)
{
	t_byte	*dst;

	dst = (t_byte*)ptr;
	while (size)
	{
		*dst = b;
		dst++;
		size--;
	}
}
