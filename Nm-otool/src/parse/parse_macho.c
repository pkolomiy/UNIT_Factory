/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_macho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:41:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/12 21:41:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int	add_symbols_32(t_nm_otool *prog, t_nlst *nlst, uint32_t stroff)
{
	uint32_t	i;

	i = 0;
	while (i < prog->nsyms)
	{
		prog->syms[i].value = swap(prog, nlst->n_value);
		if ((prog->syms[i].str = get_mem(prog,
				stroff + swap(prog, nlst->n_un.n_strx), 0)) == NULL)
			return (EXIT_FAILURE);
		prog->syms[i].type = nlst->n_type;
		prog->syms[i].sect = nlst->n_sect;
		nlst++;
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	parse_symbols_32(t_nm_otool *prog, size_t offset)
{
	t_symcmd	*st;
	t_nlst		*nlst;

	if ((st = get_mem(prog, offset, sizeof(t_symcmd))) == NULL)
		return (EXIT_FAILURE);
	prog->nsyms = swap(prog, st->nsyms);
	if ((nlst = get_mem(prog, swap(prog, st->symoff),
						sizeof(t_nlst) * prog->nsyms)) == NULL ||
		get_mem(prog, swap(prog, st->stroff),
			(size_t)swap(prog, st->strsize)) == NULL)
		return (EXIT_FAILURE);
	prog->syms = (t_symbol*)malloc(sizeof(t_symbol) * prog->nsyms);
	if (prog->syms == NULL)
		return (print_error(prog, E_MALLOC));
	if (add_symbols_32(prog, nlst, swap(prog, st->stroff)) == EXIT_FAILURE)
	{
		free(prog->syms);
		return (EXIT_FAILURE);
	}
	sort_symbols(prog);
	print_symbols(prog);
	free(prog->syms);
	return (EXIT_SUCCESS);
}

static int	add_symbols_64(t_nm_otool *prog, t_nlst64 *nlst, uint32_t stroff)
{
	uint32_t	i;

	i = 0;
	while (i < prog->nsyms)
	{
		prog->syms[i].value = nlst->n_value;
		if (prog->swap)
			prog->syms[i].value = SWAP_64(nlst->n_value);
		if ((prog->syms[i].str = get_mem(prog,
				stroff + swap(prog, nlst->n_un.n_strx), 0)) == NULL)
			return (EXIT_FAILURE);
		prog->syms[i].type = nlst->n_type;
		prog->syms[i].sect = nlst->n_sect;
		nlst++;
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	parse_symbols_64(t_nm_otool *prog, size_t offset)
{
	t_symcmd	*st;
	t_nlst64	*nlst;

	if ((st = get_mem(prog, offset, sizeof(t_symcmd))) == NULL)
		return (EXIT_FAILURE);
	prog->nsyms = swap(prog, st->nsyms);
	if ((nlst = get_mem(prog, swap(prog, st->symoff),
						sizeof(t_nlst64) * prog->nsyms)) == NULL ||
		get_mem(prog, swap(prog, st->stroff),
				(size_t)swap(prog, st->strsize)) == NULL)
		return (EXIT_FAILURE);
	prog->syms = (t_symbol*)malloc(sizeof(t_symbol) * prog->nsyms);
	if (prog->syms == NULL)
		return (print_error(prog, E_MALLOC));
	if (add_symbols_64(prog, nlst, swap(prog, st->stroff)) == EXIT_FAILURE)
	{
		free(prog->syms);
		return (EXIT_FAILURE);
	}
	sort_symbols(prog);
	print_symbols(prog);
	free(prog->syms);
	return (EXIT_SUCCESS);
}

int			parse_macho(t_nm_otool *prog)
{
	if (prog->is_64)
	{
		if (get_mem(prog, 0, sizeof(t_mh64)) == NULL ||
		parse_load_cmd_64(prog, LC_SEGMENT_64, &parse_segment_64))
			return (EXIT_FAILURE);
		if (prog->program == FT_NM)
			return (parse_load_cmd_64(prog, LC_SYMTAB, &parse_symbols_64));
	}
	else
	{
		if (get_mem(prog, 0, sizeof(t_mh)) == NULL ||
		parse_load_cmd_32(prog, LC_SEGMENT, &parse_segment_32))
			return (EXIT_FAILURE);
		if (prog->program == FT_NM)
			return (parse_load_cmd_32(prog, LC_SYMTAB, &parse_symbols_32));
	}
	return (print_otool(prog));
}
