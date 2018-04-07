/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_first_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:38:13 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:24:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

t_block			*ft_first_block(t_file *cop, t_block *b2, int f, int p)
{
	int			r;
	t_block		*b1;

	r = 0;
	b1 = b2;
	if (p == 20000)
	{
		p = ft_serch_name_proc(cop->line, &f, 0, 0);
		r = ft_cheak_inctruction(cop->line, &f, p, b2);
		g_err.arg = (-r - 1);
		g_err.process = g_op_tab[p].name;
	}
	if (r < 0)
	{
		free(b1);
		return (NULL);
	}
	return (b1);
}

t_block			*first_block(t_file *cop, t_block *b2, int f, int p)
{
	t_block		*b1;

	b1 = malloc(sizeof(t_block));
	b1->process = NULL;
	b1->cop_process = NULL;
	b1->next = NULL;
	b1->name = NULL;
	b1->line = cop->num;
	if (is_lable(cop->line, LABEL_CHAR) != -1)
		f = ft_search_labe(cop->line, b1, 0, 0);
	p = f + 1;
	b2 = b1;
	while (cop->line[p] != '\0')
	{
		if (ft_isalpha(cop->line[p]) || ft_isdigit(cop->line[p]))
		{
			p = 20000;
			break ;
		}
		p++;
	}
	return (ft_first_block(cop, b2, f, p));
}
