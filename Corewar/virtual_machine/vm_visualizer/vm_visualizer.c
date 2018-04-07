/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_visualizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:57:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/12 14:59:59 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		fill_carets_position(t_process *processes, t_byte *carets)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		carets[i] = 0;
		i++;
	}
	while (processes)
	{
		carets[processes->pos] = 1;
		processes = processes->next;
	}
	g_recalculate_carets_positions = 0;
}

static void		fill_map(t_memory *vm, int i, int x, int y)
{
	if (vm->vis.colors[i - 1] + 1 == 1)
		attron(A_BOLD);
	if (vm->vis.carets[i - 1])
		attron(COLOR_PAIR(vm->vis.colors[i - 1] + 6));
	else
		attron(COLOR_PAIR(vm->vis.colors[i - 1] + 1));
	mvprintw(y, x, "%.2x", vm->mem[i - 1]);
	if (vm->vis.colors[i - 1] + 1 == 1)
		attroff(A_BOLD);
	if (vm->vis.carets[i - 1])
		attroff(COLOR_PAIR(vm->vis.colors[i - 1] + 6));
	else
		attroff(COLOR_PAIR(vm->vis.colors[i - 1] + 1));
	mvprintw(y, x + 2, " ");
}

static void		show_player_name(t_player *players, int winner)
{
	attron(A_BOLD);
	while (players)
	{
		if (players->pos == winner)
		{
			attron(COLOR_PAIR(winner + 1));
			mvprintw(64, 210, "%.25s", players->file->header->prog_name);
			attroff(COLOR_PAIR(winner + 1));
			break ;
		}
		players = players->next;
	}
	attroff(A_BOLD);
	attron(A_REVERSE);
	mvprintw(31, 197, "                                          ");
	mvprintw(32, 197, "            PRESS ESC TO EXIT             ");
	mvprintw(33, 197, "                                          ");
	attroff(A_REVERSE);
	while (1)
		if (getch() == 27)
			exit(endwin());
}

static void		show_winner(t_player *players, int winner)
{
	char	*str;
	int		x;
	int		y;

	str = "1   1 111 1   1 1   1 1111 111101   1  1  11  1 11  1 1    1   101 1"
	" 1  1  1 1 1 1 1 1 1111 111101 1 1  1  1  11 1  11 1    1  10 1 1  111 1  "
	" 1 1   1 1111 1   100           111   111110            1   10            "
	"1    111110            1         10           111   111110";
	x = 201;
	y = 51;
	while (*str)
	{
		if (*str == '1')
			attron(COLOR_PAIR(winner + 10));
		if (*str == ' ' || *str == '0')
			attroff(COLOR_PAIR(winner + 10));
		mvprintw(y, x, " ");
		x = (*str == '0' ? 201 : x + 1);
		y = (*str == '0' ? y + 1 : y);
		str++;
	}
	show_player_name(players, winner);
}

void			vm_visualizer(t_memory *vm, _Bool flag)
{
	int	i;
	int	x;
	int	y;

	i = 1;
	x = 3;
	y = 2;
	menu(vm);
	if (g_recalculate_carets_positions)
		fill_carets_position(vm->processes, vm->vis.carets);
	while (i <= MEM_SIZE)
	{
		fill_map(vm, i, x, y);
		x += 3;
		if (i % 64 == 0)
		{
			x = 3;
			y++;
		}
		i++;
	}
	refresh();
	if (flag)
		show_winner(vm->players, vm->winner);
	key_press(vm);
}
