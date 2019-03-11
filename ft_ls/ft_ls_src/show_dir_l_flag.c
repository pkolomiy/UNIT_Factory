/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dir_l_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:42:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 22:42:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	calculate_padding(t_dir *dir)
{
	int		i;
	size_t	temp;

	i = 0;
	while (!dir->dev && i < dir->files_counter)
	{
		temp = ft_nbrlen((size_t)dir->files_arr[i]->stat->st_nlink);
		if (temp > dir->padding.nlink)
			dir->padding.nlink = (t_byte)temp;
		if ((t_byte)dir->files_arr[i]->user.size > dir->padding.pw_name)
			dir->padding.pw_name = (t_byte)dir->files_arr[i]->user.size;
		if ((t_byte)dir->files_arr[i]->group.size > dir->padding.gr_name)
			dir->padding.gr_name = (t_byte)dir->files_arr[i]->group.size;
		temp = ft_nbrlen((size_t)dir->files_arr[i]->stat->st_size);
		if (temp > dir->padding.st_size)
			dir->padding.st_size = (t_byte)temp;
		i++;
	}
}

void		show_dir_l_flag(t_dir *dir)
{
	int		i;
	t_file	*file;

	i = 0;
	if (dir->dir)
		ft_printf("total %lld\n", dir->total);
	if (dir->dev)
		show_dev(dir);
	calculate_padding(dir);
	while (!dir->dev && i < dir->files_counter)
	{
		file = dir->files_arr[i];
		print_permissions(file->type, file->stat->st_mode);
		ft_printf("  %*d %-*s  %-*s  %*lld %s %s%s\n", dir->padding.nlink,
		file->stat->st_nlink, dir->padding.pw_name, (char*)file->user.ptr,
		dir->padding.gr_name, (char*)file->group.ptr, dir->padding.st_size,
		file->stat->st_size, get_date(file->stat->st_mtimespec.tv_sec),
		file->name, file->link ? file->link : "");
		i++;
	}
}
