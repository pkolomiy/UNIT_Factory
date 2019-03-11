/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:41:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/03 15:41:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_name	*add_name_to_lst(t_name *head, char *name, mode_t st_mode)
{
	t_file_mode	mode;
	t_name		*new_name;

	mode.st_mode = st_mode;
	if (head == NULL)
	{
		head = (t_name *)malloc(sizeof(t_name));
		head->type = FILE_TYPE(mode.file.type);
		head->name = name;
		head->next = NULL;
	}
	else
	{
		new_name = head;
		while (new_name->next)
			new_name = new_name->next;
		new_name->next = (t_name *)malloc(sizeof(t_name));
		new_name->next->type = FILE_TYPE(mode.file.type);
		new_name->next->name = name;
		new_name->next->next = NULL;
	}
	return (head);
}

static t_name	*validate_names(int argc, char **names)
{
	int			i;
	t_stat		buf;
	t_name		*names_lst;

	i = 0;
	names_lst = NULL;
	while (i < argc)
	{
		if (lstat(names[i], &buf) == -1)
		{
			my_perror(names[i]);
			names[i] = NULL;
		}
		else
			names_lst = add_name_to_lst(names_lst, names[i], buf.st_mode);
		i++;
	}
	return (names_lst);
}

static void		show_dirs(t_ls_flags flags, t_name *names, int arg)
{
	t_dir	*dir;

	while (names)
	{
		if (names->type == 'd' || (names->type == 'l' && !flags.l))
		{
			if (flags.big_r)
				big_r_recursion(flags, names->name, arg);
			else if ((dir = read_whole_dir(flags, names->name)) != NULL)
			{
				show_dir(flags, dir, arg);
				free_dir(&dir);
			}
			arg++;
		}
		names = names->next;
	}
}

static void		multiple_names(t_ls_flags flags, char **names)
{
	int		arg;
	t_name	*names_lst;
	t_name	*temp;

	arg = 1;
	names_lst = names ? validate_names(flags.argc, names) : NULL;
	if (names_lst)
		read_all_arg_files(flags, names_lst, &arg);
	show_dirs(flags, names_lst, arg);
	while (names_lst)
	{
		temp = names_lst->next;
		ft_memdel((void**)&names_lst);
		names_lst = temp;
	}
}

void			ft_ls(t_ls_flags flags, char **names)
{
	t_dir	*dir;

	if (names == NULL)
	{
		if (flags.big_r)
			big_r_recursion(flags, ".", 1);
		else if ((dir = read_whole_dir(flags, ".")) != NULL)
		{
			show_dir(flags, dir, 1);
			free_dir(&dir);
		}
	}
	else
		multiple_names(flags, names);
}
