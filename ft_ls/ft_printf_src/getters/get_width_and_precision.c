/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_and_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:24:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/02 14:24:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_arg *arg, t_byte num_len, t_byte sign)
{
	int	temp;

	if (arg->flags.have_width)
	{
		temp = (int)(arg->width - arg->precision - num_len);
		temp -= sign;
		if (temp <= 0)
		{
			arg->flags.have_width = 0;
			arg->width = 0;
		}
		else
			arg->width = (size_t)(temp);
	}
}

void	get_precision(t_arg *arg, t_byte num_len)
{
	int	temp;

	if (arg->flags.have_precision)
	{
		temp = (int)(arg->precision - num_len);
		if (temp <= 0)
		{
			arg->flags.have_precision = 0;
			arg->precision = 0;
		}
		else
			arg->precision = (size_t)(temp);
	}
}
