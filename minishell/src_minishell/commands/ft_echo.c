/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:29:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 18:29:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_sh *sh)
{
	size_t		i;

	i = 1;
	while (i < sh->arg.len)
	{
		write(1, sh->arg.ptr[i], ft_strlen(sh->arg.ptr[i]));
		if (i + 1 < sh->arg.len)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
