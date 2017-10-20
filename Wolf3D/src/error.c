/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 00:04:34 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/09/29 19:44:48 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_error(char *message, char *second_message)
{
	int	len;

	len = 0;
	while (message[len])
		len++;
	write(1, message, len);
	if (second_message)
	{
		len = 0;
		while (second_message[len])
			len++;
		write(1, second_message, len);
		write(1, "\n", 1);
	}
	exit(2);
}
