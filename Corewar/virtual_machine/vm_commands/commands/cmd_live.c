/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/27 18:41:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	check(t_memory *vm, t_player *player)
{
	char	*name;
	char	player_num;

	vm->winner = player->pos;
	if (!vm->flags.visual && vm->flags.live)
	{
		player_num = (char)(player->pos + 48);
		name = player->file->header->prog_name;
		write(1, "A process shows that player ", 28);
		write(1, &player_num, 1);
		write(1, " (", 2);
		write(1, name, string_len(name));
		write(1, ") is alive\n", 11);
	}
	if (vm->flags.visual)
	{
		player->last_live = vm->cycle + 1;
		player->current_lives++;
	}
}

void		cmd_live(t_memory *vm, t_process *process)
{
	t_integer	dir;
	t_player	*tmp;

	process->alive = 1;
	vm->nbr_live++;
	dir.byte[3] = vm->mem[change_pos(process->pos + 1)];
	dir.byte[2] = vm->mem[change_pos(process->pos + 2)];
	dir.byte[1] = vm->mem[change_pos(process->pos + 3)];
	dir.byte[0] = vm->mem[change_pos(process->pos + 4)];
	tmp = vm->players;
	while (tmp)
	{
		if (tmp->nbr == dir.u4)
		{
			check(vm, tmp);
			break ;
		}
		tmp = tmp->next;
	}
	process->pos = change_pos(process->pos + 5);
}
