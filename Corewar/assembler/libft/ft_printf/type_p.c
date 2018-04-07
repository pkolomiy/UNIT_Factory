/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 12:18:05 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:55 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		type_spaces_p(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	len;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	len = (num_len >= mod->prec) ? num_len : mod->prec;
	if (!(ft_strchr(mod->flags, '0')))
	{
		while (++i < (mod->width - len - sign))
			s->return_val += write(1, " ", 1);
	}
	else if ((ft_strchr(mod->flags, '0') && ft_strchr(mod->flags, '.')))
	{
		s->spaces_d = mod->width - len - sign;
		while (++i < s->spaces_d)
			s->return_val += write(1, " ", 1);
	}
	if (ft_strchr(mod->flags, '.'))
	{
		if (mod->width && !mod->prec && !ft_strcmp(num, "0"))
			s->return_val += write(1, " ", 1);
	}
}

void		type_zeros_p(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	s->return_val += (ft_strchr(mod->flags, '.') && !mod->prec &&
		!ft_strcmp(num, "0")) ? 0 : num_len;
	if (ft_strchr(mod->flags, '0'))
	{
		while (++i < (mod->width - num_len - sign - s->spaces_d))
			s->return_val += write(1, "0", 1);
	}
	else if (mod->prec > num_len)
	{
		while (++i < (mod->prec - num_len))
			s->return_val += write(1, "0", 1);
	}
}

void		type_p(t_mod *mod, t_s *s)
{
	int			sign;
	char		*num;
	intmax_t	val;

	sign = 2;
	val = va_arg(s->ap, long int);
	(!val && !mod->width) ? s->return_val += write(1, "0x", 2) : 0;
	num = ft_itoa_base(val, 16, 'l');
	if (ft_strchr(mod->flags, '-'))
	{
		(val || (!val && mod->width)) ? s->return_val += write(1, "0x", 2) : 0;
		type_zeros_p(mod, num, sign, s);
		if (!(ft_strchr(mod->flags, '.') && mod->prec == 0 && val == 0))
			(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
		type_spaces_p(mod, num, sign, s);
	}
	else
	{
		type_spaces_p(mod, num, sign, s);
		(val || (!val && mod->width)) ? s->return_val += write(1, "0x", 2) : 0;
		type_zeros_p(mod, num, sign, s);
		if (!(ft_strchr(mod->flags, '.') && mod->prec == 0 && val == 0))
			(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
	}
}
