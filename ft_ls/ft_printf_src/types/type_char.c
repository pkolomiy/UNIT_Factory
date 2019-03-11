/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/28 22:17:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_char(t_printf *global, t_arg *arg, t_buf *buffer)
{
	t_byte	c;

	c = global->fmt.ptr[global->fmt.size];
	if (c == 'c')
		c = (t_byte)va_arg(global->ap, int);
	if (arg->flags.minus)
		buffer_set(global, buffer, c, 1);
	if (arg->flags.have_width && arg->width > 1)
		buffer_set(global, buffer, arg->width_char, arg->width - 1);
	if (!arg->flags.minus)
		buffer_set(global, buffer, c, 1);
}
