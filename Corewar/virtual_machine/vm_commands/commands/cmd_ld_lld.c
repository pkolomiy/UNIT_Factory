/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld_lld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:52:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:41:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_ld_lld(t_memory *vm, t_process *process)
{
	t_integer	args[3];

	if (!get_arguments(vm, process, args))
	{
		if (process->codage.bits.first == IND_CODE)
		{
			args[0] = get_ind_bytes(vm->mem, args[0], process->pos);
			if (process->cmd.opcode == 13)
			{
				args[0].byte[1] = args[0].byte[3];
				args[0].byte[0] = args[0].byte[2];
				args[0].byte[3] = 0;
				args[0].byte[2] = 0;
			}
		}
		process->reg[args[1].u4 - 1].u4 = args[0].u4;
		process->carry = (process->reg[args[1].u4 - 1].u4 == 0);
	}
	move_process_pos(vm, process);
}
