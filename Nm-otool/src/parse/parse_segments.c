/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_segments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:06:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/12 21:06:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int	fill_text_sect(t_nm_otool *prog, uint64_t addr,
											uint32_t offset, uint32_t size)
{
	if (prog->is_64 && prog->swap)
		addr = SWAP_64(addr);
	else if (!prog->is_64)
		addr = swap(prog, (uint32_t)addr);
	size = swap(prog, size);
	offset = swap(prog, offset);
	if ((prog->text_sect.mem = get_mem(prog, offset, (size_t)size)) == NULL)
		return (EXIT_FAILURE);
	prog->text_sect.size = size;
	prog->text_sect.addr = addr;
	return (EXIT_SUCCESS);
}

static int	parse_section_32(t_nm_otool *prog, t_sec *sect)
{
	prog->sect.iterator++;
	if (!ft_strcmp(sect->segname, SEG_TEXT) &&
	!ft_strcmp(sect->sectname, SECT_TEXT))
		prog->sect.text = prog->sect.iterator;
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
	!ft_strcmp(sect->sectname, SECT_DATA))
		prog->sect.data = prog->sect.iterator;
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
	!ft_strcmp(sect->sectname, SECT_BSS))
		prog->sect.bss = prog->sect.iterator;
	if (prog->sect.iterator == prog->sect.text)
		return (fill_text_sect(prog, sect->addr, sect->offset, sect->size));
	return (EXIT_SUCCESS);
}

int			parse_segment_32(t_nm_otool *prog, size_t offset)
{
	t_sec		*sect;
	uint32_t	nsects;

	if (get_mem(prog, offset, sizeof(t_segcmd)) == NULL)
		return (EXIT_FAILURE);
	nsects = swap(prog, ((t_segcmd*)get_mem(prog, offset, 0))->nsects);
	offset += sizeof(t_segcmd);
	if ((sect = get_mem(prog, offset, sizeof(t_sec) * nsects)) == NULL)
		return (EXIT_FAILURE);
	while (nsects)
	{
		if (parse_section_32(prog, sect) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		sect++;
		nsects--;
	}
	return (EXIT_SUCCESS);
}

static int	parse_section_64(t_nm_otool *prog, t_sec64 *sect)
{
	prog->sect.iterator++;
	if (!ft_strcmp(sect->segname, SEG_TEXT) &&
	!ft_strcmp(sect->sectname, SECT_TEXT))
		prog->sect.text = prog->sect.iterator;
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
	!ft_strcmp(sect->sectname, SECT_DATA))
		prog->sect.data = prog->sect.iterator;
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
	!ft_strcmp(sect->sectname, SECT_BSS))
		prog->sect.bss = prog->sect.iterator;
	if (prog->sect.iterator == prog->sect.text)
		return (fill_text_sect(prog, sect->addr, sect->offset, sect->size));
	return (EXIT_SUCCESS);
}

int			parse_segment_64(t_nm_otool *prog, size_t offset)
{
	t_sec64		*sect;
	uint32_t	nsects;

	if (get_mem(prog, offset, sizeof(t_segcmd64)) == NULL)
		return (EXIT_FAILURE);
	nsects = swap(prog, ((t_segcmd64*)get_mem(prog, offset, 0))->nsects);
	offset += sizeof(t_segcmd64);
	if ((sect = get_mem(prog, offset, sizeof(t_sec64) * nsects)) == NULL)
		return (EXIT_FAILURE);
	while (nsects)
	{
		if (parse_section_64(prog, sect) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		sect++;
		nsects--;
	}
	return (EXIT_SUCCESS);
}
