/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:03:24 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void			ft_convert_nbr(int numb, int power, unsigned char *ret, int *d)
{
	long		q;
	long		t;
	long		or;
	long		l;

	if (numb < 0)
	{
		q = (power == 2) ? TWO : FOUR;
		q += numb + 1;
	}
	else
		q = numb;
	while (power)
	{
		or = 255 * ft_power(256, power - 1);
		l = (power - 1) * 8;
		t = ((q & or) >> l);
		ret[(*d)++] = t;
		power--;
	}
}
