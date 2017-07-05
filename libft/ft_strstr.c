/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:19:12 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/19 19:25:50 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;

	if (big && little)
	{
		if (!*little)
			return ((char*)big);
		i = -1;
		while (((char*)big)[++i])
			if (ft_strnequ((char*)big + i, little, ft_strlen(little)))
				return ((char*)big + i);
	}
	return (0);
}
