/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:58:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/15 21:58:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int	validate_argc(int argc)
{
	if (argc > 1)
		return (EXIT_SUCCESS);
	write(2, "error: ft_otool: at least one file must be specified\n", 53);
	write(2, "Usage: ft_otool <object file> ...\n", 34);
	return (EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_nm_otool	prog;
	int			exit_code;

	prog.print_file_name = true;
	prog.program = FT_OTOOL;
	if (validate_argc(argc) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	exit_code = EXIT_SUCCESS;
	argv++;
	while (*argv)
	{
		prog.file_name = *argv;
		if (parse_file(&prog) == EXIT_FAILURE)
			exit_code = EXIT_FAILURE;
		argv++;
	}
	return (exit_code);
}
