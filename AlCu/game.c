/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 21:24:29 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/05/21 21:38:48 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		check_sum(t_alum *alum, int n, int i)
{
	while (++i < alum->len)
		n += alum->board[i];
	return (n);
}

int		user_turn(t_alum *alum, int n, int i, int k)
{
	if (n == 1)
	{
		print_board(alum);
		lost();
	}
	else
	{
		print_board(alum);
		write(1, "It's your turn!\nEnter number from 1 to 3: ", 42);
		while (i == 0)
			i = read_number(alum->board[alum->index]);
		write(1, "\n\e[32mPLAYER\e[0m: ", 18);
		ft_putnbr(i);
		write(1, "\n", 1);
		alum->board[alum->index] -= i;
		if (alum->board[alum->index] == 0)
			alum->index -= 1;
		k = 1;
		if (check_sum(alum, 0, -1) == 0)
		{
			lost();
			k = 0;
		}
	}
	return (k);
}

void	computer_turn(t_alum *alum, int k)
{
	int i;

	write(1, "It is computer's turn!\n", 23);
	i = ((k - 1) % 4 == 0) || ((k - 1) % 4 > alum->board[alum->index]) ?
		1 : (k - 1) % 4;
	write(1, "\n\e[31mCOMPUTER\e[0m: ", 20);
	ft_putnbr(i);
	write(1, "\n", 1);
	alum->board[alum->index] -= i;
	if (alum->board[alum->index] == 0)
		alum->index -= 1;
}

void	game(t_alum *alum)
{
	int i;
	int k;

	i = 0;
	alum->index = alum->len - 1;
	while (check_sum(alum, 0, -1))
	{
		if (!user_turn(alum, check_sum(alum, 0, -1), 0, 0))
			break ;
		if ((k = check_sum(alum, 0, -1)) == 1)
		{
			print_board(alum);
			won();
			break ;
		}
		else
		{
			print_board(alum);
			computer_turn(alum, k);
			check_sum(alum, 0, -1) == 0 ? won() : 0;
		}
	}
}
