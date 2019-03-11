/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:54:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/10 15:54:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static ssize_t	try_get_user_and_group(t_file *file)
{
	t_passwd	*user;
	t_group		*group;

	if ((user = getpwuid(file->stat->st_uid)) == NULL ||
	(group = getgrgid(file->stat->st_gid)) == NULL)
	{
		return (-1);
	}
	ft_stringclone(user->pw_name, &file->user);
	ft_stringclone(group->gr_name, &file->group);
	return (0);
}

static char		*get_full_name(char *first, char *second)
{
	char	*joined;
	size_t	first_len;
	size_t	second_len;

	first_len = ft_strlen(first);
	second_len = ft_strlen(second);
	joined = (char*)malloc(first_len + second_len + 2);
	ft_memcpy((void*)joined, (void*)first, first_len);
	joined[first_len] = '/';
	ft_memcpy((void*)(joined + first_len + 1), second, second_len);
	joined[first_len + 1 + second_len] = '\0';
	return (joined);
}

static void		free_t_file(t_file **file)
{
	t_file	*temp;

	temp = *file;
	ft_memdel((void**)&temp->name);
	ft_memdel((void**)&temp->full_name);
	ft_memdel((void**)&temp->stat);
	ft_memdel((void**)file);
}

static _Bool	file_validation(t_ls_flags flags, t_file **file)
{
	t_file		*temp;
	t_file_mode	mode;

	temp = *file;
	if (lstat(temp->full_name, temp->stat) == -1)
	{
		my_perror(temp->full_name);
		free_t_file(file);
		return (1);
	}
	mode.st_mode = temp->stat->st_mode;
	temp->type = FILE_TYPE(mode.file.type);
	if ((temp->type == 'l' && flags.l && try_readlink(temp) == -1) ||
		(flags.l && try_get_user_and_group(temp) == -1))
	{
		my_perror(temp->full_name);
		free_t_file(file);
		return (1);
	}
	return (0);
}

t_file			*create_t_file(t_ls_flags flags, t_dir *dir, char *name)
{
	t_file		*file;

	file = (t_file*)ft_memalloc(sizeof(t_file));
	file->name = ft_strdup(name ? name : dir->name);
	file->full_name = name ? get_full_name(dir->name, file->name) :
						ft_strdup(dir->name);
	file->stat = (t_stat*)malloc(sizeof(t_stat));
	if (file_validation(flags, &file))
		return (NULL);
	dir->total += file->stat->st_blocks;
	return (file);
}
