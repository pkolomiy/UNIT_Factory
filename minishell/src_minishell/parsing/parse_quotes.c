/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:57:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/04 16:57:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_new_ptr(t_sh *sh, size_t new_len)
{
	size_t	i;
	size_t	j;
	char	**new_ptr;

	i = 0;
	j = 0;
	if (new_len == 0)
		sh->arg.len = 0;
	else if (new_len != sh->arg.len)
	{
		new_ptr = (char **)malloc(sizeof(char *) * new_len);
		while (i < sh->arg.len)
		{
			if (sh->arg.ptr[i])
			{
				new_ptr[j] = sh->arg.ptr[i];
				j++;
			}
			i++;
		}
		free(sh->arg.ptr);
		sh->arg.ptr = new_ptr;
		sh->arg.len = new_len;
	}
}

void	parse_quotes(t_sh *sh)
{
	size_t	i;
	size_t	new_len;
	char	*temp;

	i = 0;
	new_len = 0;
	while (i < sh->arg.len)
	{
		if (ft_strchr(sh->arg.ptr[i], '"'))
		{
			temp = trim_char(sh->arg.ptr[i], '"');
			ft_memdel((void **)&sh->arg.ptr[i]);
			if (temp)
			{
				sh->arg.ptr[i] = temp;
				new_len++;
			}
		}
		else
			new_len++;
		i++;
	}
	make_new_ptr(sh, new_len);
}
