/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fork_lfork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:02:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:41:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	copy_process(t_process *process, t_process *new)
{
	int			i;

	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i].u4 = process->reg[i].u4;
	new->carry = process->carry;
	new->player = process->player;
	new->alive = process->alive;
	new->execute = 0;
	new->wait = 0;
}

void		cmd_fork_lfork(t_memory *vm, t_process *process)
{
	t_process	*new;
	t_integer	dir;

	dir.byte[1] = vm->mem[change_pos(process->pos + 1)];
	dir.byte[0] = vm->mem[change_pos(process->pos + 2)];
	dir.s2 = (process->cmd.opcode == 12) ? (dir.s2 % IDX_MOD) : dir.s2;
	if (!(new = (t_process*)malloc(sizeof(t_process))))
		exit(malloc_error("cmd_fork_lfork : new"));
	new->pos = change_pos(process->pos + dir.s2);
	copy_process(process, new);
	check_command(vm, new);
	new->pos = change_pos(process->pos + dir.s2);
	if (new->wait)
		new->wait++;
	new->next = vm->processes;
	vm->processes = new;
	if (vm->flags.visual)
		vm->vis.nbr_processes++;
	process->pos = change_pos(process->pos + 3);
}
