/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 01:28:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/14 01:28:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	print_arch(t_nm_otool *prog, cpu_type_t cputype, cpu_subtype_t subtype)
{
	int	i;

	if (prog->program == FT_NM)
		write(1, "\n", 1);
	write(1, prog->file_name, ft_strlen(prog->file_name));
	if (prog->program == FT_NM)
		write(1, " (for architecture ", 19);
	i = -1;
	while (g_arch[++i].name)
		if (g_arch[i].cputype == cputype && g_arch[i].cpusubtype == subtype)
			break ;
	if (g_arch[i].name && prog->program == FT_OTOOL)
		write(1, " (architecture ", 15);
	if (g_arch[i].name)
		write(1, g_arch[i].name, ft_strlen(g_arch[i].name));
	if (g_arch[i].name || prog->program == FT_NM)
		write(1, "):\n", 3);
	if (g_arch[i].name == NULL && prog->program == FT_OTOOL)
		write(1, ":\n", 2);
}
