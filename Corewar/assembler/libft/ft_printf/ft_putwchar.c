/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 02:31:35 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:11 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putwchar(wchar_t s)
{
	int		size;
	char	*mbs;

	size = (int)ft_wcharlen(s);
	mbs = ft_strnew(size);
	size == 4 ? (mbs[3] = 240 | (s >> 18)) : 0;
	size == 4 ? (mbs[2] = 128 | (s >> 12 & 63)) : 0;
	size == 3 ? (mbs[2] = 224 | (s >> 12)) : 0;
	size >= 3 ? (mbs[1] = 128 | (s >> 6 & 63)) : 0;
	size == 2 ? (mbs[1] = 192 | (s >> 6)) : 0;
	mbs[0] = (size == 1) ? s : 128 | (s & 63);
	mbs = ft_revstr(mbs);
	ft_putstr(mbs);
	free(mbs);
}
