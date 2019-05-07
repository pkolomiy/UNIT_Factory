/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:00:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/29 20:00:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_promt(void)
{
	signal(SIGINT, ft_signal);
	if (g_sig == 2)
		write(1, "\n$> ", 4);
	if (g_sig == 0)
		write(1, "$> ", 3);
}

void		minishell(t_sh *sh)
{
	int		ret;

	while (1)
	{
		print_promt();
		ret = get_next_line(0, &sh->line);
		if (ret <= 0)
		{
			write(1, "exit\n", 5);
			break ;
		}
		g_sig = 0;
		parse_input(sh);
		ft_memdel((void**)&sh->line);
		free_strarr(&sh->arg);
		if (sh->exit)
			break ;
	}
}
