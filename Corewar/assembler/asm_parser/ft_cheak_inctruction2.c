/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheak_inctruction2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:14:04 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void				ft_malloc_block(t_block *block)
{
	t_process_name	*cop_processname;
	int				count;

	count = -1;
	cop_processname = malloc(sizeof(t_process_name));
	cop_processname->size_bit = 0;
	cop_processname->process_number = 0;
	cop_processname->next = NULL;
	while (++count < 3)
	{
		cop_processname->operation[count].t = NULL;
		cop_processname->operation[count].bit = 0;
	}
	block->cop_process = cop_processname;
	block->process = cop_processname;
	block->size = 0;
	block->process->next = NULL;
}

void				creat_process_block(t_block *block)
{
	t_process_name	*cop_processname;
	int				count;

	count = -1;
	if (block->process == NULL)
		ft_malloc_block(block);
	else
	{
		while (block->process->next != NULL)
			block->process = block->process->next;
		cop_processname = malloc(sizeof(t_process_name));
		cop_processname->size_bit = 0;
		cop_processname->process_number = 0;
		while (++count < 3)
		{
			cop_processname->operation[count].t = NULL;
			cop_processname->operation[count].bit = 0;
		}
		cop_processname->next = NULL;
		block->process->next = cop_processname;
		block->process = block->process->next;
		block->size = 0;
		block->process->next = NULL;
	}
}

void				ft_creat_lable(char *file, t_count *o, t_block *block,
																int *i)
{
	block->process->operation[o->count].t = malloc(ft_strlen(file));
	block->process->operation[o->count].t_char = o->f;
	*i = 0;
	o->f++;
	if (file[o->f] == ':')
		o->f++;
	while (ft_islable(file[o->f]) && file[o->f] != '\0')
		block->process->operation[o->count].t[(*i)++] = file[o->f++];
	while (file[o->f] == ' ' || file[o->f] == '\t')
		o->f++;
	if (file[o->f] != '\0' && file[o->f] != ',' && file[o->f] != '#')
		block->process->operation[o->count].t[(*i)++] = ' ';
	while (file[o->f] != '\0' && file[o->f] != ',' && file[o->f] != '#')
		block->process->operation[o->count].t[(*i)++] = file[o->f++];
	block->process->operation[o->count].t[*i] = '\0';
}

int					ft_bite_when_dir(char *file, t_count *o,
												t_block *block, int i)
{
	if (file[o->f] == ':')
		block->process->operation[o->count].bit = 2;
	else
		block->process->operation[o->count].bit =
								g_op_tab[o->num_par].t_dir_size;
	if ((file[o->f + 1] == ':' && file[o->f] == '%') || file[o->f] == ':')
		ft_creat_lable(file, o, block, &i);
	else
		block->process->operation[o->count].t = NULL;
	block->process->operation[o->count].size = ft_atoi(&file[o->f + 1]);
	return (2);
}

int					ft_bite(char *file, t_count *o, t_block *block)
{
	block->process->process_number = o->num_par;
	if (file[o->f] == 'r' && ft_reg_command(o->num_par, o->count))
	{
		block->process->operation[o->count].bit = 1;
		block->process->operation[o->count].size = ft_atoi(&file[o->f + 1]);
		if (block->process->operation[o->count].size < 1 ||
			block->process->operation[o->count].size > 16)
			return (0);
		return (1);
	}
	else if ((file[o->f] == DIRECT_CHAR && ft_dir_command(o->num_par, o->count))
														|| file[o->f] == ':')
		return (ft_bite_when_dir(file, o, block, 0));
	else if (ft_isdigit_minus(file[o->f]) &&
				ft_ind_command(o->num_par, o->count))
	{
		block->process->operation[o->count].bit = 2;
		if (file[o->f - 1] == '-')
			o->f--;
		block->process->operation[o->count].size = ft_atoi(&file[o->f]);
		return (3);
	}
	return (0);
}
