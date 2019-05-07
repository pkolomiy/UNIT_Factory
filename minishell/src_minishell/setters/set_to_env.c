/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/04 20:17:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	set_to_env(t_sh *sh, char *key, char *val)
{
	t_env	*env;
	char	*old_val;

	env = sh->env;
	while (env)
	{
		if (str_equal(env->key, key))
			break ;
		env = env->next;
	}
	if (env)
	{
		old_val = env->val;
		env->val = val;
		ft_memdel((void**)&old_val);
		return (1);
	}
	return (0);
}
