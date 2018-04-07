/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:30:25 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/07 14:20:02 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim_any(char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t			len;
	unsigned char	*s_cp;

	i = 0;
	j = 1;
	if (!s)
		return (0);
	len = ft_strlen(s);
	s_cp = (unsigned char *)malloc(sizeof(char) * len + 1);
	if (!s_cp)
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == c
				|| s[i] == '\0') && s)
		i++;
	while ((s[len - j] == ' ' || s[len - j] == '\n' || s[len - j] == '\t'
				|| s[len - j] == c) && s)
		j++;
	if (i == j)
		return (ft_strdup(""));
	return (ft_strsub(s, i, (size_t)(len - i - j + 1)));
}
