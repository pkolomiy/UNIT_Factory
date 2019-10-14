/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 01:55:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/15 01:55:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define TRY_NEXT_ZONE 0
#define FREED 1
#define FREE_ZONE 2

static void	free_large(t_chunk *chunk, int page)
{
	t_chunk	*cur;
	t_chunk	*prev;

	prev = NULL;
	cur = global()->large;
	while (cur)
	{
		if (cur == chunk)
		{
			if (prev)
				prev->next = cur->next;
			else
				global()->large = cur->next;
			munmap((void*)chunk, PAGE_ROUND((chunk->size + SHEAD), page));
			break ;
		}
		prev = cur;
		cur = cur->next;
	}
}

static int	merge_free_neighbours(t_chunk *cur, t_chunk *prev)
{
	cur->free = 1;
	if (cur->next->free)
	{
		cur->size += (cur->next->size + SHEAD);
		cur->next = cur->next->next;
	}
	if (prev && prev->free)
	{
		prev->size += (cur->size + SHEAD);
		prev->next = cur->next;
	}
	return (FREED);
}

static int	free_in_chunks(t_zone *zone, t_chunk *chunk)
{
	t_chunk	*cur;
	t_chunk	*prev;

	prev = NULL;
	cur = zone->chunks;
	while (cur)
	{
		if (cur == chunk)
		{
			if (!cur->next && prev)
			{
				prev->next = NULL;
				zone->free_size += (cur->size + SHEAD);
				return (FREED);
			}
			else if (!cur->next && !prev)
				return (FREE_ZONE);
			return (merge_free_neighbours(cur, prev));
		}
		prev = cur;
		cur = cur->next;
	}
	return (TRY_NEXT_ZONE);
}

static void	free_in_zone(t_zone **zone, t_chunk *chunk)
{
	int		status;
	t_zone	*cur;

	cur = *zone;
	while (cur)
	{
		status = free_in_chunks(cur, chunk);
		if (status == FREE_ZONE)
		{
			cur->free_size += (cur->chunks->size + SHEAD);
			cur->chunks = NULL;
		}
		if (status != TRY_NEXT_ZONE)
			break ;
		cur = cur->next;
	}
}

void		free(void *ptr)
{
	t_chunk	*temp;
	int		page;

	page = getpagesize();
	if (!ptr)
		return ;
	pthread_mutex_lock(&g_mutex);
	temp = ptr - HEAD;
	if (temp->zone_type == TINY)
		free_in_zone(&global()->tiny, temp);
	else if (temp->zone_type == SMALL)
		free_in_zone(&global()->small, temp);
	else
		free_large(temp, page);
	pthread_mutex_unlock(&g_mutex);
}
