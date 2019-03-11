/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_whole_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:54:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 18:54:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_dir	*dir_reading(DIR *dir, t_ls_flags flags, char *name)
{
	t_dir		*dir_ptr;
	t_dirent	*dir_nt;
	t_file		*new_file;

	dir_ptr = (t_dir*)ft_memalloc(sizeof(t_dir));
	dir_ptr->name = name;
	dir_ptr->dir = 1;
	while ((dir_nt = readdir(dir)))
	{
		new_file = ((flags.f || flags.a) && dir_nt->d_name[0] == '.') ||
		dir_nt->d_name[0] != '.' ?
		create_t_file(flags, dir_ptr, dir_nt->d_name) : NULL;
		if (new_file)
		{
			new_file->next = dir_ptr->files;
			dir_ptr->files = new_file;
			dir_ptr->files_counter++;
			dir_ptr->dev = (_Bool)(dir_ptr->dev == 0 ?
			!(new_file->type != 'b' && new_file->type != 'c') : 1);
		}
	}
	return (dir_ptr);
}

void			read_all_arg_files(t_ls_flags flags, t_name *names, int *arg)
{
	t_dir	*dir;
	t_file	*new_file;

	dir = (t_dir*)ft_memalloc(sizeof(t_dir));
	while (names)
	{
		if ((names->type == 'l' && flags.l) ||
			(names->type != 'd' && names->type != 'l'))
		{
			dir->name = names->name;
			new_file = create_t_file(flags, dir, NULL);
			if (new_file)
			{
				new_file->next = dir->files;
				dir->files = new_file;
				dir->files_counter++;
				dir->dev = (_Bool)(dir->dev == 0 ?
				!(new_file->type != 'b' && new_file->type != 'c') : 1);
			}
			(*arg)++;
		}
		names = names->next;
	}
	show_dir(flags, dir, 1);
	free_dir(&dir);
}

t_dir			*read_whole_dir(t_ls_flags flags, char *name)
{
	DIR			*dir;
	t_dir		*dir_ptr;

	if ((dir_ptr = check_if_link(flags, name)) != NULL)
		return (dir_ptr);
	if ((dir = opendir(name)) == NULL)
	{
		my_perror(name);
		return (NULL);
	}
	dir_ptr = dir_reading(dir, flags, name);
	closedir(dir);
	return (dir_ptr);
}
