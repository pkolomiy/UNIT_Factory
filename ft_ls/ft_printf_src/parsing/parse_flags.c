/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:50:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/26 21:50:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	set_number(t_string *fmt)
{
	size_t	number;

	number = 0;
	while (fmt->ptr[fmt->size] >= '0' &&
		fmt->ptr[fmt->size] <= '9')
	{
		number = (number * 10) + (fmt->ptr[fmt->size] - 48);
		fmt->size++;
	}
	return (number);
}

static void		set_precision(t_printf *global, t_arg *arg)
{
	int		number;

	arg->flags.have_precision = 1;
	arg->precision = 0;
	global->fmt.size++;
	if (global->fmt.ptr[global->fmt.size] == '*')
	{
		global->fmt.size++;
		number = va_arg(global->ap, int);
		if (number < 0)
			arg->flags.have_precision = 0;
		else
			arg->precision = (size_t)number;
	}
	else
	{
		while (global->fmt.ptr[global->fmt.size] == '0')
			global->fmt.size++;
		arg->precision = set_number(&global->fmt);
	}
}

static void		set_width_or_precision(t_printf *global, t_arg *arg)
{
	int	temp;

	if (global->fmt.ptr[global->fmt.size] == '*' ||
		(global->fmt.ptr[global->fmt.size] >= '1' &&
		global->fmt.ptr[global->fmt.size] <= '9'))
	{
		arg->flags.have_width = 1;
		if (global->fmt.ptr[global->fmt.size] == '*')
		{
			global->fmt.size++;
			temp = va_arg(global->ap, int);
			if (temp < 0)
			{
				arg->flags.minus = 1;
				temp = -temp;
			}
			arg->width = (size_t)temp;
		}
		else
			arg->width = set_number(&global->fmt);
	}
	else
		set_precision(global, arg);
}

static void		set_flag(t_arg *arg, char c)
{
	if (c == ' ')
		arg->flags.space = 1;
	else if (c == '#')
		arg->flags.hash = 1;
	else if (c == '+')
		arg->flags.plus = 1;
	else if (c == '-')
		arg->flags.minus = 1;
	else if (c == '0')
		arg->flags.zero = 1;
	else if (c == 'h')
		arg->h_counter++;
	else if (c == 'l')
		arg->l_counter++;
	else if (c == 'j')
		arg->flags.j = 1;
	else
		arg->flags.z = 1;
}

void			parse_flags(t_printf *global, t_arg *arg)
{
	char		c;

	c = global->fmt.ptr[global->fmt.size];
	while (c == ' ' || c == '#' || c == '+' || c == '-' || c == '.' ||
			c == '*' || (c >= '0' && c <= '9') ||
			c == 'h' || c == 'l' || c == 'j' || c == 'z')
	{
		if (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0' ||
		c == 'h' || c == 'l' || c == 'j' || c == 'z')
		{
			set_flag(arg, c);
			global->fmt.size++;
		}
		else
			set_width_or_precision(global, arg);
		c = global->fmt.ptr[global->fmt.size];
	}
}
