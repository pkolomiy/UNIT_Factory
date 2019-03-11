/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:36:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/10 19:36:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	calculate_padding(t_dir *dir)
{
	int		i;
	size_t	temp;

	i = 0;
	while (i < dir->files_counter)
	{
		temp = ft_nbrlen((size_t)dir->files_arr[i]->stat->st_nlink);
		if (temp > dir->padding.nlink)
			dir->padding.nlink = (t_byte)temp;
		if ((t_byte)dir->files_arr[i]->user.size > dir->padding.pw_name)
			dir->padding.pw_name = (t_byte)dir->files_arr[i]->user.size;
		if ((t_byte)dir->files_arr[i]->group.size > dir->padding.gr_name)
			dir->padding.gr_name = (t_byte)dir->files_arr[i]->group.size;
		temp = ft_nbrlen((size_t)major(dir->files_arr[i]->stat->st_rdev));
		if (temp > dir->padding.dev_maj)
			dir->padding.dev_maj = (t_byte)temp;
		temp = ft_nbrlen((size_t)minor(dir->files_arr[i]->stat->st_rdev));
		if (temp > dir->padding.dev_min)
			dir->padding.dev_min = (t_byte)temp;
		i++;
	}
}

void		show_dev(t_dir *dir)
{
	int		i;
	t_file	*file;

	i = 0;
	calculate_padding(dir);
	while (i < dir->files_counter)
	{
		file = dir->files_arr[i];
		print_permissions(file->type, file->stat->st_mode);
		ft_printf("  %*d %-*s  %-*s  ", dir->padding.nlink,
			file->stat->st_nlink, dir->padding.pw_name, (char*)file->user.ptr,
			dir->padding.gr_name, (char*)file->group.ptr);
		if (file->type == 'c' || file->type == 'b')
			ft_printf(" %*d, %*d",
				dir->padding.dev_maj, major(file->stat->st_rdev),
				dir->padding.dev_min, minor(file->stat->st_rdev));
		else
			ft_printf("   %*lld", dir->padding.dev_maj + dir->padding.dev_min,
				file->stat->st_size);
		ft_printf(" %s %s%s\n", get_date(file->stat->st_mtimespec.tv_sec),
			file->name, file->link ? file->link : "");
		i++;
	}
}
