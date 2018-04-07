/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_of_valid_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:40:55 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

int			ft_comment(char *j)
{
	int		count;

	count = 0;
	while (j[count] != '\0')
	{
		if (ft_isalpha(j[count]) || ft_isdigit(j[count]))
			return (0);
		else if (j[count] == COMMENT_CHAR)
			return (1);
		count++;
	}
	return (0);
}

int			ft_empty_line(char *name, int f)
{
	if (f < 0)
		f = 0;
	while (name[f] != '\0')
	{
		if (ft_isalpha(name[f]) || ft_isdigit(name[f]))
			return (1);
		f++;
	}
	return (0);
}
