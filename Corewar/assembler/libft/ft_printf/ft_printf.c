/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:39:19 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:07 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_struct(t_s *s)
{
	s->error = 0;
	s->spaces_d = 0;
	s->param_num = 0;
	s->return_val = 0;
}

void	print_it(char *str, t_s *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '%')
				s->return_val += write(1, &str[i++], 1);
			else
				handle_modif(str, &i, s);
		}
		else
			s->return_val += write(1, &str[i++], 1);
	}
}

int		ft_printf(char *str, ...)
{
	t_s		s;

	init_struct(&s);
	va_start(s.ap, str);
	print_it(str, &s);
	va_end(s.ap);
	return (s.return_val);
}
