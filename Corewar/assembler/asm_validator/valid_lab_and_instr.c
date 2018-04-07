/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_lab_and_instr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:57:20 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/24 20:33:05 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_label_char(char c)
{
	int	i;

	i = -1;
	while (LABEL_CHARS[++i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
	}
	return (0);
}

static int	check_labels(t_list *labels, char **error, int j)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = labels;
	while (tmp)
	{
		while (++i < (int)tmp->content_size)
		{
			if (!is_label_char(((char*)tmp->content)[i]))
			{
				*error = error_message(j, 's');
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

void		valid_lab_and_instr(char **file, t_asm *s_file, char **error, int j)
{
	int	i;

	i = j - 1;
	if (!s_file->name || !s_file->comment)
		(!(*error)) ? *error = error_message(j, 'm') : 0;
	while (file[++i] && !(*error))
	{
		if (ft_strlen(file[i]) == 0)
			continue ;
		if (!is_label_char(file[i][0]))
			*error = error_message(i, 'l');
		else
			deal_with_label(&(file[i]), s_file, error, i);
	}
	if ((!(*error)) && !check_labels(s_file->labels, error, j))
		return ;
	i = j;
	while (file[++i] && !(*error))
	{
		if (ft_strlen(file[i]) == 0)
			continue ;
		valid_instruction(file[i], s_file, error, i);
	}
}
