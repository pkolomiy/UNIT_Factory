/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:03:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/11 13:03:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	*malloc_large(size_t size)
{
	t_chunk	*temp;
	t_chunk	*temp2;
	int		page;

	page = getpagesize();
	temp2 = global()->large;
	if (!(temp = ft_mmap(PAGE_ROUND((size + HEAD), page))))
		return (NULL);
	temp->free = 0;
	temp->zone_type = LARGE;
	temp->size = size;
	temp->next = NULL;
	if (!temp2)
		global()->large = temp;
	else
	{
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp;
	}
	return (before_return(temp));
}

void		*malloc(size_t size)
{
	pthread_mutex_lock(&g_mutex);
	if (size <= TINY_SIZE)
		return (malloc_zone(&global()->tiny, TINY, (long)size));
	else if (size <= SMALL_SIZE)
		return (malloc_zone(&global()->small, SMALL, (long)size));
	return (malloc_large(size));
}
