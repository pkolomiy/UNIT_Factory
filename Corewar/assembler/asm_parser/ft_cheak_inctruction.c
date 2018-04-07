/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheak_inctruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:49:56 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:35:56 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void			initialization(int *binary_code, t_count *o,
												int num_of_static_val)
{
	int			i;

	i = 0;
	o->count = 0;
	o->num_par = num_of_static_val;
	o->z = g_op_tab[num_of_static_val].args_num;
	while (i < 3)
	{
		binary_code[i] = 0;
		i++;
	}
}

int				check_and_calculate_parameters(char *file, int *binary_code,
										t_count *o, t_block *block)
{
	int			u;

	u = 0;
	if (file[o->f] == LABEL_CHAR)
		u = 3;
	binary_code[o->count] = ft_bite(file, o, block);
	if (binary_code[o->count] == 0)
		return (-(o->count + 1));
	if (u == 3)
		binary_code[o->count] = 3;
	while (file[o->f] != SEPARATOR_CHAR && o->z > 1)
		o->f++;
	while (file[o->f] == ' ' || file[o->f] == SEPARATOR_CHAR
													|| file[o->f] == '\t')
		o->f++;
	o->count++;
	o->z--;
	return (1);
}

int				ft_size_command(t_block *block, int num_of_static_val)
{
	int			j;
	int			size;

	size = 0;
	j = -1;
	while (++j < 3)
		size += block->process->operation[j].bit;
	size += g_op_tab[num_of_static_val].codage + 1;
	block->process->size_bit = size;
	return (size);
}

int				ft_cheak_inctruction(char *file, int *f,
									int num_of_static_val, t_block *block)
{
	int			binary_code[3];
	t_count		o;
	int			l;

	initialization(binary_code, &o, num_of_static_val);
	creat_process_block(block);
	while (file[*f] != DIRECT_CHAR && file[*f] != ':' && file[*f] != 'r'
					&& ft_isdigit(file[*f]) == 0 && file[*f] != '-')
		(*f)++;
	o.f = *f;
	while ((file[*f] == DIRECT_CHAR || file[*f] == 'r' || file[*f] == ':' ||
		file[*f] != '-' || ft_isdigit_minus(file[*f])) && o.z > 0)
	{
		l = check_and_calculate_parameters(file, binary_code, &o, block);
		if (l < 0)
			return (l);
	}
	*f = o.f;
	while (file[*f] != ' ' && file[*f] != '\n' &&
					file[*f] != '\t' && file[*f] != '\0')
		(*f)++;
	block->process->size_process = binary_code[0] * 64 + binary_code[1] * 16
														+ binary_code[2] * 4;
	return (ft_size_command(block, num_of_static_val));
}
