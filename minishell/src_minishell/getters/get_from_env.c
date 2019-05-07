/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:36:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/02 22:36:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_from_env(t_env *env, char *key)
{
	while (env)
	{
		if (str_equal(env->key, key))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}
