/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:14:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/02 22:14:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*paste_env_key(t_env *env, char *src, char *pos)
{
	char	*key;
	char	*value;
	size_t	len;

	len = 1;
	while (pos[len] && name_symbol(pos[len]))
		len++;
	if (len == 1)
		return (src);
	key = sub_string(src, pos - src + 1, len - 1);
	value = get_from_env(env, key);
	free(key);
	if (value == NULL)
		return (src);
	key = replace_string(src, value, pos - src, len);
	free(src);
	return (key);
}

void	parse_arguments(t_sh *sh)
{
	size_t	i;
	char	*temp;

	i = 0;
	parse_quotes(sh);
	while (i < sh->arg.len)
	{
		if (sh->arg.ptr[i][0] == '~' &&
			(sh->arg.ptr[i][1] == '/' || sh->arg.ptr[i][1] == '\0'))
		{
			temp = get_from_env(sh->env, "HOME");
			temp = replace_string(sh->arg.ptr[i], temp ? temp : "", 0, 1);
			free(sh->arg.ptr[i]);
			sh->arg.ptr[i] = temp;
		}
		if ((temp = ft_strchr(sh->arg.ptr[i], '$')))
			sh->arg.ptr[i] = paste_env_key(sh->env, sh->arg.ptr[i], temp);
		i++;
	}
}
