/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:08:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/12 18:08:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	sort_symbols(t_nm_otool *prog)
{
	int			diff;
	uint32_t	i;
	uint32_t	j;
	t_symbol	tmp;

	i = 0;
	while (i < prog->nsyms - 1)
	{
		j = i + 1;
		while (j < prog->nsyms)
		{
			diff = ft_strcmp(prog->syms[i].str, prog->syms[j].str);
			if (diff > 0 ||
				(diff == 0 && prog->syms[i].value > prog->syms[j].value))
			{
				tmp = prog->syms[i];
				prog->syms[i] = prog->syms[j];
				prog->syms[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
