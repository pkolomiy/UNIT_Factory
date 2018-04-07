/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_and_or_xor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:41:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_and_or_xor(t_memory *vm, t_process *process)
{
	t_integer	args[3];

	if (!get_arguments(vm, process, args))
	{
		args[0] = update_argument(vm, process, 1, args[0]);
		args[1] = update_argument(vm, process, 2, args[1]);
		if (process->cmd.opcode == 6)
			process->reg[args[2].u4 - 1].u4 = args[0].u4 & args[1].u4;
		else if (process->cmd.opcode == 7)
			process->reg[args[2].u4 - 1].u4 = args[0].u4 | args[1].u4;
		else
			process->reg[args[2].u4 - 1].u4 = args[0].u4 ^ args[1].u4;
		process->carry = (process->reg[args[2].u4 - 1].u4 == 0);
	}
	move_process_pos(vm, process);
}
