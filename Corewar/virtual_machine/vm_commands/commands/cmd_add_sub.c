/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:21:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:41:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_add_sub(t_memory *vm, t_process *process)
{
	t_integer	args[3];

	if (!get_arguments(vm, process, args))
	{
		if (process->cmd.opcode == 4)
			process->reg[args[2].u4 - 1].u4 =
			process->reg[args[0].u4 - 1].u4 +
			process->reg[args[1].u4 - 1].u4;
		else
			process->reg[args[2].u4 - 1].u4 =
			process->reg[args[0].u4 - 1].u4 -
			process->reg[args[1].u4 - 1].u4;
		process->carry = (process->reg[args[2].u4 - 1].u4 == 0);
	}
	move_process_pos(vm, process);
}
