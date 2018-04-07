/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:23:25 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

unsigned char		*ft_strcp(unsigned char *dst, const unsigned char *src)
{
	int				i;

	i = 0;
	while (i < COM_NAME)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i++] = '\0';
	return (dst);
}

unsigned char		*create_line(unsigned char *ret, int *size)
{
	unsigned char *ret_end;

	ret_end = malloc(COM_NAME + *size + 1);
	ft_strcp(ret_end, ret);
	free(ret);
	return (ret_end);
}
