/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/13 17:46:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		nbr;
	_Bool	minus;

	nbr = 0;
	while ((*str >= 8 && *str <= 14) || *str == 32)
		str++;
	if ((minus = *str == '-'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	if (minus)
		return (-nbr);
	return (nbr);
}
