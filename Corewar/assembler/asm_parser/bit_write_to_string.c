/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_write_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:23:58 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:35:56 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void				process_entry(t_process_name *g, int *number_process,
									int *d, unsigned char *ret)
{
	g->last_suma_bit = *number_process;
	*number_process += g->size_bit;
	ret[(*d)++] = g_op_tab[g->process_number].opcode;
	if (g_op_tab[g->process_number].codage)
		ret[(*d)++] = g->size_process;
}

int					write_all_process_in_list(t_process_name *g, int *d,
								unsigned char *ret, t_block *b1)
{
	int				count;
	int				j;

	count = 0;
	while (g_op_tab[g->process_number].args_num > count)
	{
		if (g->operation[count].t != NULL)
		{
			j = ft_search_lable_size(g->operation[count].t, b1);
			g_err.process = g->operation[count].t;
			g_err.t_char = g->operation[count].t_char;
			if (j < 0)
				return (j);
			ft_convert_nbr(j - g->last_suma_bit,
									g->operation[count].bit, ret, d);
		}
		else
			ft_convert_nbr(g->operation[count].size,
									g->operation[count].bit, ret, d);
		count++;
	}
	return (0);
}

int					bit_write_to_string(t_block *b1, unsigned char *ret, int d)
{
	t_block			*b3;
	int				number_process;
	t_process_name	*g;

	d = COM_NAME;
	b3 = b1;
	number_process = 0;
	while (b3)
	{
		g = b3->cop_process;
		while (g)
		{
			process_entry(g, &number_process, &d, ret);
			if (write_all_process_in_list(g, &d, ret, b1) < 0)
			{
				g_err.line = b3->line;
				return (-1);
			}
			g = g->next;
		}
		b3 = b3->next;
	}
	d = 136;
	ft_convert_nbr(number_process, 4, ret, &d);
	return (number_process);
}
