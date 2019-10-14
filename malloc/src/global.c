/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 03:05:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/09/15 03:05:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_global	g_malloc = {NULL, NULL, NULL};
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

t_global	*global(void)
{
	return (&g_malloc);
}
