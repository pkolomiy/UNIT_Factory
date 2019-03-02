/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:16:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/28 22:16:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_octal(t_printf *global, t_arg *arg, t_buf *buffer)
{
	t_string	oct;
	t_number	num;

	num = get_t_number(arg, global->ap, global->fmt.ptr[global->fmt.size]);
	oct = get_itoa_base_string(&num, 8, 0);
	get_precision(arg, num.len + arg->flags.hash);
	get_width(arg, num.len, arg->flags.hash);
	if (!arg->flags.minus && !arg->flags.zero && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (arg->flags.hash)
		buffer_set(global, buffer, '0', 1);
	if (!arg->flags.minus && arg->flags.zero && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (arg->flags.have_precision)
		buffer_set(global, buffer, '0', arg->precision);
	if (num.len)
		string_to_buffer(global, buffer, oct);
	if (arg->flags.minus && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	ft_memdel((void**)&oct.ptr);
}
