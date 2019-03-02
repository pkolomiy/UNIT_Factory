/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:55:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/26 20:32:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	filtrate_flags(t_arg *arg, char c)
{
	if (arg->h_counter && arg->h_counter % 2 == 1)
		arg->flags.h = 1;
	else if (arg->h_counter)
		arg->flags.hh = 1;
	if ((arg->l_counter && arg->l_counter % 2 == 1) ||
		c == 'D' || c == 'O' || c == 'U')
		arg->flags.l = 1;
	else if (arg->l_counter)
		arg->flags.ll = 1;
	if (arg->flags.plus == 1)
		arg->flags.space = 0;
	if (((c == 'd' || c == 'p' || c == 'D' || c == 'i' || c == 'o' ||
	c == 'O' || c == 'x' || c == 'X' || c == 'u' || c == 'U') &&
	arg->flags.have_precision) || arg->flags.minus == 1)
		arg->flags.zero = 0;
	arg->width_char = (t_byte)(arg->flags.zero ? '0' : ' ');
	return (c);
}

void		parse_arg(t_printf *global, t_buf *buffer)
{
	t_arg	arg;
	char	c;

	ft_bzero(&arg, sizeof(t_arg));
	parse_flags(global, &arg);
	c = filtrate_flags(&arg, global->fmt.ptr[global->fmt.size]);
	if (c == 's')
		type_string(global, &arg, buffer);
	else if (c == 'd' || c == 'i' || c == 'D')
		type_decimal(global, &arg, buffer);
	else if (c == 'u' || c == 'U')
		type_unsigned(global, &arg, buffer);
	else if (c == 'o' || c == 'O')
		type_octal(global, &arg, buffer);
	else if (c == 'x' || c == 'X')
		type_hexadecimal(global, &arg, buffer);
	else if (c == 'p')
		type_pointer(global, &arg, buffer);
	else if (c != 0)
		type_char(global, &arg, buffer);
}
