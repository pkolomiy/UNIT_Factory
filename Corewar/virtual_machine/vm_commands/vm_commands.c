/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:18:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/29 23:19:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static _Bool	validate_codage(t_memory *vm, t_process *process, t_op cmd)
{
	t_bits	bit;
	int		result;
	int		move_pos;

	process->codage.byte = get_byte(vm->mem, process->pos + 1);
	bit = process->codage.bits;
	if (cmd.args_num == 3)
		result = (((cmd.arg[0] & vm->args[bit.first].code) != 0) << 2) |
		(((cmd.arg[1] & vm->args[bit.second].code) != 0) << 1) |
		((cmd.arg[2] & vm->args[bit.third].code) != 0);
	else if (cmd.args_num == 2)
		result = 4 | (((cmd.arg[0] & vm->args[bit.first].code) != 0) << 1) |
		((cmd.arg[1] & vm->args[bit.second].code) != 0);
	else
		result = 6 | ((cmd.arg[0] & vm->args[bit.first].code) != 0);
	move_pos = get_move_size(vm, process->codage, cmd.args_num);
	if (result != 7)
		process->pos = change_pos(process->pos + move_pos + 2);
	return (result == 7);
}

void			check_command(t_memory *vm, t_process *process)
{
	if (process->execute)
	{
		vm->args[DIR_CODE].size = process->cmd.t_dir_size;
		if (!(process->cmd.codage) ||
		validate_codage(vm, process, process->cmd))
			process->cmd.command(vm, process);
		process->execute = 0;
	}
	else if (vm->mem[process->pos] >= 1 && vm->mem[process->pos] <= 16)
	{
		process->cmd = g_op_tab[vm->mem[process->pos] - 1];
		process->cmd.command = g_command[vm->mem[process->pos] - 1];
		process->execute = 1;
		process->wait = process->cmd.wait - 2;
	}
	else
		process->pos = change_pos(process->pos + 1);
}

void			vm_commands(t_memory *vm)
{
	t_process	*process;

	process = vm->processes;
	while (process)
	{
		if (!process->wait)
			check_command(vm, process);
		else
			process->wait--;
		process = process->next;
	}
}
