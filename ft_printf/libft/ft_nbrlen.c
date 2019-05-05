/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:08:12 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/05 15:10:44 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_byte	more_ft_nbrlen(size_t nbr)
{
	if (nbr >= 10000000000 && nbr <= 99999999999)
		return (11);
	else if (nbr >= 100000000000 && nbr <= 999999999999)
		return (12);
	else if (nbr >= 1000000000000 && nbr <= 9999999999999)
		return (13);
	else if (nbr >= 10000000000000 && nbr <= 99999999999999)
		return (14);
	else if (nbr >= 100000000000000 && nbr <= 999999999999999)
		return (15);
	else if (nbr >= 1000000000000000 && nbr <= 9999999999999999)
		return (16);
	else if (nbr >= 10000000000000000 && nbr <= 99999999999999999)
		return (17);
	else if (nbr >= 100000000000000000 && nbr <= 999999999999999999)
		return (18);
	else if (nbr >= 1000000000000000000 && nbr <= 9999999999999999999U)
		return (19);
	return (20);
}

t_byte			ft_nbrlen(size_t nbr)
{
	if (nbr < 10)
		return (1);
	else if (nbr >= 10 && nbr <= 99)
		return (2);
	else if (nbr >= 100 && nbr <= 999)
		return (3);
	else if (nbr >= 1000 && nbr <= 9999)
		return (4);
	else if (nbr >= 10000 && nbr <= 99999)
		return (5);
	else if (nbr >= 100000 && nbr <= 999999)
		return (6);
	else if (nbr >= 1000000 && nbr <= 9999999)
		return (7);
	else if (nbr >= 10000000 && nbr <= 99999999)
		return (8);
	else if (nbr >= 100000000 && nbr <= 999999999)
		return (9);
	else if (nbr >= 1000000000 && nbr <= 9999999999)
		return (10);
	return (more_ft_nbrlen(nbr));
}
