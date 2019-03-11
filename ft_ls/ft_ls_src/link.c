/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:47:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/10 15:47:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ssize_t	try_readlink(t_file *file)
{
	ssize_t	len;
	char	*temp;

	temp = (char*)malloc(READ_LINK_BUFF);
	len = readlink(file->full_name, temp, READ_LINK_BUFF);
	if (len == -1)
		ft_memdel((void**)&temp);
	else
	{
		ft_memmove(temp + 4, temp, (size_t)len);
		ft_memcpy(temp, " -> ", 4);
		temp[len + 4] = '\0';
		file->link = temp;
	}
	return (len);
}

t_dir	*check_if_link(t_ls_flags flags, char *name)
{
	t_dir		*dir;
	t_stat		buf;
	t_file_mode	mode;

	if (stat(name, &buf) == -1)
		return (NULL);
	mode.st_mode = buf.st_mode;
	if (FILE_TYPE(mode.file.type) != 'd')
	{
		dir = (t_dir*)ft_memalloc(sizeof(t_dir));
		dir->name = name;
		dir->files = create_t_file(flags, dir, NULL);
		if (dir->files)
			dir->files_counter++;
		return (dir);
	}
	return (NULL);
}
