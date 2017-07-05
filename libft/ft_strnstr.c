/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:47:06 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/20 00:44:01 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (big && little)
	{
		if (!*little)
			return ((char*)big);
		i = -1;
		while (((char*)big)[++i] && (len - i))
			if (ft_strnequ((char*)big + i, little, ft_strlen(little)))
				if (ft_strlen(little) + i <= len)
					return ((char*)big + i);
	}
	return (0);
}
