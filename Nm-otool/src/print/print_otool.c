/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_otool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:51:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/15 21:51:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static void	print_group(t_nm_otool *prog, t__text *sect, uint32_t i, bool group)
{
	uint32_t	j;
	uint32_t	temp;

	j = 0;
	while (j < 16 && (int)(sect->size - i - j) > 0)
	{
		if (group)
		{
			temp = *((uint32_t*)(sect->mem + i + j));
			print_hex(swap(prog, temp), 8);
		}
		else
			print_hex(sect->mem[i + j], 2);
		j += (group ? 4 : 1);
		write(1, " ", 1);
	}
}

static void	print_section(t_nm_otool *prog, t__text *sect)
{
	uint32_t	i;
	bool		group;

	i = 0;
	group = sect->cputype != CPU_TYPE_X86_64 && sect->cputype != CPU_TYPE_I386;
	while (i < sect->size)
	{
		print_hex(sect->addr + i, prog->is_64 ? 16 : 8);
		write(1, "\t", 1);
		print_group(prog, sect, i, group);
		write(1, "\n", 1);
		i += 16;
	}
}

int			print_otool(t_nm_otool *prog)
{
	if (prog->print_file_name)
	{
		if (prog->program == FT_NM)
			write(1, "\n", 1);
		write(1, prog->file_name, ft_strlen(prog->file_name));
		write(1, ":\n", 2);
	}
	write(1, "Contents of (__TEXT,__text) section\n", 36);
	print_section(prog, &prog->text_sect);
	return (EXIT_SUCCESS);
}
