/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 20:17:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	copy_to_buffer(t_printf *global, t_buf *buffer)
{
	size_t		len;

	len = 0;
	while (global->fmt.ptr[global->fmt.size + len] &&
		global->fmt.ptr[global->fmt.size + len] != '%')
		len++;
	if (len >= BUFFER)
		flush_buffer_and_str(global, buffer, (t_string){global->fmt.ptr, len});
	else
	{
		if (buffer->size + len >= BUFFER)
			flush_buffer(global, buffer);
		ft_memcpy(buffer->str + buffer->size,
					global->fmt.ptr + global->fmt.size, len);
		buffer->size += len;
	}
	global->fmt.size += len;
}

void		parse_fmt(t_printf *global)
{
	t_buf	buffer;

	buffer.size = 0;
	while (global->fmt.ptr[global->fmt.size])
	{
		if (global->fmt.ptr[global->fmt.size] == '%')
		{
			global->fmt.size++;
			parse_arg(global, &buffer);
			if (global->fmt.ptr[global->fmt.size])
				global->fmt.size++;
		}
		else
			copy_to_buffer(global, &buffer);
	}
	flush_buffer(global, &buffer);
}
