/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:12:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/28 16:17:44 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		*realloc_from_new(t_chunk *chunk, size_t new_size)
{
	void	*new_alloc;

	pthread_mutex_unlock(&g_mutex);
	if (!(new_alloc = malloc(new_size)))
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	if ((size_t)chunk->size < new_size)
		ft_memcpy(new_alloc, (void*)chunk + HEAD, (size_t)chunk->size);
	else
		ft_memcpy(new_alloc, (void*)chunk + HEAD, new_size);
	pthread_mutex_unlock(&g_mutex);
	free((void*)chunk + HEAD);
	pthread_mutex_lock(&g_mutex);
	return (new_alloc);
}

static void		*from_zone(t_zone *zone, t_chunk *chunk, size_t new_size)
{
	t_chunk	*cur;
	t_chunk	*prev;
	void	*res;

	while (zone)
	{
		prev = NULL;
		cur = zone->chunks;
		while (cur)
		{
			if (cur == chunk &&
				(res = try_realloc_free_space(zone, cur, prev, new_size)))
				return (res);
			prev = cur;
			cur = cur->next;
		}
		zone = zone->next;
	}
	return (realloc_from_new(chunk, new_size));
}

static t_chunk	*valid_ptr(void *ptr, t_zone *zone, t_chunk *chunks)
{
	t_chunk	*temp;

	temp = ptr - HEAD;
	while (zone)
	{
		chunks = zone->chunks;
		while (chunks)
		{
			if (chunks == temp)
				return (temp);
			chunks = chunks->next;
		}
		zone = zone->next;
	}
	while (chunks)
	{
		if (chunks == temp)
			return (temp);
		chunks = chunks->next;
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	t_chunk	*temp;
	void	*new_alloc;

	if (!ptr)
		return (malloc(size));
	pthread_mutex_lock(&g_mutex);
	if (!valid_ptr(ptr, NULL, global()->large) &&
		!valid_ptr(ptr, global()->small, NULL) &&
		!valid_ptr(ptr, global()->tiny, NULL))
		return (NULL);
	temp = ptr - HEAD;
	if (temp->size == (long)size)
		new_alloc = ptr;
	else if (temp->zone_type == TINY)
		new_alloc = from_zone(global()->tiny, temp, size);
	else if (temp->zone_type == SMALL)
		new_alloc = from_zone(global()->small, temp, size);
	else
		new_alloc = realloc_from_new(temp, size);
	pthread_mutex_unlock(&g_mutex);
	return (new_alloc);
}
