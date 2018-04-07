/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:53:12 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cmd_zjmp(t_memory *vm, t_process *process)
{
	t_integer	dir;

	dir.byte[1] = vm->mem[change_pos(process->pos + 1)];
	dir.byte[0] = vm->mem[change_pos(process->pos + 2)];
	dir.s2 %= IDX_MOD;
	process->pos = change_pos(process->pos + (process->carry ? dir.s2 : 3));
}
