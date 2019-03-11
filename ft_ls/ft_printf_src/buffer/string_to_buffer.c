/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:12:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/02 19:12:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_to_buffer(t_printf *global, t_buf *buffer, t_string str)
{
	if (str.size >= BUFFER)
		flush_buffer_and_str(global, buffer, str);
	else
	{
		if (buffer->size + str.size >= BUFFER)
			flush_buffer(global, buffer);
		ft_memcpy(buffer->str + buffer->size, str.ptr, str.size);
		buffer->size += str.size;
	}
}
