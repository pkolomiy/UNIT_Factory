/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:03:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/12 20:03:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>

void	*thread(void *unused)
{
	int		i;
	char	*addr;

	(void)unused;
	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return (NULL);
}

#define THREADS_N 16

int		main(void)
{
	pthread_t	threads[THREADS_N];
	int			i;

	i = -1;
	while (++i < THREADS_N)
		pthread_create(&threads[i], NULL, thread, NULL);
	i = -1;
	while (++i < THREADS_N)
		pthread_join(threads[i], NULL);
	return (0);
}
