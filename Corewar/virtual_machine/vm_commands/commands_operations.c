/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:38:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/02/25 19:30:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_byte		get_byte(t_byte *mem, int index)
{
	return (mem[change_pos(index)]);
}

int			change_pos(int move)
{
	g_recalculate_carets_positions = 1;
	return (((unsigned)(MEM_SIZE + move)) % MEM_SIZE);
}

int			get_move_size(t_memory *vm, t_codage codage, t_byte args_num)
{
	return (vm->args[codage.bits.first].size +
	(args_num >= 2 ? vm->args[codage.bits.second].size : 0) +
	(args_num == 3 ? vm->args[codage.bits.third].size : 0));
}

void		move_process_pos(t_memory *vm, t_process *process)
{
	int	move;

	move = get_move_size(vm, process->codage, process->cmd.args_num);
	process->pos = change_pos(process->pos + 2 + move);
}

t_integer	update_argument(t_memory *vm, t_process *process, t_byte number,
														t_integer old_argument)
{
	if (number == 1 && (process->codage.bits.first == REG_CODE ||
	process->codage.bits.first == IND_CODE))
	{
		return ((process->codage.bits.first == REG_CODE) ?
		process->reg[old_argument.u4 - 1] :
		get_ind_bytes(vm->mem, old_argument, process->pos));
	}
	else if (number == 2 && (process->codage.bits.second == REG_CODE ||
	process->codage.bits.second == IND_CODE))
	{
		return ((process->codage.bits.second == REG_CODE) ?
		process->reg[old_argument.u4 - 1] :
		get_ind_bytes(vm->mem, old_argument, process->pos));
	}
	else if (number == 3 && (process->codage.bits.third == REG_CODE ||
	process->codage.bits.third == IND_CODE))
	{
		return ((process->codage.bits.third == REG_CODE) ?
		process->reg[old_argument.u4 - 1] :
		get_ind_bytes(vm->mem, old_argument, process->pos));
	}
	return (old_argument);
}
