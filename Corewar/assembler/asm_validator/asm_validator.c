/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:58:36 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/28 17:03:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_struct(t_asm *file)
{
	file->name = NULL;
	file->labels = NULL;
	file->comment = NULL;
	file->instructions = NULL;
}

static char	*cut_comments(char *str, int *n)
{
	int		i;
	char	*res;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\"')
			(*n)++;
		if (str[i] == COMMENT_CHAR && ((*n % 2) == 0))
		{
			res = ft_strndup(str, i);
			ft_memdel((void**)&str);
			return (res);
		}
	}
	return (str);
}

static void	clean_struct(t_asm *file)
{
	ft_memdel((void**)&file->name);
	ft_memdel((void**)&file->comment);
	ft_lstdel(&file->labels, delete_tlist_node);
	ft_lstdel(&file->instructions, delete_tlist_node);
}

_Bool		asm_validator(char *file, char **error)
{
	int		i;
	int		n;
	char	**res;
	t_asm	s_file;

	n = 0;
	i = -1;
	*error = NULL;
	init_struct(&s_file);
	res = ft_strsplit(file, '\n');
	while (res[++i])
	{
		res[i] = ft_skip_whitespace(res[i], 0);
		res[i] = cut_comments(res[i], &n);
	}
	i = -1;
	if (valid_name_and_comm(res, &s_file, error, &i))
		(!(*error)) ? valid_lab_and_instr(res, &s_file, error, i) : 0;
	ft_free_arr(res);
	if ((!s_file.instructions && !s_file.labels) && !(*error))
		*error = error_message(i, 'b');
	clean_struct(&s_file);
	if (*error)
		return (0);
	return (1);
}
