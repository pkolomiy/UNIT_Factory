/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 18:30:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_sh *sh)
{
	t_env	*temp;

	temp = sh->env_end;
	while (temp)
	{
		write(1, temp->key, ft_strlen(temp->key));
		write(1, "=", 1);
		if (temp->val)
			write(1, temp->val, ft_strlen(temp->val));
		write(1, "\n", 1);
		temp = temp->prev;
	}
}
