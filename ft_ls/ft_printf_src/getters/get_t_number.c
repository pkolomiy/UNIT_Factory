/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:58:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/02 11:58:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_number	get_unsigned(t_arg *arg, va_list ap)
{
	t_number	num;

	if (arg->flags.z)
		num.val = va_arg(ap, size_t);
	else if (arg->flags.j)
		num.val = (size_t)va_arg(ap, uintmax_t);
	else if (arg->flags.ll)
		num.val = (size_t)va_arg(ap, unsigned long long);
	else if (arg->flags.l)
		num.val = (size_t)va_arg(ap, unsigned long);
	else if (arg->flags.h)
		num.val = (size_t)((unsigned short)va_arg(ap, unsigned int));
	else if (arg->flags.hh)
		num.val = (size_t)((unsigned char)va_arg(ap, unsigned int));
	else
		num.val = (size_t)va_arg(ap, unsigned int);
	num.len = 1;
	return (num);
}

static t_number	get_signed(t_arg *arg, va_list ap)
{
	intmax_t	temp;
	t_number	num;

	if (arg->flags.z || arg->flags.j)
		temp = va_arg(ap, intmax_t);
	else if (arg->flags.ll)
		temp = (intmax_t)va_arg(ap, long long);
	else if (arg->flags.l)
		temp = (intmax_t)va_arg(ap, long);
	else if (arg->flags.h)
		temp = (intmax_t)((short)va_arg(ap, int));
	else if (arg->flags.hh)
		temp = (intmax_t)((char)va_arg(ap, int));
	else
		temp = (intmax_t)va_arg(ap, int);
	arg->flags.negative = (t_byte)(temp < 0);
	num.val = (size_t)(temp < 0 ? -temp : temp);
	num.len = 1;
	return (num);
}

t_number		get_t_number(t_arg *arg, va_list ap, char c)
{
	t_number	num;

	if (c == 'u' || c == 'x' || c == 'o' ||
		c == 'U' || c == 'X' || c == 'O')
		num = get_unsigned(arg, ap);
	else
		num = get_signed(arg, ap);
	if (num.val == 0 && (((c == 'o' || c == 'O') && arg->flags.hash) ||
		(arg->flags.have_precision && !arg->precision)))
		num.len = 0;
	else if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
		num.len = (t_byte)ft_nbrlen(num.val);
	return (num);
}
