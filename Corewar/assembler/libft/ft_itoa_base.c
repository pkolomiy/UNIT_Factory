/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:16:14 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/10 13:30:18 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aux(intmax_t num, int b, char *res, int *i)
{
	char	*base;

	base = ft_strdup("0123456789abcdef");
	if (num <= -b || b <= num)
		aux(num / b, b, res, i);
	res[(*i)++] = base[ABS(num % b)];
	free(base);
}

char	*ft_itoa_base(intmax_t num, int base, int letter_size)
{
	int		i;
	char	*res;

	i = 0;
	if (base < 2 || base > 16 || !(res = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	if (base == 10 && num < 0)
		res[i++] = '-';
	else if (base != 10 && num < 0)
		(num > -4294967296) ? num += 4294967296 : 0;
	aux(num, base, res, &i);
	res[i] = '\0';
	i = -1;
	if (letter_size == 'b')
	{
		while (res[++i])
			res[i] = ft_toupper(res[i]);
	}
	return (res);
}
