/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:28:41 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:28 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_flags(t_mod *mod, t_s *s)
{
	if (mod->type == 'd' || mod->type == 'i')
		type_d(mod, s);
	else if (mod->type == 'D')
		type_big_d(mod, s);
	else if (mod->type == 'u' || mod->type == 'U')
		type_u(mod, s);
	else if (mod->type == 'o' || mod->type == 'O')
		type_o(mod, s);
	else if (mod->type == 'x' || mod->type == 'X')
		type_x(mod, s);
	else if (mod->type == 's')
		type_s(mod, s);
	else if (mod->type == 'S')
		type_big_s(mod, s);
	else if (mod->type == 'c' || mod->type == 'C')
		type_c(mod, s);
	else if (mod->type == 'p')
		type_p(mod, s);
	else
		type_smth(mod, s);
}
