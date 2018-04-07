/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labl2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:52:31 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

int					ft_cheak_label(char *lab)
{
	int				j;
	int				z;

	j = 0;
	z = 0;
	while (lab[j] == ' ' || lab[j] == '\t')
		j++;
	while (ft_strstr(lab, NAME_CMD_STRING) ||
					ft_strstr(lab, COMMENT_CMD_STRING))
		return (0);
	if (the_comm(lab, 0) == 1)
		return (0);
	while (lab[j] != '\0')
	{
		while (ft_strchr(LABEL_CHARS, lab[j]) != NULL)
			j++;
		if (lab[j])
		{
			z = 1;
			break ;
		}
		j++;
	}
	return (z);
}

int					ft_search_lable_size(char *s, t_block *b1)
{
	t_block			*cop_b;

	cop_b = b1;
	while (cop_b)
	{
		if (cop_b->name == NULL)
		{
			if (cop_b->next == NULL)
				return (-1);
			cop_b = cop_b->next;
			if (cop_b)
			{
				continue ;
			}
		}
		if (ft_strcmp(s, cop_b->name) == 0)
			return (cop_b->size);
		cop_b = cop_b->next;
	}
	return (-1);
}

int					ft_count_size(t_block *b2)
{
	t_process_name	*way;
	int				u;

	u = 0;
	if (b2->cop_process == NULL)
		return (0);
	way = b2->cop_process;
	while (way)
	{
		u += way->size_bit;
		way = way->next;
	}
	return (u);
}

int					ft_la_size(t_block *b2)
{
	int				l;
	t_process_name	*z;
	t_block			*b4;

	b4 = b2;
	l = 0;
	while (b4)
	{
		b4->size = l;
		z = b4->cop_process;
		while (z)
		{
			l += z->size_bit;
			z = z->next;
		}
		b4 = b4->next;
	}
	return (l);
}
