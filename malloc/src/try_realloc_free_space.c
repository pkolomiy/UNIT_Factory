/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_realloc_free_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:37:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/28 16:18:13 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define ZONE_END_HAS_FREE_SPACE 1
#define NEXT_NEIGHBOUR_FREE 2
#define CURRENT_HAS_ENOUGH_SPACE 3

static void	*reallocate_neighbours(t_zone *zone, t_chunk *cur, t_chunk *prev,
									long new_size)
{
	prev->size += (cur->size + SHEAD);
	if (cur->next && cur->next->free)
	{
		prev->size += (cur->next->size + SHEAD);
		cur->next = cur->next->next;
	}
	prev->next = cur->next;
	if (prev->next && prev->size - new_size > SHEAD)
		add_chunk_leftover(prev, new_size);
	else if (!prev->next && prev->size - new_size > SHEAD)
	{
		zone->free_size += (prev->size - new_size);
		prev->size = new_size;
	}
	ft_memcpy((void*)prev + HEAD, (void*)cur + HEAD, (size_t)cur->size);
	return ((void*)prev + HEAD);
}

static void	*reallocate(int option, t_zone *zone, t_chunk *cur, long new_size)
{
	if (option == ZONE_END_HAS_FREE_SPACE)
	{
		zone->free_size += (cur->size - new_size);
		cur->size = new_size;
	}
	if (option == NEXT_NEIGHBOUR_FREE)
	{
		cur->size += (cur->next->size + SHEAD);
		cur->next = cur->next->next;
	}
	if (option == NEXT_NEIGHBOUR_FREE || option == CURRENT_HAS_ENOUGH_SPACE)
	{
		if (cur->size - new_size > SHEAD)
			add_chunk_leftover(cur, new_size);
	}
	return ((void*)cur + HEAD);
}

void		*try_realloc_free_space(t_zone *zone, t_chunk *cur, t_chunk *prev,
					long new_size)
{
	if (!cur->next && (zone->free_size >= new_size - cur->size))
		return (reallocate(ZONE_END_HAS_FREE_SPACE, zone, cur, new_size));
	if (cur->next && cur->next->free && cur->size + cur->next->size +
		SHEAD >= new_size)
		return (reallocate(NEXT_NEIGHBOUR_FREE, zone, cur, new_size));
	if (cur->size > new_size)
		return (reallocate(CURRENT_HAS_ENOUGH_SPACE, zone, cur, new_size));
	if (prev && prev->free && ((prev->size + SHEAD + cur->size >= new_size) ||
		(cur->next && cur->next->free && prev->size + (SHEAD * 2) +
		cur->size + cur->next->size >= new_size)))
		return (reallocate_neighbours(zone, cur, prev, new_size));
	return (NULL);
}
