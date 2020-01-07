/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:33:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/09 14:33:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int	main(int argc, char **argv)
{
	t_nm_otool	prog;
	int			exit_code;

	prog.file_name = "a.out";
	prog.print_file_name = argc > 2;
	prog.program = FT_NM;
	if (argc < 2)
		return (parse_file(&prog));
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
