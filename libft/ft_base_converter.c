/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:05:15 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/18 17:06:55 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_converter(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	else if (ft_islower(c))
		return (c - 87);
	else if (ft_isupper(c))
		return (c - 55);
	return (-1);
}
