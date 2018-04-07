/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:18:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/29 23:08:55 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	vm_dump(t_memory *vm)
{
	int		i;
	char	*str;

	i = 1;
	str = "0123456789abcdef";
	if (vm->flags.visual)
		endwin();
	while (i <= MEM_SIZE)
	{
		write(1, &str[vm->mem[i - 1] >> 4], 1);
		write(1, &str[vm->mem[i - 1] & 0xF], 1);
		write(1, i % 64 ? " " : "\n", 1);
		i++;
	}
	return (0);
}

static void	kill_processes(t_memory *vm, _Bool *sound)
{
	t_process	*cur;
	t_process	*prev;

	prev = NULL;
	cur = vm->processes;
	while (cur)
	{
		if (cur->alive)
		{
			cur->alive = 0;
			prev = cur;
			cur = cur->next;
		}
		else
		{
			(prev) ? (prev->next = cur->next) :
			(vm->processes = vm->processes->next);
			free(cur);
			*sound = 1;
			if (vm->flags.visual)
				vm->vis.nbr_processes--;
			cur = prev ? prev->next : vm->processes;
		}
	}
}

static void	reduce_cycle_to_die(t_memory *vm)
{
	t_player	*tmp;
	_Bool		sound;

	sound = 0;
	kill_processes(vm, &sound);
	if (sound && vm->flags.visual)
		system("afplay virtual_machine/sound/dead.wav &");
	if (vm->flags.visual)
	{
		tmp = vm->players;
		while (tmp)
		{
			tmp->current_lives = 0;
			tmp = tmp->next;
		}
	}
	if (vm->nbr_live >= NBR_LIVE ||
	vm->max_checks == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->max_checks = 1;
	}
	else
		vm->max_checks++;
	vm->nbr_live = 0;
}

static void	last_operation_kostyl(t_memory *vm)
{
	vm_commands(vm);
	reduce_cycle_to_die(vm);
	vm->cycle++;
	reduce_cycle_to_die(vm);
	vm->cycle_to_die = 0;
	g_recalculate_carets_positions = 1;
}

void		vm_program(t_memory *vm)
{
	int	i;

	i = 1;
	g_recalculate_carets_positions = 1;
	while (vm->cycle_to_die > 0 && vm->processes)
	{
		if (vm->flags.dump && vm->flags.nbr == (unsigned)(vm->cycle))
			exit(vm_dump(vm));
		if (vm->flags.visual && vm->cycle >= vm->vis.step)
			vm_visualizer(vm, 0);
		vm_commands(vm);
		if (i == vm->cycle_to_die)
		{
			reduce_cycle_to_die(vm);
			i = 0;
		}
		i++;
		vm->cycle++;
	}
	last_operation_kostyl(vm);
	if (vm->flags.visual)
		vm_visualizer(vm, 1);
}
