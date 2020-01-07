/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:00:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/15 22:00:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int	read_file(t_nm_otool *prog)
{
	int			fd;
	struct stat	buf;

	fd = open(prog->file_name, O_RDONLY);
	if (fd == -1)
		return (print_error(prog, E_NO_FILE));
	if (fstat(fd, &buf) < 0)
		return (print_error(prog, E_PERMISSION));
	if (S_ISDIR(buf.st_mode))
		return (print_error(prog, E_IS_DIR));
	prog->ptr_size = (size_t)buf.st_size;
	prog->ptr = mmap(0, prog->ptr_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (prog->ptr == MAP_FAILED)
		return (print_error(prog, E_MMAP));
	if (close(fd) < 0)
		return (print_error(prog, E_CLOSE));
	return (EXIT_SUCCESS);
}

int			parse_file(t_nm_otool *prog)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (read_file(prog) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	prog->ptr_offset = 0;
	if (get_mem(prog, 0, sizeof(uint32_t)) == NULL ||
	parse_object(*prog) == EXIT_FAILURE)
		exit_code = print_error(prog, E_INVALID_OBJ);
	if (munmap(prog->ptr, prog->ptr_size) < 0)
		return (print_error(prog, E_MUNMAP));
	return (exit_code);
}
