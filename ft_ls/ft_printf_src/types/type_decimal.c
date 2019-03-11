/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:16:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/28 22:16:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_byte	get_sign(t_flags flags)
{
	if (flags.negative)
		return ('-');
	else if (flags.plus)
		return ('+');
	else if (flags.space)
		return (' ');
	return (0);
}

void			type_decimal(t_printf *global, t_arg *arg, t_buf *buffer)
{
	t_number	num;
	t_byte		sign;

	num = get_t_number(arg, global->ap, global->fmt.ptr[global->fmt.size]);
	sign = get_sign(arg->flags);
	get_precision(arg, num.len);
	get_width(arg, num.len, (t_byte)(sign != 0));
	if (!arg->flags.minus && !arg->flags.zero && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (sign)
		buffer_set(global, buffer, sign, 1);
	if (!arg->flags.minus && arg->flags.zero && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (arg->flags.have_precision)
		buffer_set(global, buffer, '0', arg->precision);
	if (num.len)
		decimal_to_buffer(global, buffer, num);
	if (arg->flags.minus && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
}
