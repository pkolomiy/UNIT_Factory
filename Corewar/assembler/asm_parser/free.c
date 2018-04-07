/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:46:30 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:24:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void				ft_free_file_information(t_file *file)
{
	t_file			*del;
	t_file			*as;

	as = file;
	while (as)
	{
		free(as->line);
		del = as;
		as = as->next;
		free(del);
	}
}

void				ft_outside_loop(t_process_name *z1)
{
	int			j;

	j = -1;
	while (++j < 3)
	{
		if (z1->operation[j].t != NULL)
			free(z1->operation[j].t);
	}
}

void				ft_free(t_file *file, t_block *b1)
{
	t_process_name	*z1;
	t_block			*b4;
	t_process_name	*z;
	t_block			*u;

	ft_free_file_information(file);
	b4 = b1;
	while (b4)
	{
		if (b4->name != NULL)
			free(b4->name);
		z = b4->cop_process;
		while (z)
		{
			z1 = z;
			ft_outside_loop(z1);
			z = z->next;
			free(z1);
		}
		u = b4;
		b4 = b4->next;
		free(u);
	}
}
