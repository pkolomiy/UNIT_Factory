/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/12 20:17:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static char	get_type(t_sections sections, t_symbol symbol)
{
	char			chr;
	const uint8_t	type = (symbol.type & N_TYPE);

	if ((type != N_ABS && type != N_SECT && type != N_INDR && type != N_UNDF) ||
		symbol.type & N_STAB)
		return (0);
	if (type == N_INDR)
		chr = 'i';
	else if (type == N_UNDF && symbol.value)
		chr = 'c';
	else if (type == N_ABS)
		chr = 'a';
	else if (type == N_SECT && symbol.sect == sections.text)
		chr = 't';
	else if (type == N_SECT && symbol.sect == sections.data)
		chr = 'd';
	else if (type == N_SECT && symbol.sect == sections.bss)
		chr = 'b';
	else if (type == N_UNDF)
		chr = 'u';
	else
		chr = 's';
	if (symbol.type & N_EXT && chr > 96 && chr < 123)
		chr -= 32;
	return (chr);
}

static void	print_symbol(t_symbol symbol, char type, bool is_64)
{
	if (type == 'U')
		write(1, "                ", is_64 ? 16 : 8);
	else
		print_hex(symbol.value, is_64 ? 16 : 8);
	write(1, " ", 1);
	write(1, &type, 1);
	write(1, " ", 1);
	write(1, symbol.str, ft_strlen(symbol.str));
	write(1, "\n", 1);
}

void		print_symbols(t_nm_otool *prog)
{
	char		type;
	uint32_t	i;

	if (prog->print_file_name)
	{
		if (prog->program == FT_NM)
			write(1, "\n", 1);
		write(1, prog->file_name, ft_strlen(prog->file_name));
		write(1, ":\n", 2);
	}
	i = 0;
	while (i < prog->nsyms)
	{
		type = get_type(prog->sect, prog->syms[i]);
		if (prog->syms[i].str[0] && type)
			print_symbol(prog->syms[i], type, prog->is_64);
		i++;
	}
}
