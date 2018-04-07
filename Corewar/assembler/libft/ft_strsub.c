/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:38:25 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/11 15:27:10 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned char	*fresh;

	i = 0;
	fresh = (unsigned char *)malloc(sizeof(char) * len + 1);
	if (!fresh)
		return (0);
	while (s && i <= len)
	{
		if (i == len)
		{
			fresh[i] = '\0';
			return ((char *)fresh);
		}
		fresh[i] = s[start + i];
		i++;
	}
	return (0);
}
