/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:05:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/11 13:05:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <pthread.h>
# include <sys/mman.h>

# define TINY_SIZE 128
# define SMALL_SIZE 2048

# define ZONES 100

# define PAGE_ROUND(s, p) (s + !!(s % p) * (p - s % p))

typedef struct s_chunk	t_chunk;
typedef struct s_zone	t_zone;
typedef struct s_global	t_global;

enum {LOCK = 0, UNLOCK = 1};
enum {TINY, SMALL, LARGE};

# define HEAD sizeof(t_chunk)
# define SHEAD (long)(sizeof(t_chunk))

struct		s_chunk
{
	_Bool	free;
	int		zone_type;
	long	size;
	t_chunk	*next;
};

struct		s_zone
{
	long	free_size;
	t_chunk	*chunks;
	t_zone	*next;
};

struct		s_global
{
	t_zone	*tiny;
	t_zone	*small;
	t_chunk	*large;
};

void		*malloc(size_t size);
void		*malloc_zone(t_zone **zone, int zone_size, long size);

void		*realloc(void *ptr, size_t size);
void		*try_realloc_free_space(t_zone *zone, t_chunk *cur, t_chunk *prev,
									long new_size);

void		free(void *ptr);

void		show_alloc_mem(void);

t_global	*global(void);
void		add_chunk_leftover(t_chunk *chunk, long size);

void		*ft_mmap(size_t size);
void		*before_return(t_chunk *chunk);

void		ft_memcpy(void *dst, void *src, size_t size);

extern pthread_mutex_t	g_mutex;

#endif
