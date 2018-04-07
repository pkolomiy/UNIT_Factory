/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:52:17 by dmulish           #+#    #+#             */
/*   Updated: 2017/02/10 13:50:04 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	size_t			len_s1;
	size_t			len_s2;
	unsigned char	*fresh;

	i = 0;
	j = -1;
	if (!s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	fresh = (unsigned char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!fresh)
		return (0);
	while (i < (int)len_s1)
	{
		fresh[i] = s1[i];
		i++;
	}
	while (++j < (int)len_s2)
		fresh[i + j] = s2[j];
	fresh[i + j] = '\0';
	return ((char *)fresh);
}
