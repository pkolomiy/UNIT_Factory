/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:42:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/27 22:42:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_string(t_printf *global, t_arg *arg, t_buf *buffer)
{
	t_string	str;

	str.ptr = (t_byte*)va_arg(global->ap, char*);
	if (str.ptr == NULL)
		str = (t_string){(t_byte *)"(null)", 6};
	else
		str.size = ft_strlen((char*)str.ptr);
	if (arg->flags.have_precision && str.size && str.size > arg->precision)
		str.size = arg->precision;
	if (arg->flags.minus && str.size)
		string_to_buffer(global, buffer, str);
	if (arg->flags.have_width && (int)(arg->width - str.size) > 0)
		buffer_set(global, buffer, arg->width_char, arg->width - str.size);
	if (!arg->flags.minus && str.size)
		string_to_buffer(global, buffer, str);
}
