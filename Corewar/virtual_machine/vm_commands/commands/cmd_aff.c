/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/26 18:20:44 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_aff(t_memory *vm, t_process *process)
{
	t_integer	args[3];

	if (!get_arguments(vm, process, args) && !vm->flags.visual &&
	vm->flags.live)
	{
		write(1, "Aff: ", 5);
		write(1, &process->reg[args[0].u4 - 1].byte[0], 1);
		write(1, "\n", 1);
	}
	move_process_pos(vm, process);
}
