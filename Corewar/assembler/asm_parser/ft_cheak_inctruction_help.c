/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheak_inctruction_help.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:05:31 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

int			ft_islable(char c)
{
	char	*z;
	int		i;

	i = 0;
	z = LABEL_CHARS;
	while (z[i] != '\0')
	{
		if (z[i] == c || z[i] == DIRECT_CHAR || z[i] == ':')
			return (1);
		i++;
	}
	return (0);
}

int			ft_isdigit_minus(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

int			ft_reg_command(int num_of_static_val, int count)
{
	if ((g_op_tab[num_of_static_val].arg[count] % 2) == 1)
		return (1);
	else
		return (0);
}

int			ft_dir_command(int num_of_static_val, int count)
{
	if (g_op_tab[num_of_static_val].arg[count] == 2 ||
		g_op_tab[num_of_static_val].arg[count] == 3 ||
		g_op_tab[num_of_static_val].arg[count] == 7 ||
		g_op_tab[num_of_static_val].arg[count] == 6)
		return (1);
	else
		return (0);
}

int			ft_ind_command(int num_of_static_val, int count)
{
	if (g_op_tab[num_of_static_val].arg[count] >= 4)
		return (1);
	else
		return (0);
}
