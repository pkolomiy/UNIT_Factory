/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 13:07:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(size_t nbr)
{
	size_t	len;

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
	len = 9;
	while (nbr >= 1000000000)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
