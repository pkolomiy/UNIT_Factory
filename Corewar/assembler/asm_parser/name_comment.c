/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:26:48 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:24:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

t_file				*name_comment(t_file *cop, unsigned char *ret, int f)
{
	int l;

	l = 4;
	ret[1] = 0xea;
	ret[2] = 0x83;
	ret[3] = 0xf3;
	while (cop->line[f] != LINE)
		(f)++;
	(f)++;
	while (cop->line[f] != LINE)
	{
		if (cop->line[f] == '\0')
		{
			f = 0;
			cop = cop->next;
			ret[l++] = '\n';
		}
		else
			ret[l++] = cop->line[f++];
	}
	return (cop);
}

t_file				*ft_search_comment(t_file *cop, unsigned char *ret)
{
	int				f;
	int				l;

	f = 0;
	while (cop->line[f] != LINE)
		f++;
	f++;
	l = 140;
	while (cop->line[f] != LINE)
	{
		if (cop->line[f] == '\0')
		{
			cop = cop->next;
			f = 0;
			ret[l++] = '\n';
		}
		else
			ret[l++] = cop->line[f++];
	}
	f++;
	return (cop);
}
