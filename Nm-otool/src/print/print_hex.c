/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:31:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/16 12:31:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

#define HEX "0123456789abcdef"

void	print_hex(uint64_t nbr, int width)
{
	char	hex[16];
	int		i;

	i = -1;
	while (++i < width)
		hex[i] = '0';
	while (nbr)
	{
		hex[--i] = HEX[nbr % 16];
		nbr /= 16;
	}
	write(1, hex, width);
}
