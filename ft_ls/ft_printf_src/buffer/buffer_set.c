/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:12:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/01 22:12:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_set(t_printf *global, t_buf *buffer, t_byte c, size_t size)
{
	t_byte		*joined;

	if (size >= BUFFER)
	{
		joined = join_with_buffer(global, buffer, size);
		ft_memset(joined + global->ret.size + buffer->size, c, size);
		save_to_ret(global, buffer, (t_string){joined, size});
	}
	else
	{
		if (buffer->size + size >= BUFFER)
			flush_buffer(global, buffer);
		ft_memset(buffer->str + buffer->size, c, size);
		buffer->size += size;
	}
}
