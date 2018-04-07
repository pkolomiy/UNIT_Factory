/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cre_struct_data_labels_proc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:33:01 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:24:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

static t_block	*ft_creat_list_labl(t_file *cop, t_block *b2, int *f)
{
	t_block		*b3;

	b3 = malloc(sizeof(t_block));
	b3->line = cop->num;
	b3->next = NULL;
	b3->process = NULL;
	b3->cop_process = NULL;
	b3->size = ft_count_size(b2);
	b2->process = NULL;
	if (ft_search_labe(cop->line, b3, 0, 0) > 0)
	{
		b2->next = b3;
		b2 = b2->next;
	}
	else
	{
		free(b3);
		*f = 0;
	}
	return (b2);
}

static int		ft_cheak_inctruction_and_cheak(t_file *cop, int f,
													t_block *b2, int p)
{
	int			t;

	p = ft_seach_process_name(cop->line, &f);
	if (p >= 0)
	{
		t = ft_cheak_inctruction(cop->line, &f, p, b2);
		if (t < 0)
		{
			g_err.arg = (-t - 1);
			g_err.process = g_op_tab[p].name;
			return (-1);
		}
	}
	return (1);
}

int				the_comm(char *str, int f)
{
	while (str[f] != '\0')
	{
		if (str[f] == '#')
			return (1);
		else if (str[f] != ' ' && str[f] != '\t')
			return (-1);
		f++;
	}
	return (-1);
}

int				cre_struct_data_labels_proc(t_file *cop, t_block *b2,
														int p, int f)
{
	cop = cop->next;
	while (cop)
	{
		if (ft_comment(cop->line) == 1)
		{
			cop = cop->next;
			continue ;
		}
		if ((f = is_lable(cop->line, LABEL_CHAR)) != -1)
			b2 = ft_creat_list_labl(cop, b2, &f);
		if (f < 0)
			f = 0;
		if (ft_empty_line(cop->line, f) == 0 || the_comm(cop->line, f + 1) == 1)
		{
			f = 0;
			cop = cop->next;
			continue ;
		}
		if (ft_cheak_inctruction_and_cheak(cop, f, b2, p) == -1)
			return (-1);
		b2->line = cop->num;
		cop = cop->next;
		f = 0;
	}
	return (1);
}
