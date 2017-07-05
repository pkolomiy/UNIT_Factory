/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <kzahreba@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:09:18 by kzahreba          #+#    #+#             */
/*   Updated: 2017/05/21 21:39:13 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	print_board(t_alum *alum)
{
	int i;
	int n;

	i = -1;
	write(1, "\n", 1);
	while (++i < alum->len && alum->board[i])
	{
		ft_putnbr(i + 1);
		write(1, ") ", 2);
		n = alum->board[i] + 1;
		while (--n)
			write(1, "| ", 2);
		write(1, "\n", 1);
	}
	n = 66;
	write(1, "\n", 1);
	while (--n)
		write(1, "~", 1);
	write(1, "\n\n", 2);
}

int		check(int i, int num)
{
	if (num < i)
	{
		write(1, "\nThere is not enough matches in the row.\n", 41);
		write(1, "Take less matches: ", 19);
		i = 0;
	}
	return (i);
}

int		read_number(int num)
{
	char	buf[1];
	char	c[2];
	int		i;

	i = 0;
	while (read(1, buf, 1) > 0)
	{
		i == 0 ? c[0] = buf[0] : 0;
		i == 1 ? c[1] = buf[0] : 0;
		if (buf[0] == '\n')
			break ;
		i++;
	}
	i = 0;
	if (c[1] != '\n' || c[0] < '1' || c[0] > '3')
		write(1, "Incorrect input, enter number from 1 to 3: ", 43);
	else
		i = check(c[0] - 48, num);
	return (i);
}
