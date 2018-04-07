/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:14:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/29 23:15:55 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	usage(void)
{
	write(1, "./corewar [-l] [-v] [-dump nbr_cycles]"
	"[[-n number] champion1.cor] ...\n\t   "
	"-l\t\t\t: Shows lives and Aff (Default is to hide it)\n\t   "
	"-v\t\t\t: Visualization (optional)\n"
	"\t   -dump \e[1mnbr_cycles\e[0m\t: Dumps memory after \e[1mnbr_cycles\e[0m"
	" then exits (optional) \n\t   -n \e[1mnumber\e[0m\t\t: Sets the"
	" \e[1mnumber\e[0m of the next player (optional)\n"
	"", 332);
	return (0);
}

static void	winner_is(t_memory *vm)
{
	t_player	*tmp;
	char		*str;

	tmp = vm->players;
	while (tmp)
	{
		if (tmp->pos == vm->winner)
		{
			write(1, "And the winner is: \"", 20);
			str = tmp->file->header->prog_name;
			write(1, str, string_len(str));
			write(1, "\"\n", 2);
			break ;
		}
		tmp = tmp->next;
	}
}

static void	welcome_contestants(t_player *player)
{
	char	c;

	if (player->next)
		welcome_contestants(player->next);
	c = (char)(player->pos + 48);
	write(1, "Player ", 7);
	write(1, &c, 1);
	write(1, ", \"", 3);
	write(1, player->file->header->prog_name,
		string_len(player->file->header->prog_name));
	write(1, "\" (\"", 4);
	write(1, player->file->header->comment,
		string_len(player->file->header->comment));
	write(1, "\") !\n", 5);
}

void		fill_array_with_pointers_to_function(void)
{
	g_command[0] = &cmd_live;
	g_command[1] = &cmd_ld_lld;
	g_command[2] = &cmd_st;
	g_command[3] = &cmd_add_sub;
	g_command[4] = &cmd_add_sub;
	g_command[5] = &cmd_and_or_xor;
	g_command[6] = &cmd_and_or_xor;
	g_command[7] = &cmd_and_or_xor;
	g_command[8] = &cmd_zjmp;
	g_command[9] = &cmd_ldi_lldi;
	g_command[10] = &cmd_sti;
	g_command[11] = &cmd_fork_lfork;
	g_command[12] = &cmd_ld_lld;
	g_command[13] = &cmd_ldi_lldi;
	g_command[14] = &cmd_fork_lfork;
	g_command[15] = &cmd_aff;
}

int			main(int argc, char **argv)
{
	t_memory	vm;
	char		*error;

	vm.processes = NULL;
	vm.players = NULL;
	if (argc == 1)
		return (usage());
	if (!(vm_args(argv, &vm.players, &vm.flags, &error)))
	{
		write(2, error, string_len(error));
		return (1);
	}
	if (!vm.flags.visual)
	{
		write(1, "Welcome contestants:\n", 21);
		welcome_contestants(vm.players);
	}
	vm_init(&vm);
	fill_array_with_pointers_to_function();
	vm_program(&vm);
	if (!vm.flags.visual)
		winner_is(&vm);
	return (0);
}
