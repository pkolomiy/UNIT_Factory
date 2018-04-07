/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:47:09 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:44:42 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef struct	s_mod
{
	int			prec;
	int			size;
	int			type;
	int			width;
	char		*flags;
	char		*modifs;
}				t_mod;

typedef struct	s_s
{
	int			return_val;
	int			param_num;
	int			spaces_d;
	int			error;
	va_list		ap;
}				t_s;

int				ft_printf(char *str, ...);

void			ft_putwstr(wchar_t *s);
void			ft_putwchar(wchar_t s);
void			type_c(t_mod *mod, t_s *s);
void			type_d(t_mod *mod, t_s *s);
void			type_o(t_mod *mod, t_s *s);
void			type_p(t_mod *mod, t_s *s);
void			type_s(t_mod *mod, t_s *s);
void			type_u(t_mod *mod, t_s *s);
void			type_x(t_mod *mod, t_s *s);
void			type_smth(t_mod *mod, t_s *s);
void			type_big_d(t_mod *mod, t_s *s);
void			type_big_s(t_mod *mod, t_s *s);
void			print_flags(t_mod *mod, t_s *s);
void			handle_modif(char *str, int *i, t_s *s);

char			*ft_itoa_ulong(size_t n);
char			*ft_itoa_long(long long n);

size_t			ft_bstrlen(wchar_t *str);
size_t			ft_wcharlen(wchar_t s);

#endif
