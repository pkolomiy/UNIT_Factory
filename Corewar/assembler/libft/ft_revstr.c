/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 00:36:50 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/26 18:04:55 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = ft_strnew(ft_strlen(str));
	j = (int)ft_strlen(str) - 1;
	while (j >= 0)
	{
		res[i] = str[j];
		i++;
		j--;
	}
	return (res);
}
