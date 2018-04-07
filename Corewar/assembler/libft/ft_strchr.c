/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:25:14 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/23 13:25:45 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = (char*)s;
	if (ft_strlen(s1) == 0)
		return (NULL);
	while (s1[++i])
	{
		if (s1[i] == c || c == '\0')
			return (&s1[i]);
	}
	return (NULL);
}
