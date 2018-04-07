/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:55:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:14:59 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	fill_cmd_args_mask(t_memory *vm)
{
	vm->args[0].code = 0;
	vm->args[0].size = 0;
	vm->args[0].get = NULL;
	vm->args[REG_CODE].code = T_REG;
	vm->args[REG_CODE].size = 1;
	vm->args[REG_CODE].get = &get_t_reg;
	vm->args[DIR_CODE].code = T_DIR;
	vm->args[DIR_CODE].size = 0;
	vm->args[DIR_CODE].get = &get_t_dir;
	vm->args[IND_CODE].code = T_IND;
	vm->args[IND_CODE].size = 2;
	vm->args[IND_CODE].get = &get_t_ind;
}

static void	vm_mem(t_memory *vm)
{
	int	i;

	i = 0;
	if (!(vm->mem = (unsigned char *)malloc(MEM_SIZE)))
		exit(malloc_error("vm_mem : vm->mem"));
	if (!(vm->vis.colors = (unsigned char *)malloc(MEM_SIZE)))
		exit(malloc_error("vm_mem : vm->colors"));
	if (!(vm->vis.carets = (unsigned char *)malloc(MEM_SIZE)))
		exit(malloc_error("vm_mem : vm->carets"));
	while (i < MEM_SIZE)
	{
		vm->mem[i] = 0;
		vm->vis.colors[i] = 0;
		vm->vis.carets[i] = 0;
		i++;
	}
}

static void	add_process(t_memory *vm, t_player *player, int i)
{
	t_process	*process;
	int			j;

	if (!(process = (t_process*)malloc(sizeof(t_process))))
		exit(malloc_error("add_process : process"));
	j = 0;
	process->pos = i;
	process->alive = 0;
	process->wait = 0;
	process->execute = 0;
	process->reg[0].u4 = player->nbr;
	while (++j < REG_NUMBER)
		process->reg[j].u4 = 0;
	process->player = player->pos;
	process->next = vm->processes;
	vm->processes = process;
}

static void	vm_processes(t_memory *vm, t_player *player, int step)
{
	int			i;
	unsigned	j;

	if (player->next)
		vm_processes(vm, player->next, step);
	i = step * (player->pos - 1);
	add_process(vm, player, i);
	j = 0;
	while (j < player->file->header->prog_size)
	{
		vm->mem[j + i] = player->file->program[j];
		vm->vis.colors[j + i] = (t_byte)player->pos;
		j++;
	}
}

void		vm_init(t_memory *vm)
{
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->nbr_live = 0;
	vm->max_checks = 1;
	vm->winner = vm->players->pos;
	fill_cmd_args_mask(vm);
	vm_mem(vm);
	vm_processes(vm, vm->players, MEM_SIZE / vm->players->pos);
	vm->vis.pause = 1;
	vm->vis.first_time = 1;
	vm->vis.delay = 4;
	vm->vis.nbr_processes = vm->players->pos;
	vm->vis.step = 0;
}
