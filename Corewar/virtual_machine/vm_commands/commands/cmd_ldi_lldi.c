/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ldi_lldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:57:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_ldi_lldi(t_memory *vm, t_process *process)
{
	t_integer	args[3];
	int			pos;
	t_bits		bit;

	if (!get_arguments(vm, process, args))
	{
		bit = process->codage.bits;
		args[0] = update_argument(vm, process, 1, args[0]);
		if (process->codage.bits.second == REG_CODE)
			args[1].u4 = process->reg[args[1].u4 - 1].u4;
		pos = ((bit.first == DIR_CODE) ? args[0].s2 : args[0].u4) +
		((bit.second == DIR_CODE) ? args[1].s2 : args[1].u4);
		if (process->cmd.opcode == 10)
			pos %= IDX_MOD;
		pos += process->pos;
		process->reg[args[2].u4 - 1].byte[3] = vm->mem[change_pos(pos)];
		process->reg[args[2].u4 - 1].byte[2] = vm->mem[change_pos(pos + 1)];
		process->reg[args[2].u4 - 1].byte[1] = vm->mem[change_pos(pos + 2)];
		process->reg[args[2].u4 - 1].byte[0] = vm->mem[change_pos(pos + 3)];
		if (process->cmd.opcode == 14)
			process->carry = (process->reg[args[2].u4 - 1].u4 == 0);
	}
	move_process_pos(vm, process);
}
