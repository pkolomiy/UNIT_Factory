/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:01:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/09 12:59:52 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*putnum(char *s, long int n, int *i)
{
	if (n > 9)
	{
		putnum(s, n / 10, i);
		(*i)++;
	}
	s[*i] = n % 10 + '0';
	return (s);
}

char		*ft_itoa(int n)
{
	int			i;
	char		*res;
	long int	num;

	i = 0;
	num = (n < 0) ? -n : n;
	if (n < 0)
	{
		if ((res = (char *)malloc(sizeof(char) *
			ft_digitnum((unsigned long long)num) + 2)) == 0)
			return (0);
		res[i] = '-';
		i++;
	}
	else if ((res = (char *)malloc(sizeof(char) *
		ft_digitnum((unsigned long long)num) + 1)) == 0)
		return (0);
	res = putnum(res, num, &i);
	res[i + 1] = '\0';
	return (res);
}
