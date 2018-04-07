/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_big_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:08:21 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

wchar_t	*put_in_list(wchar_t *str, t_s *s, t_mod *mod)
{
	if (!(str = va_arg(s->ap, wchar_t*)) && !mod->width)
	{
		ft_putstr("(null)");
		s->return_val += 6;
	}
	return (str);
}

void	type_spaces_bs(t_mod *mod, wchar_t *str, t_s *s)
{
	int	i;
	int	len;
	int	str_len;

	i = -1;
	str_len = (int)ft_bstrlen(str);
	len = (!ft_strchr(mod->flags, '.') || (mod->prec > str_len))
		? str_len : mod->prec;
	if (ft_strchr(mod->flags, '.'))
	{
		s->spaces_d = mod->width - len;
		while (++i < s->spaces_d)
			s->return_val += (ft_strchr(mod->flags, '0')) ? write(1, "0", 1) :
				write(1, " ", 1);
	}
	if (mod->width)
	{
		while (++i < (mod->width - len))
			s->return_val += (ft_strchr(mod->flags, '0')) ? write(1, "0", 1) :
			write(1, " ", 1);
	}
}

void	minus_bs(t_mod *mod, t_s *s, wchar_t *str)
{
	int	i;

	i = -1;
	if (!mod->prec && ft_bstrlen(str))
	{
		if (!ft_strchr(mod->flags, '.'))
		{
			ft_putwstr(str);
			s->return_val += ft_bstrlen(str);
		}
	}
	else if (ft_bstrlen(str))
	{
		while (++i < mod->prec && str[i])
			ft_putwchar(str[i]);
		s->return_val += ft_bstrlen(str);
	}
	type_spaces_bs(mod, str, s);
}

void	type_str(t_mod *mod, wchar_t *str, t_s *s)
{
	int	i;

	i = 0;
	if (!mod->prec && ft_bstrlen(str))
	{
		if (!ft_strchr(mod->flags, '.'))
		{
			ft_putwstr(str);
			s->return_val += ft_bstrlen(str);
		}
	}
	else if (ft_bstrlen(str))
	{
		while (i < mod->prec / (int)ft_wcharlen(str[i]) && str[i])
		{
			ft_putwchar(str[i]);
			s->return_val += ft_wcharlen(str[i]);
			i++;
		}
	}
}

void	type_big_s(t_mod *mod, t_s *s)
{
	wchar_t	*str;

	str = 0;
	str = put_in_list(str, s, mod);
	if (!str)
		return ;
	if (ft_strchr(mod->flags, '-'))
		minus_bs(mod, s, str);
	else
	{
		type_spaces_bs(mod, str, s);
		type_str(mod, str, s);
	}
}
