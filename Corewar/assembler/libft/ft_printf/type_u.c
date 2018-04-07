/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:06:08 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:44:07 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

intmax_t	deal_with_size_u(t_mod *mod, t_s *s)
{
	intmax_t	val;

	if ((mod->type == 'u' && mod->size == 'l') ||
			(mod->type == 'U' && !mod->size))
		val = va_arg(s->ap, unsigned long);
	else if (mod->size == 'L')
		val = va_arg(s->ap, unsigned long long);
	else if (mod->size == 'z')
		val = va_arg(s->ap, size_t);
	else if (mod->size == 'j')
		val = va_arg(s->ap, intmax_t);
	else
		val = va_arg(s->ap, unsigned int);
	return (val);
}

void		type_spaces_u(t_mod *mod, char *num, int sign, t_s *s)
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

void		type_zeros_u(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	s->return_val += (ft_strchr(mod->flags, '.') && !mod->prec &&
		!ft_strcmp(num, "0")) ? 0 : num_len;
	if ((ft_strchr(mod->flags, '+') && mod->type != 'u') || num[0] == '-')
		s->return_val += (num[0] == '-') ? write(1, "-", 1) : write(1, "+", 1);
	else if (ft_strchr(mod->flags, ' ') && mod->type != 'u')
		s->return_val += (num[0] == '-') ? write(1, "-", 1) : write(1, " ", 1);
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

void		type_u(t_mod *mod, t_s *s)
{
	int			sign;
	char		*num;
	intmax_t	val;

	val = deal_with_size_u(mod, s);
	num = ft_itoa_ulong(val);
	sign = (ft_strchr(mod->flags, '+') || ft_strchr(mod->flags, ' ') ||
		num[0] == '-') ? 1 : 0;
	if (ft_strchr(mod->flags, '-'))
	{
		type_zeros_u(mod, num, sign, s);
		if (!(ft_strchr(mod->flags, '.') && mod->prec == 0 && val == 0))
			(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
		type_spaces_u(mod, num, sign, s);
	}
	else
	{
		type_spaces_u(mod, num, sign, s);
		type_zeros_u(mod, num, sign, s);
		if (!(ft_strchr(mod->flags, '.') && mod->prec == 0 && val == 0))
			(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
	}
}
