/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 23:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/02/27 23:07:44 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	delay_change(t_memory *vm, int k)
{
	attron(A_BOLD);
	vm->vis.delay += (k == 259 ? 1 : -1);
	if (vm->vis.delay)
		mvprintw(4, 192 + 7, "Delay %16d", vm->vis.delay);
	else
		mvprintw(4, 192 + 7, "       No Delay       ");
	attroff(A_BOLD);
}

void		key_press(t_memory *vm)
{
	int k;

	while (1)
	{
		k = getch();
		if (k == 27)
			exit(endwin());
		else if ((k == 258 && vm->vis.delay) ||
		(k == 259 && vm->vis.delay < 5))
			delay_change(vm, k);
		else if (k == 32)
			vm->vis.pause = (vm->vis.pause == 0);
		else if (k == 's' || k == 'h' || k == 't')
		{
			if (k != 's')
				vm->vis.step = vm->cycle + (k == 'h' ? 100 : 1000);
			break ;
		}
		if (!vm->vis.pause)
		{
			if (vm->vis.delay)
				usleep((useconds_t)(1 << (vm->vis.delay * 4)));
			break ;
		}
	}
}
