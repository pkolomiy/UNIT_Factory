/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 22:40:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/08 23:05:26 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <curses.h>

void	set_visualizer(void)
{
	FILE	*f;

	SCREEN * screen;
	f = fopen("/dev/tty", "r+");
	screen = newterm(NULL, f, f);
	set_term(screen);
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(1);
	getch();
	write(1, "\e[?25l\e[2J\e[H"
	"\r\e[1m+-----------------+ +------------------+\n"
	"\r| [\e[32mSpace\e[0m\e[1m] - start | "
	"| [\e[32mEnter\e[0m\e[1m] - finish |\n\r"
	"+-----------------+ +------------------+\e[0m\n\n", 174);
}

void	show_stack(t_main *m, t_stack *a, t_stack *b, char *inst)
{
	write(1, "\rOperation [\e[31;1m", 19);
	write(1, inst, (inst[2] ? 3 : 2));
	write(1, "\e[0m] Iterator [\e[1m", 20);
	nbr(m->temp);
	write(1, "\e[0m]\n\n\r\e[1mSTACK A(", 20);
	nbr(m->a_len);
	write(1, "): \e[33m", 8);
	while (a)
	{
		nbr(a->nbr);
		if (a->next)
			write(1, " ", 1);
		a = a->next;
	}
	write(1, "\e[0m\n\n\r\e[1mSTACK B(", 19);
	nbr(m->b_len);
	write(1, "): \e[35m", 8);
	while (b)
	{
		nbr(b->nbr);
		if (b->next)
			write(1, " ", 1);
		b = b->next;
	}
	write(1, "\e[0m\n\n", 6);
}

void	status_bar(t_main *m, _Bool pause)
{
	write(1, "\e[2J\e[H", 7);
	if (pause)
	{
		write(1, "\r\e[1m+-----------------+ +------------------+\n"
		"\r| [\e[32mSpace\e[0m\e[1m] - pause | "
		"| [\e[32mEnter\e[0m\e[1m] - finish |\n"
		"\r+-----------------+ +------------------+\e[0m\n\n", 161);
	}
	else
	{
		write(1, "\r\e[1m+---------------+ +----------------+ "
		"+----------------+ +------------------+\n"
		"\r| [\e[32mLeft\e[0m\e[1m] - back | | [\e[32mSpace\e[0m\e[1m] - play |"
		" | [\e[32mRight\e[0m\e[1m] - next | | [\e[32mEnter\e[0m\e[1m] - finish"
		" |\n\r+---------------+ +----------------+ +----------------+ "
		"+------------------+\e[0m\n\n", 295);
	}
	show_stack(m, m->a, m->b, m->tmp->inst);
}

void	manual_control(t_main *m, int key)
{
	while (!m->final && key != SPACE)
	{
		key = getch();
		m->final = key == ENTER;
		if (key == LEFT && m->tmp->prev && --m->temp)
		{
			if (m->tmp->inst[0] == 'p')
				pa_pb((m->tmp->inst[1] == 'a' ? PB : PA), m);
			else if (m->tmp->inst[0] == 's' && m->tmp->inst[1] != 's')
				sa_sb_ss(m->tmp->inst[1] == 'a' ? SA : SB, m);
			else if (m->tmp->inst[0] == 'r' && m->tmp->inst[1] != 'r')
				rra_rrb_rrr((m->tmp->inst[1] == 'a' ? RRA : RRB), m);
			else if (m->tmp->inst[0] == 's' || !m->tmp->inst[2])
				m->tmp->inst[0] == 's' ? sa_sb_ss(SS, m) : rra_rrb_rrr(RRR, m);
			else if (m->tmp->inst[2] != 'r')
				ra_rb_rr((m->tmp->inst[2] == 'a' ? RA : RB), m);
			else
				ra_rb_rr(RR, m);
			m->tmp = m->tmp->prev;
		}
		else if (key == RIGHT && m->tmp->next && ++m->temp)
			m->tmp = m->tmp->next;
		(key == RIGHT) ? apply(m, m->tmp->inst) : 0;
		(key == LEFT || key == RIGHT) ? status_bar(m, 0) : 0;
	}
}

void	visualizer(t_main *m)
{
	static _Bool	first = 0;
	int				key;

	(!first) ? set_visualizer() : 0;
	while (!first && !m->final)
	{
		key = getch();
		first = (key == SPACE || key == ENTER) ? 1 : 0;
		m->final = key == ENTER;
	}
	if (!m->final)
	{
		status_bar(m, 1);
		sleep(1);
		key = getch();
		m->final = key == ENTER;
		(key == SPACE) ? status_bar(m, 0) : 0;
		(key == SPACE) ? manual_control(m, 0) : 0;
	}
	if (!m->tmp->next)
	{
		endwin();
		write(1, "\e[2J\e[H\e[?25h", 13);
		show_stack(m, m->a, m->b, m->tmp->inst);
	}
}
