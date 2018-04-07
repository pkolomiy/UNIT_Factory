/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:15:48 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/27 16:56:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static int	hash(t_hash *hash_map, char *str)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (str[++i])
		sum += str[i];
	return (sum % hash_map->bucket_num);
}

t_node		new_node(char *key, void *data, size_t data_size)
{
	t_node	node;

	node.key = ft_strdup(key);
	node.data = (void*)malloc(data_size);
	node.data = ft_memcpy(node.data, data, data_size);
	node.data_size = data_size;
	return (node);
}

void		add_elem(t_hash *hash_map, char *key, void *data, size_t data_size)
{
	int		index;
	t_node	node;

	if (!ft_strlen(key) || data == NULL || data_size == 0)
		return ;
	if ((double)hash_map->filled / (double)hash_map->bucket_num > 0.7)
		resize_hash_map(hash_map);
	index = hash(hash_map, key);
	node = new_node(key, data, data_size);
	if (hash_map->map[index] == NULL)
	{
		hash_map->map[index] = ft_lstnew((void*)&node, sizeof(t_node));
		if (hash_map->all_index == NULL)
			hash_map->all_index = ft_lstnew((void*)&index, sizeof(int));
		else
			ft_lstadd(&(hash_map->all_index),
			ft_lstnew((void*)&index, sizeof(int)));
	}
	else
		ft_lstadd(&(hash_map->map[index]),
			ft_lstnew((void*)&node, sizeof(t_node)));
	hash_map->filled++;
}

void		*get_elem(t_hash *hash_map, char *key)
{
	int		index;
	t_list	*tmp;

	if (!ft_strlen(key))
		return (NULL);
	index = hash(hash_map, key);
	if (hash_map->map[index] == NULL)
		return (NULL);
	tmp = hash_map->map[index];
	while (tmp)
	{
		if (!ft_strcmp(((t_node*)tmp->content)->key, key))
			return (((t_node*)tmp->content)->data);
		tmp = tmp->next;
	}
	return (NULL);
}

t_hash		*new_hash_map(size_t size)
{
	t_hash	*new;

	if (size == 0)
		size = 128;
	new = (t_hash*)malloc(sizeof(t_hash));
	new->filled = 0;
	new->all_index = NULL;
	new->bucket_num = size;
	new->map = (t_list**)ft_memalloc(sizeof(t_list*) * size);
	return (new);
}
