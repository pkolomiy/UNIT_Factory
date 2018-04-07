/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:13:43 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/27 19:10:21 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_instruct(char *str, t_asm *s_file)
{
	int		len;

	len = ft_strlen(str);
	if (!s_file->instructions)
		s_file->instructions = ft_lstnew(str, len);
	else
		ft_lstadd(&s_file->instructions, ft_lstnew(str, len));
}

char	**split_args(char *str, t_asm *s_file, char **error, int c)
{
	int		i;
	int		j;
	size_t	len;
	char	**res;

	i = c;
	j = -1;
	len = ft_strlen(str);
	if (!(res = (char**)malloc(sizeof(char*) * 2 + 1)))
	{
		*error = ft_strdup("Out of memory while running validation!");
		return (NULL);
	}
	res[0] = ft_strndup(str, c);
	res[1] = ft_strnew(len - c);
	res[2] = 0;
	fill_instruct(res[0], s_file);
	while (i < (int)len)
	{
		res[1][++j] = str[i];
		i++;
	}
	res[1][j + 1] = '\0';
	return (res);
}

char	**search_arg(char *str, char **error, t_asm *s_file)
{
	int		i;
	char	**res;

	i = -1;
	res = NULL;
	while (str[++i])
	{
		if (str[i] == DIRECT_CHAR || str[i] == ' ' || str[i] == '\t')
		{
			res = split_args(str, s_file, error, i);
			break ;
		}
	}
	return (res);
}

void	valid_instruction(char *str, t_asm *s_file, char **error, int j)
{
	int		ret;
	char	**arg;

	arg = search_arg(str, error, s_file);
	if (arg == NULL)
	{
		(!(*error)) ? *error = error_message(j, 'i') : 0;
		return ;
	}
	ret = check_instruction(arg[0], error, j);
	if (*error)
	{
		ft_free_arr(arg);
		return ;
	}
	if (ret == -1 || !check_params(arg[1], ret, error, j))
	{
		ft_free_arr(arg);
		return ;
	}
	ft_free_arr(arg);
}
