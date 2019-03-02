/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_base_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:36:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/02 19:36:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursion(t_string *str, size_t num, t_byte base, _Bool uppercase)
{
	const char	*letters = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (num >= base)
		recursion(str, num / base, base, uppercase);
	str->ptr[str->size] = (t_byte)letters[num % base];
	str->size++;
}

t_string	get_itoa_base_string(t_number *num, t_byte base, _Bool uppercase)
{
	t_string	str;

	str.ptr = NULL;
	str.size = 0;
	if (num->len)
	{
		str.ptr = (t_byte*)malloc(ITOA_BUF);
		str.size = 0;
		recursion(&str, num->val, base, uppercase);
		num->len = (t_byte)str.size;
	}
	return (str);
}
