/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:14:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 16:14:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static inline t_command	command(int i)
{
	static t_command	commands[7] = {
		{"env", 1, 1, &ft_env, "env: too many arguments\n"},
		{"setenv", 2, 0, &ft_setenv, "setenv [key=value ...]\n"},
		{"unsetenv", 2, 0, &ft_unsetenv, "unsetenv [key ...]\n"},
		{"echo", 1, 0, &ft_echo, "echo [string ...]\n"},
		{"cd", 1, 2, &ft_cd, "cd [directory]\n"},
		{"exit", 1, 1, &ft_exit, "exit: too many arguments\n"},
		{NULL, 0, 0, &ft_bin, NULL}
	};

	return (commands[i]);
}

static void				check_command(t_sh *sh)
{
	int	i;

	i = -1;
	while (command(++i).name)
		if (str_equal(sh->arg.ptr[0], command(i).name))
			break ;
	if (command(i).name)
	{
		if (sh->arg.len < command(i).min_args ||
		(command(i).max_args && sh->arg.len > command(i).max_args))
			error_msg("usage: ", command(i).usage, NULL, NULL);
		else
			command(i).execute(sh);
	}
	else
		command(i).execute(sh);
}

void					parse_input(t_sh *sh)
{
	t_strarr	temp;
	size_t		i;

	i = 0;
	if (sh->line)
	{
		temp = ft_strsplit(sh->line, ';');
		ft_memdel((void**)&sh->line);
		while (i < temp.len)
		{
			sh->line = temp.ptr[i];
			parse_input_line(sh);
			parse_arguments(sh);
			if (sh->arg.ptr && sh->arg.len >= 1)
				check_command(sh);
			free_strarr(&sh->arg);
			i++;
		}
		sh->line = NULL;
		free_strarr(&temp);
	}
}
