/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 20:46:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/11 18:28:04 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static _Bool	valid_flag(t_ls_flags *flags, char *flag)
{
	flag++;
	while (*flag)
	{
		if (*flag != 'a' && *flag != 'l' && *flag != 'f' &&
		*flag != 'r' && *flag != 'R' && *flag != 't')
			return (1);
		else
		{
			if (*flag == 'a')
				flags->a = 1;
			else if (*flag == 'l')
				flags->l = 1;
			else if (*flag == 'f')
				flags->f = 1;
			else if (*flag == 'r')
				flags->r = 1;
			else if (*flag == 'R')
				flags->big_r = 1;
			else
				flags->t = 1;
		}
		flag++;
	}
	return (0);
}

static char		**validate_flags(t_ls_flags *flags, char **argv, int argc)
{
	while (*argv)
	{
		if ((*argv)[0] == '-' && valid_flag(flags, *argv))
			exit(ft_printf("usage ft_ls [-Ralfrt] [file ...]\n"));
		else if ((*argv)[0] != '-')
			break ;
		argv++;
		argc--;
	}
	flags->argc = argc;
	return (argv);
}

static void		check_for_swap(char ***argv, int i, int j)
{
	int		k;
	char	*temp;

	k = 0;
	while ((*argv)[i][k] && (*argv)[j][k])
	{
		if ((*argv)[j][k] < (*argv)[i][k] ||
			((*argv)[j][k] == (*argv)[i][k] &&
			(*argv)[j][k + 1] == '\0' && (*argv)[i][k + 1] != '\0'))
		{
			temp = (*argv)[i];
			(*argv)[i] = (*argv)[j];
			(*argv)[j] = temp;
			break ;
		}
		else if ((*argv)[i][k] == (*argv)[j][k])
			k++;
		else
			break ;
	}
}

static char		**sort(t_ls_flags *flags, char **argv, int argc)
{
	int		i;
	int		j;

	argv = validate_flags(flags, argv, argc);
	if (flags->f)
		return (*argv ? argv : NULL);
	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			check_for_swap(&argv, i, j);
			j++;
		}
		i++;
	}
	return (*argv ? argv : NULL);
}

int				main(int argc, char **argv)
{
	t_ls_flags	flags;

	ft_bzero((void*)&flags, sizeof(t_ls_flags));
	if (argc != 1)
	{
		argv = sort(&flags, argv + 1, argc - 1);
		ft_ls(flags, argv);
	}
	else
		ft_ls(flags, NULL);
	return (0);
}
