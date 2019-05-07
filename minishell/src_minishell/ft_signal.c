/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 22:10:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/05 22:10:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n$> ", 4);
		g_sig = 1;
	}
}

void	ft_signal2(int sig)
{
	if (sig == SIGINT)
	{
		g_sig = 2;
	}
}
