/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:34:02 by kzahreba          #+#    #+#             */
/*   Updated: 2017/05/21 20:26:05 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	char			print;

	print = 0;
	nb = n < 0 ? -n : n;
	if (n < 0)
		write(1, "-", 1);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		print = nb + '0';
		write(1, &print, 1);
	}
}
