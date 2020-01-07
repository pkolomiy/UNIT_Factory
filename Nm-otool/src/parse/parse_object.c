/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:00:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/10 20:00:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static void	reset_prog(t_nm_otool *prog)
{
	prog->swap = false;
	prog->is_64 = false;
	prog->nsyms = 0;
	prog->syms = NULL;
	prog->sect = (t_sections){0, 0, 0, 0};
	prog->text_sect = (t__text){NULL, 0, 0, 0};
}

int			parse_object(t_nm_otool prog)
{
	const uint32_t	magic = *(uint32_t*)get_mem(&prog, 0, 0);
	const uint32_t	ar_magic = *(uint32_t*)ARMAG;

	reset_prog(&prog);
	if (magic == FAT_CIGAM || magic == FAT_CIGAM_64 || magic == MH_CIGAM ||
		magic == MH_CIGAM_64 || magic == SWAP_32(ar_magic))
		prog.swap = true;
	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64 ||
		magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		prog.is_64 = true;
	if (magic == ar_magic || magic == SWAP_32(ar_magic))
		return (parse_archive(&prog));
	else if (magic == MH_MAGIC || magic == MH_CIGAM ||
			magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (parse_macho(&prog));
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM ||
			magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		return (parse_fat(&prog));
	return (EXIT_FAILURE);
}
