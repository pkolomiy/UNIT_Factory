/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 00:28:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/10 00:28:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_dir(t_dir **dir)
{
	t_dir	*temp;
	int		i;

	i = 0;
	temp = *dir;
	while (i < temp->files_counter)
	{
		ft_memdel((void**)&temp->files_arr[i]->stat);
		ft_memdel((void**)&temp->files_arr[i]->name);
		ft_memdel((void**)&temp->files_arr[i]->full_name);
		ft_memdel((void**)&temp->files_arr[i]->link);
		ft_memdel((void**)&temp->files_arr[i]->user.ptr);
		ft_memdel((void**)&temp->files_arr[i]->group.ptr);
		ft_memdel((void**)&temp->files_arr[i]);
		i++;
	}
	ft_memdel((void**)&temp->files_arr);
	ft_memdel((void**)dir);
}
