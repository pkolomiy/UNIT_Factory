/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_chunk_leftover.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:10:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/16 13:10:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_chunk_leftover(t_chunk *chunk, long size)
{
	t_chunk	*left_chunk;

	left_chunk = (void*)chunk + size + SHEAD;
	left_chunk->size = chunk->size - size - SHEAD;
	left_chunk->zone_type = chunk->zone_type;
	left_chunk->free = 1;
	left_chunk->next = chunk->next;
	chunk->size = size;
	chunk->next = left_chunk;
}
