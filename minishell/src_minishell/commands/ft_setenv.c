/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 18:30:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static _Bool	invalid_argument(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			j++;
		i++;
	}
	if (j > 1 || arg[0] == '=')
		return (1);
	return (0);
}

static void		check_arg(t_sh *sh, t_strarr parsed, char *arg)
{
	if (invalid_argument(arg) || parsed.len == 0 || parsed.len > 2)
		error_msg("setenv: invalid argument: ", arg, "\n", NULL);
	else if (valid_name(parsed.ptr[0]) == 0)
		error_msg("setenv: invalid name: ", parsed.ptr[0], "\n", NULL);
	else
	{
		if (set_to_env(sh, parsed.ptr[0], parsed.ptr[1]) == 0)
		{
			set_new_env(sh, parsed.ptr[0], parsed.ptr[1]);
			parsed.ptr[0] = NULL;
		}
		parsed.ptr[1] = NULL;
	}
}

void			ft_setenv(t_sh *sh)
{
	size_t		i;
	size_t		j;
	t_strarr	temp;

	i = 1;
	while (i < sh->arg.len)
	{
		temp = ft_strsplit(sh->arg.ptr[i], '=');
		check_arg(sh, temp, sh->arg.ptr[i]);
		j = 0;
		while (temp.ptr && j < temp.len)
		{
			ft_memdel((void **)&temp.ptr[j]);
			j++;
		}
		ft_memdel((void**)&temp.ptr);
		i++;
	}
}
