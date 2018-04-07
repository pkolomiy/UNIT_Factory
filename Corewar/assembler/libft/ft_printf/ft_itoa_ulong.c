/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:47:15 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*putnum_u(char *s, unsigned long long num, int *i)
{
	if (num > 9)
	{
		putnum_u(s, num / 10, i);
		(*i)++;
	}
	s[*i] = num % 10 + '0';
	return (s);
}

char	*ft_itoa_ulong(size_t n)
{
	int					i;
	char				*res;
	unsigned long long	num;

	i = 0;
	num = n;
	if (!(res = (char *)malloc(sizeof(char) * (ft_digitnum(num) + 1))))
		return (0);
	res = putnum_u(res, num, &i);
	res[i + 1] = '\0';
	return (res);
}
