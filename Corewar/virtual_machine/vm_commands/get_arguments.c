/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:13:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/29 22:58:50 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_integer	get_ind_bytes(const t_byte *mem, t_integer ind, int pos)
{
	t_integer	ret;

	ret.byte[3] = mem[change_pos(ind.s2 + pos)];
	ret.byte[2] = mem[change_pos(ind.s2 + pos + 1)];
	ret.byte[1] = mem[change_pos(ind.s2 + pos + 2)];
	ret.byte[0] = mem[change_pos(ind.s2 + pos + 3)];
	return (ret);
}

t_integer	get_t_reg(const t_byte *mem, int pos, t_op cmd, _Bool *error)
{
	t_integer	reg;

	(void)cmd;
	reg.u4 = mem[pos];
	if (reg.u4 < 1 || reg.u4 > 16)
	{
		*error = 1;
	}
	return (reg);
}

t_integer	get_t_dir(const t_byte *mem, int pos, t_op cmd, _Bool *error)
{
	t_integer	dir;

	(void)error;
	dir.u4 = 0;
	if (cmd.t_dir_size == 2)
	{
		dir.byte[1] = mem[pos];
		dir.byte[0] = mem[change_pos(pos + 1)];
	}
	else
	{
		dir.byte[3] = mem[pos];
		dir.byte[2] = mem[change_pos(pos + 1)];
		dir.byte[1] = mem[change_pos(pos + 2)];
		dir.byte[0] = mem[change_pos(pos + 3)];
	}
	return (dir);
}

t_integer	get_t_ind(const t_byte *mem, int pos, t_op cmd, _Bool *error)
{
	t_integer	ind;

	(void)error;
	ind.u4 = 0;
	ind.byte[1] = mem[pos];
	ind.byte[0] = mem[change_pos(pos + 1)];
	if (cmd.opcode != 13 && cmd.opcode != 15 && cmd.opcode != 3)
		ind.s2 %= IDX_MOD;
	return (ind);
}

_Bool		get_arguments(t_memory *vm, t_process *process, t_integer args[])
{
	_Bool	error;

	error = 0;
	if (process->cmd.args_num > 0)
	{
		args[0] = vm->args[process->codage.bits.first].
		get(vm->mem, change_pos(process->pos + 2), process->cmd, &error);
	}
	if (process->cmd.args_num > 1)
	{
		args[1] = vm->args[process->codage.bits.second].
		get(vm->mem, change_pos(process->pos + 2 +
			vm->args[process->codage.bits.first].size), process->cmd, &error);
	}
	if (process->cmd.args_num > 2)
	{
		args[2] = vm->args[process->codage.bits.third].
		get(vm->mem, change_pos(process->pos + 2 +
			vm->args[process->codage.bits.first].size +
			vm->args[process->codage.bits.second].size), process->cmd, &error);
	}
	return (error);
}
