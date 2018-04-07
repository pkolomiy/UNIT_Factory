/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hash_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 19:43:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 02:45:24 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static void	delete_node(void *data, size_t data_size)
{
	(void)data_size;
	ft_memdel(&((t_node*)data)->data);
	ft_memdel(&data);
}

void		free_hash_map(t_hash *h, void (*del)(void*, size_t))
{
	int	i;

	i = -1;
	while (++i < (int)h->bucket_num)
		ft_lstdel(&(h->map[i]), del);
	ft_memdel((void**)&h->map);
	ft_memdel((void**)&h);
}

void		resize_hash_map(t_hash *h)
{
	int		i;
	t_list	*tmp;
	t_list	**saved;
	size_t	old_size;

	i = -1;
	saved = h->map;
	old_size = h->bucket_num;
	h->bucket_num *= 2;
	h->map = (t_list**)ft_memalloc(sizeof(t_list*) * h->bucket_num);
	h->filled = 0;
	while (++i < (int)old_size)
	{
		tmp = saved[i];
		while (tmp)
		{
			add_elem(h, (char*)(((t_node*)tmp->content)->key),
			((t_node*)tmp->content)->data, ((t_node*)tmp->content)->data_size);
			tmp = tmp->next;
		}
	}
	i = -1;
	while (++i < (int)old_size)
		ft_lstdel(&(saved[i]), delete_node);
	ft_memdel((void**)&saved);
}
