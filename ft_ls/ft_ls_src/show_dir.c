/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 23:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 23:07:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		my_perror(char *s)
{
	write(2, "ft_ls: ", 7);
	perror(s);
}

void		show_dir(t_ls_flags flags, t_dir *dir, int arg)
{
	int	i;

	i = 0;
	dir->files_arr = get_files_arr(flags, dir);
	if (dir->files_arr && arg && flags.argc > 1 && dir->dir)
		ft_printf("%s%s:\n", arg == 1 ? "" : "\n", dir->name);
	if (flags.l && dir->files_arr)
		show_dir_l_flag(dir);
	else if (dir->files_arr)
	{
		while (i < dir->files_counter)
		{
			ft_printf("%s\n", dir->files_arr[i]->name);
			i++;
		}
	}
}
