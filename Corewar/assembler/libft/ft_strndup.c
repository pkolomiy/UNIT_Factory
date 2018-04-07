/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:54:36 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/22 17:57:32 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (NULL);
	s2 = (char*)malloc(sizeof(char) * (n + 1));
	if (s2 == NULL)
		return (0);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
