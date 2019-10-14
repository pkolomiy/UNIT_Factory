/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:06:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/28 14:06:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define HEX "0123456789ABCDEF"

static void		write_base(size_t num, size_t base)
{
	if (num >= base)
		write_base(num / base, base);
	write(1, &HEX[num % base], 1);
}

static size_t	show_chunk(t_chunk *chunk)
{
	size_t	size;

	size = 0;
	while (chunk)
	{
		write(1, "0x", 2);
		write_base((size_t)((void *)chunk + HEAD), 16);
		write(1, " - ", 4);
		write(1, "0x", 2);
		write_base((size_t)((void *)chunk + HEAD + chunk->size), 16);
		write(1, " : ", 4);
		write_base((size_t)chunk->size, 10);
		write(1, " bytes\n", 7);
		size += chunk->size;
		chunk = chunk->next;
	}
	return (size);
}

static size_t	show_zone(t_zone *zone, char *zone_name)
{
	size_t	size;

	size = 0;
	while (zone)
	{
		write(1, zone_name, zone_name[0] == 'T' ? 4 : 5);
		write(1, " : ", 3);
		write(1, "0x", 2);
		write_base((size_t)zone, 16);
		write(1, "\n", 1);
		size += show_chunk(zone->chunks);
		zone = zone->next;
	}
	return (size);
}

void			show_alloc_mem(void)
{
	size_t	total;

	total = 0;
	pthread_mutex_lock(&g_mutex);
	total += show_zone(global()->tiny, "TINY");
	total += show_zone(global()->small, "SMALL");
	if (global()->large)
	{
		write(1, "LARGE : 0x", 10);
		write_base((size_t)global()->large, 16);
		write(1, "\n", 1);
		total += show_chunk(global()->large);
	}
	write(1, "Total : ", 8);
	write_base(total, 10);
	write(1, " bytes\n", 7);
	pthread_mutex_unlock(&g_mutex);
}
