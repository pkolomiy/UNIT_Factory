/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:15:13 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/26 19:21:25 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static void	print_node(t_list *node)
{
	ft_putstr(((t_node*)(node->content))->key);
	ft_putstr(" => ");
	ft_putstr((char*)(((t_node*)(node->content))->data));
	ft_putstr("; ");
}

void		print_hash(t_hash *map)
{
	int	i;

	i = -1;
	while (++i < (int)map->bucket_num)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		if (map->map[i] == NULL)
			ft_putstr("NULL\n");
		else
		{
			ft_lstiter(map->map[i], print_node);
			ft_putstr("\n");
		}
	}
}
