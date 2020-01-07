/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_archive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:49:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/10 19:49:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int	parse_archive_object(t_nm_otool *prog, t_ar *ar)
{
	int		offset;
	char	*name;

	if (ft_strncmp(ar->ar_name, AR_EFMT1, sizeof(AR_EFMT1) - 2))
		return (EXIT_FAILURE);
	offset = ft_atoi(ar->ar_name + sizeof(AR_EFMT1) - 1);
	if ((name = get_mem(prog, sizeof(t_ar), (size_t)offset)) == NULL)
		return (EXIT_FAILURE);
	if (prog->program == FT_NM)
		write(1, "\n", 1);
	write(1, prog->file_name, ft_strlen(prog->file_name));
	write(1, "(", 1);
	write(1, name, ft_strlen(name));
	write(1, "):\n", 3);
	prog->ptr_offset += sizeof(t_ar) + offset;
	if (get_mem(prog, 0, sizeof(uint32_t)) == NULL ||
		parse_object(*prog) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	prog->ptr_offset += (ft_atoi(ar->ar_size) - offset);
	return (EXIT_SUCCESS);
}

int			parse_archive(t_nm_otool *prog)
{
	t_ar	*ar;

	prog->print_file_name = false;
	if (prog->program == FT_OTOOL)
	{
		write(1, "Archive : ", 10);
		write(1, prog->file_name, ft_strlen(prog->file_name));
		write(1, "\n", 1);
	}
	if ((ar = get_mem(prog, SARMAG, sizeof(t_ar))) == NULL)
		return (EXIT_FAILURE);
	prog->ptr_offset += SARMAG + sizeof(t_ar) + ft_atoi(ar->ar_size);
	while (prog->ptr_offset < prog->ptr_size)
	{
		if ((ar = get_mem(prog, 0, sizeof(t_ar))) == NULL)
			return (EXIT_FAILURE);
		if (!ft_strncmp(ar->ar_name, ARMAG, SARMAG - 1))
			return (EXIT_SUCCESS);
		if (parse_archive_object(prog, ar) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
