/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/28 22:17:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_unsigned(t_printf *global, t_arg *arg, t_buf *buffer)
{
	t_number	num;

	num = get_t_number(arg, global->ap, global->fmt.ptr[global->fmt.size]);
	get_precision(arg, num.len);
	get_width(arg, num.len, 0);
	if (!arg->flags.minus && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (arg->flags.have_precision)
		buffer_set(global, buffer, '0', arg->precision);
	if (num.len)
		decimal_to_buffer(global, buffer, num);
	if (arg->flags.minus && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
}
