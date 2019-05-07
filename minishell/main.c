/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:02:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/21 11:02:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **environ)
{
	t_sh		*sh;
	t_strarr	temp;

	(void)argc;
	(void)argv;
	sh = (t_sh*)ft_memalloc(sizeof(t_sh));
	while (*environ)
	{
		temp = ft_strsplit(*environ, '=');
		set_new_env(sh, temp.ptr[0], temp.ptr[1]);
		free(temp.ptr);
		environ++;
	}
	minishell(sh);
	return (0);
}
