/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:54:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/02 17:54:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_number(t_byte *str, size_t size, t_number num)
{
	while (num.len)
	{
		num.len--;
		str[size + num.len] = (t_byte)((num.val % 10) + 48);
		num.val /= 10;
	}
}

void		decimal_to_buffer(t_printf *global, t_buf *buffer, t_number num)
{
	t_byte	*joined;

	if ((size_t)num.len >= BUFFER)
	{
		joined = join_with_buffer(global, buffer, num.len);
		add_number(joined, global->ret.size + buffer->size, num);
		save_to_ret(global, buffer, (t_string){joined, num.len});
	}
	else
	{
		if (buffer->size + num.len >= BUFFER)
			flush_buffer(global, buffer);
		add_number(buffer->str, buffer->size, num);
		buffer->size += num.len;
	}
}
