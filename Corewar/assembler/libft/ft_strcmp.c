/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:22:30 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/02 21:18:58 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	i = 0;
	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	if (!s1_cp[i] && !s2_cp[i])
		return (0);
	while (s1_cp[i] || s2_cp[i])
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
