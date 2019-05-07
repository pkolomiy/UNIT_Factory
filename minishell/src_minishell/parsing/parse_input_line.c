/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:42:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/01 14:42:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_args(char *input)
{
	size_t	count;

	count = 0;
	while (*input)
	{
		while (*input && white_space(*input))
			input++;
		if (*input && !white_space(*input))
			count++;
		while (*input && !white_space(*input))
			input++;
	}
	return (count);
}

static char		*cut(char **str)
{
	char	*temp;
	char	*ret;

	temp = *str;
	while (*temp && !white_space(*temp))
		temp++;
	ret = (char*)malloc(temp - *str + 1);
	temp = ret;
	while (*(*str) && !white_space(*(*str)))
	{
		*temp = *(*str);
		(*str)++;
		temp++;
	}
	*temp = '\0';
	return (ret);
}

void			parse_input_line(t_sh *sh)
{
	char	**temp;
	char	*str;

	sh->arg.len = count_args(sh->line);
	sh->arg.ptr = (char**)malloc(sizeof(char*) * (sh->arg.len + 1));
	temp = sh->arg.ptr;
	str = sh->line;
	while (*str)
	{
		while (*str && white_space(*str))
			str++;
		if (*str)
		{
			*temp = cut(&str);
			temp++;
		}
	}
	*temp = NULL;
}
