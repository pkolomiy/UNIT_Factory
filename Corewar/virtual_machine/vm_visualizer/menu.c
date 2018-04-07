/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 23:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/02/28 01:05:16 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	start_color();
	init_pair(1, 8, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, 8, 8);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_GREEN, COLOR_GREEN);
	init_pair(12, COLOR_BLUE, COLOR_BLUE);
	init_pair(13, COLOR_RED, COLOR_RED);
	init_pair(14, COLOR_CYAN, COLOR_CYAN);
	nodelay(stdscr, TRUE);
}

static void	players_and_keypad(t_memory *vm)
{
	t_player	*tmp;

	tmp = vm->players;
	attron(A_BOLD);
	while (tmp)
	{
		mvprintw(7 + (tmp->pos * 4), 192 + 7, "Player %d", tmp->pos);
		attron(COLOR_PAIR(tmp->pos + 1));
		mvprintw(7 + (tmp->pos * 4), 192 + 17, "%.25s",
				tmp->file->header->prog_name);
		attroff(COLOR_PAIR(tmp->pos + 1));
		tmp = tmp->next;
	}
	mvprintw(36, 200, "[SPACE]  -  Play / Pause");
	mvprintw(38, 200, "'S'      -  One Step");
	mvprintw(40, 200, "'H'      -  100 Steps");
	mvprintw(42, 200, "'T'      -  1000 Steps");
	mvprintw(44, 200, "[UP]     -  Increase Delay");
	mvprintw(46, 200, "[DOWN]   -  Decrease Delay");
	mvprintw(48, 200, "[ESC]    -  Exit");
	attroff(A_BOLD);
}

static void	gray_lines(void)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(6));
	while (i < 240)
	{
		mvprintw(0, i, " ");
		mvprintw(67, i, " ");
		if (i > 196)
			mvprintw(34, i, " ");
		i++;
	}
	i = 0;
	while (i < 67)
	{
		mvprintw(i, 0, " ");
		mvprintw(i, 196, " ");
		mvprintw(i, 239, " ");
		i++;
	}
	attroff(COLOR_PAIR(6));
}

static void	players_lives(t_player *players)
{
	int	pos;

	while (players)
	{
		pos = 9 + (players->pos * 4);
		mvprintw(pos - 1, 201, "Last live %10d", players->last_live);
		mvprintw(pos, 201, "Current lives %6d", players->current_lives);
		players = players->next;
	}
}

void		menu(t_memory *vm)
{
	if (vm->vis.first_time)
	{
		vm->vis.first_time = 0;
		init();
		players_and_keypad(vm);
		gray_lines();
	}
	attron(A_BOLD);
	if (vm->vis.delay)
		mvprintw(4, 199, "Delay %16d", vm->vis.delay);
	else
		mvprintw(4, 199, "       No Delay       ");
	mvprintw(7, 199, "Cycle %16d", vm->cycle);
	mvprintw(9, 199, "Processes %12d", vm->vis.nbr_processes);
	mvprintw(13 + (vm->players->pos * 4), 199, "CYCLE_TO_DIE %9d",
												vm->cycle_to_die);
	players_lives(vm->players);
	attroff(A_BOLD);
}
