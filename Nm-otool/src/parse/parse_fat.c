/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:49:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/10 19:49:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int	check_cpus_32(t_nm_otool *prog, uint32_t nfats, bool *show_arch)
{
	t_arch		*arch;
	cpu_type_t	cputype;

	*show_arch = false;
	if (!(arch = get_mem(prog, sizeof(t_fat), sizeof(t_arch) * nfats)))
		return (EXIT_FAILURE);
	while (nfats && *show_arch == false)
	{
		cputype = swap(prog, arch->cputype);
		if (cputype != CPU_TYPE_X86_64 && cputype != CPU_TYPE_I386)
			*show_arch = true;
		arch++;
		nfats--;
	}
	if (*show_arch == true)
		prog->print_file_name = false;
	return (EXIT_SUCCESS);
}

static int	check_cpus_64(t_nm_otool *prog, uint32_t nfats, bool *show_arch)
{
	t_arch64	*arch;
	cpu_type_t	cputype;

	*show_arch = false;
	if (!(arch = get_mem(prog, sizeof(t_fat), sizeof(t_arch64) * nfats)))
		return (EXIT_FAILURE);
	while (nfats && *show_arch == false)
	{
		cputype = swap(prog, arch->cputype);
		if (cputype != CPU_TYPE_X86_64 && cputype != CPU_TYPE_I386)
			*show_arch = true;
		arch++;
		nfats--;
	}
	if (*show_arch == true)
		prog->print_file_name = false;
	return (EXIT_SUCCESS);
}

static int	parse_fat_arch32(t_nm_otool *prog, uint32_t nfats, bool show_arch)
{
	t_arch		*arch;
	cpu_type_t	cputype;
	uint16_t	subtype;

	arch = get_mem(prog, sizeof(t_fat), 0);
	while (nfats)
	{
		cputype = swap(prog, arch->cputype);
		subtype = swap(prog, arch->cpusubtype);
		if (show_arch)
			print_arch(prog, cputype, subtype);
		prog->ptr_offset = swap(prog, arch->offset);
		if (show_arch ||
		(cputype == CPU_TYPE_X86_64 && subtype == CPU_SUBTYPE_X86_64_ALL))
			if (get_mem(prog, 0, sizeof(uint32_t)) == NULL ||
			parse_object(*prog) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		arch++;
		nfats--;
	}
	return (EXIT_SUCCESS);
}

static int	parse_fat_arch64(t_nm_otool *prog, uint32_t nfats, bool show_arch)
{
	t_arch64	*arch;
	cpu_type_t	cputype;
	uint16_t	subtype;

	arch = get_mem(prog, sizeof(t_fat), 0);
	while (nfats)
	{
		cputype = swap(prog, arch->cputype);
		subtype = swap(prog, arch->cpusubtype);
		if (show_arch)
			print_arch(prog, cputype, subtype);
		prog->ptr_offset = swap(prog, arch->offset);
		if (show_arch ||
		(cputype == CPU_TYPE_X86_64 && subtype == CPU_SUBTYPE_X86_64_ALL))
			if (get_mem(prog, 0, sizeof(uint32_t)) == NULL ||
			parse_object(*prog) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		arch++;
		nfats--;
	}
	return (EXIT_SUCCESS);
}

int			parse_fat(t_nm_otool *prog)
{
	bool		show_arch;
	uint32_t	nfats;

	if (prog->program == FT_NM)
		prog->print_file_name = false;
	if (get_mem(prog, 0, sizeof(t_fat)) == NULL)
		return (EXIT_FAILURE);
	nfats = swap(prog, ((t_fat*)get_mem(prog, 0, 0))->nfat_arch);
	if (prog->is_64)
	{
		if (check_cpus_64(prog, nfats, &show_arch) == EXIT_FAILURE ||
		parse_fat_arch64(prog, nfats, show_arch) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (check_cpus_32(prog, nfats, &show_arch) == EXIT_FAILURE ||
		parse_fat_arch32(prog, nfats, show_arch) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
