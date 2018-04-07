/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:41:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_sti(t_memory *vm, t_process *process)
{
	t_integer	args[3];
	int			pos;

	if (!get_arguments(vm, process, args))
	{
		args[1] = update_argument(vm, process, 2, args[1]);
		args[2] = update_argument(vm, process, 3, args[2]);
		pos = ((int)((process->codage.bits.second == DIR_CODE ? args[1].s2 :
		args[1].u4) + (process->codage.bits.third == DIR_CODE ? args[2].s2 :
		args[2].u4)) % IDX_MOD) + process->pos;
		vm->mem[change_pos(pos)] = process->reg[args[0].u4 - 1].byte[3];
		vm->mem[change_pos(pos + 1)] = process->reg[args[0].u4 - 1].byte[2];
		vm->mem[change_pos(pos + 2)] = process->reg[args[0].u4 - 1].byte[1];
		vm->mem[change_pos(pos + 3)] = process->reg[args[0].u4 - 1].byte[0];
		if (vm->flags.visual)
		{
			vm->vis.colors[change_pos(pos)] = (t_byte)process->player;
			vm->vis.colors[change_pos(pos + 1)] = (t_byte)process->player;
			vm->vis.colors[change_pos(pos + 2)] = (t_byte)process->player;
			vm->vis.colors[change_pos(pos + 3)] = (t_byte)process->player;
		}
	}
	move_process_pos(vm, process);
}
