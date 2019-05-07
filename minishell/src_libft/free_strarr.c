/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/05 20:30:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strarr(t_strarr *arr)
{
	size_t	i;

	i = 0;
	while (i < arr->len)
	{
		ft_memdel((void**)&arr->ptr[i]);
		i++;
	}
	ft_memdel((void**)&arr->ptr);
	arr->len = 0;
}
