/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:02:44 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/13 16:10:34 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (lit[j] == '\0')
		return ((char *)&big[i - j]);
	while (big[i] && i < len)
	{
		if (big[i] == lit[j])
		{
			if (lit[j + 1] == '\0')
				return ((char *)&big[i - j]);
			j++;
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}
