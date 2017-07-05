/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:50:17 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/19 19:26:02 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	str ? (i = ft_strlen(str) + 1) : 0;
	while (str && --i != -1)
		if (((char*)str)[i] == (t_uc)c)
			return (((char*)str) + i);
	return (0);
}
