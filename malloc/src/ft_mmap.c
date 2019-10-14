/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:38:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/28 16:16:53 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define PROT (PROT_READ | PROT_WRITE)
#define FLAGS (MAP_ANON | MAP_PRIVATE)

void	*ft_mmap(size_t size)
{
	void	*temp;

	temp = mmap(0, size, PROT, FLAGS, -1, 0);
	if (temp == MAP_FAILED)
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	return (temp);
}
