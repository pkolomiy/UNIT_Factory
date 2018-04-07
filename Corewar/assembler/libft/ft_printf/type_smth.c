/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_smth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 11:19:04 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:44:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		type_spaces_smth(t_mod *mod, int sign, t_s *s)
{
	int	i;

	i = -1;
	if (!(ft_strchr(mod->flags, '0')))
	{
		while (++i < (mod->width - sign - 1))
			s->return_val += write(1, " ", 1);
	}
	else if ((ft_strchr(mod->flags, '0') && ft_strchr(mod->flags, '.')))
	{
		s->spaces_d = mod->width - sign - 1;
		while (++i < s->spaces_d)
			s->return_val += (ft_strchr(mod->flags, '0')) ? write(1, "0", 1) :
				write(1, " ", 1);
	}
	else if (ft_strchr(mod->flags, '.'))
	{
		if (mod->width && !mod->prec)
			s->return_val += (ft_strchr(mod->flags, '0')) ? write(1, "0", 1) :
				write(1, " ", 1);
	}
}

void		type_smth(t_mod *mod, t_s *s)
{
	int	sign;

	sign = (ft_strchr(mod->flags, '+') || ft_strchr(mod->flags, ' ')) ? 1 : 0;
	if (ft_strchr(mod->flags, '-'))
	{
		ft_putchar(mod->type);
		type_spaces_smth(mod, sign, s);
	}
	else
	{
		type_spaces_smth(mod, sign, s);
		ft_putchar(mod->type);
	}
	s->return_val += (mod->type) ? 1 : 0;
}
