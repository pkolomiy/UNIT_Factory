/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 00:35:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/15 00:35:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	*new_chunk(t_zone *zone, int zone_type, long size)
{
	zone->chunks = (void*)zone + sizeof(t_zone);
	zone->chunks->free = 0;
	zone->chunks->zone_type = zone_type;
	zone->chunks->size = size;
	zone->chunks->next = NULL;
	return (before_return(zone->chunks));
}

static void	*create_zone(t_zone **zone, int zone_type, long size)
{
	t_zone	*temp;
	int		page;
	size_t	zone_size;

	page = getpagesize();
	zone_size = zone_type == SMALL ? SMALL_SIZE : TINY_SIZE;
	zone_size = PAGE_ROUND(((zone_size * ZONES) + (HEAD * ZONES)), page);
	if (!(temp = ft_mmap(zone_size)))
		return (NULL);
	temp->free_size = (long)(zone_size - size - HEAD - sizeof(t_zone));
	temp->next = NULL;
	*zone = temp;
	return (new_chunk(temp, zone_type, size));
}

static void	*add_to_zone_end(t_zone *zone, t_chunk *chunk, long size)
{
	zone->free_size -= (size + SHEAD);
	chunk->next = (void*)chunk + chunk->size + SHEAD;
	chunk->next->size = size;
	chunk->next->free = 0;
	chunk->next->next = NULL;
	return (before_return(chunk->next));
}

static void	*find_free_space(t_zone *zone, int zone_type, long size)
{
	t_chunk	*temp;

	if (!(temp = zone->chunks))
		return (new_chunk(zone, zone_type, size));
	while (temp)
	{
		if (temp->free && temp->size >= size)
		{
			temp->free = 0;
			if (temp->size - size > SHEAD)
				add_chunk_leftover(temp, size);
			return (before_return(temp));
		}
		if (!temp->next && zone->free_size >= size + SHEAD)
			return (add_to_zone_end(zone, temp, size));
		temp = temp->next;
	}
	return (NULL);
}

void		*malloc_zone(t_zone **zone, int zone_type, long size)
{
	t_zone	*temp;
	void	*res;

	if (!(*zone))
		return (create_zone(zone, zone_type, size));
	temp = *zone;
	while (temp)
	{
		if ((res = find_free_space(temp, zone_type, size)))
			return (res);
		if (!temp->next)
			return (create_zone(&temp->next, zone_type, size));
		temp = temp->next;
	}
	return (NULL);
}
