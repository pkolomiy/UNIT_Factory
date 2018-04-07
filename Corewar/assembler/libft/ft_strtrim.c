/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:44:45 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/13 19:30:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
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
	if ((s_cp = (unsigned char *)malloc(sizeof(char) * len + 1)) == 0)
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0') && s)
		i++;
	while ((s[len - j] == ' ' || s[len - j] == '\n' || s[len - j] == '\t') && s)
		j++;
	if (i == j || ft_strlen(s) == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, (size_t)(len - i - j + 1)));
}
