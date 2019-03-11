/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:47:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 19:47:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort_by_name(t_file ***arr, int i, int j)
{
	t_file	*temp;
	int		k;

	k = 0;
	while ((*arr)[i]->name[k] && (*arr)[j]->name[k])
	{
		if ((*arr)[j]->name[k] < (*arr)[i]->name[k] ||
		((*arr)[i]->name[k] == (*arr)[j]->name[k] &&
		(*arr)[j]->name[k + 1] == '\0' && (*arr)[i]->name[k + 1] != '\0'))
		{
			temp = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = temp;
			break ;
		}
		else if ((*arr)[i]->name[k] == (*arr)[j]->name[k])
			k++;
		else
			break ;
	}
}

static void		check_for_swap(t_ls_flags flags, t_file ***arr, int i, int j)
{
	t_file	*temp;

	if (flags.r)
	{
		i ^= j;
		j ^= i;
		i ^= j;
	}
	if (flags.t)
	{
		if ((*arr)[j]->stat->st_mtimespec.tv_sec >
		(*arr)[i]->stat->st_mtimespec.tv_sec)
		{
			temp = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = temp;
		}
		else if ((*arr)[j]->stat->st_mtimespec.tv_sec ==
		(*arr)[i]->stat->st_mtimespec.tv_sec)
			sort_by_name(arr, i, j);
	}
	else
		sort_by_name(arr, i, j);
}

static t_file	**unsorted(t_dir *dir)
{
	t_file	*temp;
	t_file	**arr;
	int		i;

	temp = dir->files;
	arr = (t_file**)malloc(sizeof(t_file) * dir->files_counter);
	i = dir->files_counter - 1;
	while (i >= 0)
	{
		arr[i] = temp;
		temp = temp->next;
		i--;
	}
	return (arr);
}

static t_file	**sorted(t_ls_flags flags, t_dir *dir)
{
	t_file	**arr;
	int		i;
	int		j;

	arr = unsorted(dir);
	i = 0;
	while (i < dir->files_counter)
	{
		j = i + 1;
		while (j < dir->files_counter)
		{
			check_for_swap(flags, &arr, i, j);
			j++;
		}
		i++;
	}
	return (arr);
}

t_file			**get_files_arr(t_ls_flags flags, t_dir *dir)
{
	if (dir->files_counter == 0)
		return (NULL);
	if (flags.f)
		return (unsorted(dir));
	else
		return (sorted(flags, dir));
}
