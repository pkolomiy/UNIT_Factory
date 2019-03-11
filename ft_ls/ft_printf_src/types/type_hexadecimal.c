/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:16:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/28 22:16:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_hexadecimal(t_printf *global, t_arg *arg, t_buf *buffer)
{
	t_string	hex;
	t_number	num;
	const char	*hash = global->fmt.ptr[global->fmt.size] == 'X' ? "0X" : "0x";

	num = get_t_number(arg, global->ap, global->fmt.ptr[global->fmt.size]);
	arg->flags.hash = (t_byte)(num.val != 0 ? arg->flags.hash : 0);
	hex = get_itoa_base_string(&num, 16,
			global->fmt.ptr[global->fmt.size] == 'X');
	get_precision(arg, num.len);
	get_width(arg, num.len, (t_byte)(arg->flags.hash ? 2 : 0));
	if (!arg->flags.minus && !arg->flags.zero && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (arg->flags.hash)
		string_to_buffer(global, buffer, (t_string){(t_byte*)hash, 2});
	if (!arg->flags.minus && arg->flags.zero && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	if (arg->flags.have_precision)
		buffer_set(global, buffer, '0', arg->precision);
	if (num.len)
		string_to_buffer(global, buffer, hex);
	if (arg->flags.minus && arg->flags.have_width)
		buffer_set(global, buffer, arg->width_char, arg->width);
	ft_memdel((void**)&hex.ptr);
}
