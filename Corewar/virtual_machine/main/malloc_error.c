/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:27:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/02/19 21:06:05 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		malloc_error(const char *str)
{
	write(2, "malloc_error\n", 13);
	write(2, str, string_len(str));
	write(2, "\n", 1);
	return (1);
}
