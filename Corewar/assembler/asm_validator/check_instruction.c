/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:32:03 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/27 18:53:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_char(char *str, int *res, char c)
{
	int	i;
	int	n;
	int	len;

	n = 0;
	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (str[i] == c)
		{
			n++;
			(*res)++;
		}
	}
	return (n);
}

int		check_instruction(char *arg, char **error, int j)
{
	int	i;
	int	yep;

	i = -1;
	yep = -1;
	while (++i < 16)
	{
		if (ft_strstr(arg, g_op_tab[i].name))
			yep = i;
	}
	if (yep == -1 || (ft_strlen(arg) != ft_strlen(g_op_tab[yep].name)))
		(!(*error)) ? *error = error_message(j, 'i') : 0;
	return (yep);
}
