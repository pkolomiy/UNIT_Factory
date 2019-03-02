/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:42:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 21:42:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_byte	*join_with_buffer(t_printf *global, t_buf *buffer, size_t size)
{
	t_byte	*joined;

	joined = (t_byte *)malloc(global->ret.size + buffer->size + size);
	if (global->ret.size)
		ft_memcpy(joined, global->ret.ptr, global->ret.size);
	if (buffer->size)
		ft_memcpy(joined + global->ret.size, buffer->str, buffer->size);
	return (joined);
}

void	save_to_ret(t_printf *global, t_buf *buffer, t_string joined)
{
	ft_memdel((void**)&global->ret.ptr);
	global->ret.ptr = joined.ptr;
	global->ret.size += (buffer->size + joined.size);
	buffer->size = 0;
}

void	flush_buffer_and_str(t_printf *global, t_buf *buffer, t_string str)
{
	t_byte	*joined;

	joined = join_with_buffer(global, buffer, str.size);
	ft_memcpy(joined + global->ret.size + buffer->size, str.ptr, str.size);
	save_to_ret(global, buffer, (t_string){joined, str.size});
}

void	flush_buffer(t_printf *global, t_buf *buffer)
{
	t_byte	*joined;

	if (buffer->size)
	{
		joined = join_with_buffer(global, buffer, 0);
		save_to_ret(global, buffer, (t_string){joined, 0});
	}
}
