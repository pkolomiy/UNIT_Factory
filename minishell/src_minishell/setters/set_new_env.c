/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:52:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/04 20:52:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_new_env(t_sh *sh, char *key, char *val)
{
	t_env	*temp;

	temp = (t_env*)malloc(sizeof(t_env));
	temp->key = key;
	temp->val = val;
	temp->next = sh->env;
	temp->prev = NULL;
	if (sh->env)
		sh->env->prev = temp;
	sh->env = temp;
	sh->env_len++;
	if (!sh->env_end)
		sh->env_end = sh->env;
}
