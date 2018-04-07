/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:16:12 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/13 17:41:05 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	i = 0;
	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	if (!s1_cp[i] && !s2_cp[i])
		return (0);
	while ((s1_cp[i] || s2_cp[i]) && i < n)
	{
		if (s1_cp[i] == s2_cp[i])
		{
			if (s1_cp[i + 1] == '\0' && s2_cp[i + 1] == '\0')
				return (0);
		}
		else
			return (s1_cp[i] - s2_cp[i]);
		i++;
	}
	return (0);
}
