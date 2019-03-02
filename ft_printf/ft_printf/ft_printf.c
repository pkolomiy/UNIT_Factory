/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:34:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 15:34:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_asprintf(char **ret, char *fmt, ...)
{
	t_printf	global;

	ft_bzero((void*)&global, sizeof(t_printf));
	va_start(global.ap, fmt);
	global.fmt.ptr = (t_byte*)fmt;
	parse_fmt(&global);
	va_end(global.ap);
	*ret = (char*)global.ret.ptr;
	return ((int)global.ret.size);
}

int	ft_dprintf(int fd, char *fmt, ...)
{
	t_printf	global;

	ft_bzero((void*)&global, sizeof(t_printf));
	va_start(global.ap, fmt);
	global.fmt.ptr = (t_byte*)fmt;
	parse_fmt(&global);
	va_end(global.ap);
	if (global.ret.size)
	{
		write(fd, global.ret.ptr, global.ret.size);
		ft_memdel((void **)&global.ret.ptr);
	}
	return ((int)global.ret.size);
}

int	ft_printf(char *fmt, ...)
{
	t_printf	global;

	ft_bzero((void*)&global, sizeof(t_printf));
	va_start(global.ap, fmt);
	global.fmt.ptr = (t_byte*)fmt;
	parse_fmt(&global);
	va_end(global.ap);
	if (global.ret.size)
	{
		write(1, global.ret.ptr, global.ret.size);
		ft_memdel((void **)&global.ret.ptr);
	}
	return ((int)global.ret.size);
}
