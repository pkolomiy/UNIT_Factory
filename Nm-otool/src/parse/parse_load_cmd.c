/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_load_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:15:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/12 21:15:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int	parse_load_cmd_32(t_nm_otool *prog, uint32_t lc_type,
										int (*parse_func)(t_nm_otool*, size_t))
{
	t_lc		*lc;
	uint32_t	ncmds;
	size_t		offset;
	t_mh		*header;

	header = get_mem(prog, 0, 0);
	ncmds = swap(prog, header->ncmds);
	prog->text_sect.cputype = swap(prog, header->cputype);
	offset = sizeof(t_mh);
	while (ncmds)
	{
		if (!(lc = get_mem(prog, offset, sizeof(t_lc))) ||
			swap(prog, lc->cmdsize) % 4 ||
			(swap(prog, lc->cmd) == lc_type && parse_func(prog, offset)))
			return (EXIT_FAILURE);
		offset += swap(prog, lc->cmdsize);
		ncmds--;
	}
	return (EXIT_SUCCESS);
}

int	parse_load_cmd_64(t_nm_otool *prog, uint32_t lc_type,
										int (*parse_func)(t_nm_otool*, size_t))
{
	t_lc		*lc;
	uint32_t	ncmds;
	size_t		offset;
	t_mh64		*header;

	header = get_mem(prog, 0, 0);
	ncmds = swap(prog, header->ncmds);
	prog->text_sect.cputype = swap(prog, header->cputype);
	offset = sizeof(t_mh64);
	while (ncmds)
	{
		if (!(lc = get_mem(prog, offset, sizeof(t_lc))) ||
			swap(prog, lc->cmdsize) % 8 ||
			(swap(prog, lc->cmd) == lc_type && parse_func(prog, offset)))
			return (EXIT_FAILURE);
		offset += swap(prog, lc->cmdsize);
		ncmds--;
	}
	return (EXIT_SUCCESS);
}
