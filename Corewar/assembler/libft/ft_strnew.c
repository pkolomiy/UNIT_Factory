/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:11:18 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/01 20:38:25 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*fresh;

	i = -1;
	fresh = (char*)malloc(sizeof(char) * size + 1);
	if (!fresh)
		return (0);
	while (++i < size)
		fresh[i] = '\0';
	fresh[i] = '\0';
	*fresh = 0;
	return (fresh);
}
