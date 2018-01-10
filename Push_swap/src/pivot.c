/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:22:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/06 19:07:21 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline void	swap(int *arr, int i, int len)
{
	int		j;

	j = i;
	while (++j < len)
	{
		if (arr[i] > arr[j])
		{
			arr[i] ^= arr[j];
			arr[j] ^= arr[i];
			arr[i] ^= arr[j];
		}
	}
}

int					find_pivot(t_stack *tmp, int len)
{
	int		i;
	int		*arr;
	int		pivot;

	arr = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		arr[i] = tmp->nbr;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < len)
	{
		swap(arr, i, len);
	}
	pivot = arr[len / 2];
	free(arr);
	return (pivot);
}
