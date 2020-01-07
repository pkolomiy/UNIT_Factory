/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:35:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/10 14:35:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	*get_mem(t_nm_otool *prog, size_t offset, size_t size)
{
	if (prog->ptr_offset + offset + size > prog->ptr_size)
		return (NULL);
	return ((void*)((size_t)prog->ptr + prog->ptr_offset + offset));
}
