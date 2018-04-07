/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:13:34 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 02:45:14 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H

# include "../libft.h"

typedef struct	s_node
{
	size_t		data_size;
	void		*data;
	char		*key;
}				t_node;

typedef struct	s_hash
{
	size_t		bucket_num;
	size_t		filled;
	t_list		*all_index;
	t_list		**map;
}				t_hash;

void			print_hash(t_hash *map);
void			resize_hash_map(t_hash *h);
void			*get_elem(t_hash *hash_map, char *key);
void			add_elem(t_hash *hash_map, char *key, void *data,
						size_t data_size);
void			free_hash_map(t_hash *h, void (*del)(void*, size_t));

t_hash			*new_hash_map(size_t size);

#endif
