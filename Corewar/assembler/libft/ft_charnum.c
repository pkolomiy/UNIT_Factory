/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:46:49 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/18 16:50:24 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charnum(char *str, char c)
{
	int		i;
	size_t	res;

	i = -1;
	res = 0;
	if (!ft_strlen(str))
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
			res++;
	}
	return (res);
}
