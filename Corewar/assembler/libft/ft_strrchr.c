/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:36:26 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/13 19:21:10 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*s1;

	len = (int)ft_strlen((char*)s);
	s1 = (unsigned char*)s;
	while (len >= 0 || c == '\0')
	{
		if (s1[len--] == c)
			return ((char *)&s1[len + 1]);
	}
	return (0);
}
