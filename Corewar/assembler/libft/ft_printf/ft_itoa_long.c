/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:44:46 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:42:59 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*putnum(char *s, unsigned long long num, int *i)
{
	if (num > 9)
	{
		putnum(s, num / 10, i);
		(*i)++;
	}
	s[*i] = num % 10 + '0';
	return (s);
}

char	*ft_itoa_long(long long n)
{
	int					i;
	char				*res;
	unsigned long long	num;

	i = 0;
	num = (n < 0) ? -n : n;
	if (n < 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_digitnum(num) + 2))))
			return (0);
		res[i] = '-';
		i++;
	}
	else if (!(res = (char *)malloc(sizeof(char) * (ft_digitnum(num) + 1))))
		return (0);
	res = putnum(res, num, &i);
	res[i + 1] = '\0';
	return (res);
}
