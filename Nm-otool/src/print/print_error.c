/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:54:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/10 11:54:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int	print_error(t_nm_otool *prog, char *error_msg)
{
	if (prog->program == FT_NM)
		write(2, "ft_nm: ", 7);
	if (prog->program == FT_OTOOL)
		write(2, "ft_otool: ", 10);
	write(2, prog->file_name, ft_strlen(prog->file_name));
	write(2, ": ", 2);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	if (prog->program == FT_NM)
		write(2, "\n", 1);
	return (EXIT_FAILURE);
}
