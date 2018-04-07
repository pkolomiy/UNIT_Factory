/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:23:30 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/04 17:44:16 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int				i;
	size_t			len;
	unsigned char	*fresh;

	i = -1;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	fresh = (unsigned char *)malloc(sizeof(char) * len + 1);
	if (!fresh)
		return (0);
	while (++i < (int)len)
		fresh[i] = f(s[i]);
	fresh[i] = '\0';
	return ((char *)fresh);
}
