/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 00:36:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/15 00:36:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*before_return(t_chunk *chunk)
{
	pthread_mutex_unlock(&g_mutex);
	return ((void*)chunk + HEAD);
}
