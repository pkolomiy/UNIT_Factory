/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:28:01 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/02 20:20:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)&big[i - j]);
	while (big[i])
	{
		if (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
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
