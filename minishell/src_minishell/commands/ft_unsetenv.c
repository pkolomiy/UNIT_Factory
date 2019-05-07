/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 18:30:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env_elem(t_sh *sh, t_env *env, t_env *temp)
{
	if (env == sh->env)
		sh->env = env->next;
	if (env == sh->env_end)
		sh->env_end = env->prev;
	if (temp)
		temp->next = env->next;
	if (env->next)
		env->next->prev = temp;
	ft_memdel((void**)&env->key);
	ft_memdel((void**)&env->val);
	ft_memdel((void**)&env);
}

static void	del_from_env(t_sh *sh, size_t i)
{
	t_env	*env;
	t_env	*temp;

	temp = NULL;
	env = sh->env;
	while (env)
	{
		if (str_equal(env->key, sh->arg.ptr[i]))
		{
			free_env_elem(sh, env, temp);
			sh->env_len--;
			break ;
		}
		temp = env;
		env = env->next;
	}
}

void		ft_unsetenv(t_sh *sh)
{
	size_t		i;

	i = 1;
	while (i < sh->arg.len)
	{
		if (valid_name(sh->arg.ptr[i]) == 0)
			error_msg("unsetenv: invalid name: ", sh->arg.ptr[i], "\n", NULL);
		else
			del_from_env(sh, i);
		i++;
	}
}
