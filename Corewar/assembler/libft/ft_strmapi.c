/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:36:07 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/04 17:47:55 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	unsigned char	*fresh;

	i = 0;
	if (!s || !f)
		return (0);
	len = (unsigned int)ft_strlen(s);
	fresh = (unsigned char *)malloc(sizeof(char) * len + 1);
	if (!fresh)
		return (0);
	while (i < len)
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return ((char *)fresh);
}
