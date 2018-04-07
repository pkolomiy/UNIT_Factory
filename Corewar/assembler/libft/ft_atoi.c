/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:58:09 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/27 18:56:10 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_pos(char str, int pos, int *i)
{
	if (str == '+' && pos == 2)
	{
		(*i)++;
		return (1);
	}
	else
		return (0);
}

static int	check_neg(char str, int neg, int *i)
{
	if (str == '-' && neg == 1)
	{
		(*i)++;
		return (1);
	}
	else
		return (0);
}

static int	check_bls(char str)
{
	if (str == '\t' || str == '\n' || str == '\f'
		|| str == '\v' || str == '\r' || str == 32)
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int	num;
	int pos;
	int neg;

	i = 0;
	num = 0;
	pos = 2;
	neg = 1;
	while (check_bls(str[i]) == 1)
		i++;
	if (ft_isdigit(str[i]) == 0 && check_bls(str[i]) != 1)
	{
		if (check_neg(str[i], neg, &i) == 1)
			neg = -1;
		else if (check_pos(str[i], pos, &i) == 1)
			pos = -2;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}
