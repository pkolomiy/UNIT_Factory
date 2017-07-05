/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:45:41 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/19 19:26:36 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str && ((char*)str)[++i])
		if (((char*)str)[i] == (t_uc)c)
			return (((char*)str) + i);
	if (str && !((char*)str)[i] && !(t_uc)c)
		return (&((char*)str)[i]);
	return (0);
}
