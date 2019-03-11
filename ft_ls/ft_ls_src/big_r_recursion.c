/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 23:02:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 23:02:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	big_r_recursion(t_ls_flags flags, char *name, int arg)
{
	t_dir	*dir;
	int		i;

	i = 0;
	if ((dir = read_whole_dir(flags, name)) != NULL)
	{
		show_dir(flags, dir, arg);
		while (i < dir->files_counter)
		{
			if (dir->files_arr[i]->type == 'd' &&
			ft_strcmp(dir->files_arr[i]->name, ".") &&
			ft_strcmp(dir->files_arr[i]->name, ".."))
			{
				ft_printf("\n%s:\n", dir->files_arr[i]->full_name);
				big_r_recursion(flags, dir->files_arr[i]->full_name, 0);
			}
			i++;
		}
		free_dir(&dir);
	}
}
