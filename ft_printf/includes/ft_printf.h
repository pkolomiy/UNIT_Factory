/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:34:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 15:34:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define BUFFER 4096
# define ITOA_BUF 32

typedef struct s_printf	t_printf;
typedef struct s_buf	t_buf;
typedef struct s_string	t_string;
typedef struct s_number	t_number;
typedef struct s_arg	t_arg;
typedef struct s_flags	t_flags;

struct		s_buf
{
	t_byte	str[BUFFER];
	size_t	size;
};

struct		s_string
{
	t_byte	*ptr;
	size_t	size;
};

struct		s_number
{
	size_t	val;
	t_byte	len;
};

struct		s_flags
{
	t_byte	space : 1;
	t_byte	hash : 1;
	t_byte	plus : 1;
	t_byte	minus : 1;
	t_byte	zero : 1;
	t_byte	have_precision : 1;
	t_byte	have_width : 1;
	t_byte	negative : 1;
	t_byte	hh : 1;
	t_byte	h : 1;
	t_byte	l : 1;
	t_byte	ll : 1;
	t_byte	j : 1;
	t_byte	z : 1;
};

struct		s_arg
{
	t_flags		flags;
	int			h_counter;
	int			l_counter;
	size_t		precision;
	size_t		width;
	t_byte		width_char;
};

struct		s_printf
{
	t_string	ret;
	t_string	fmt;
	va_list		ap;
};

int			ft_printf(char *fmt, ...);
int			ft_dprintf(int fd, char *fmt, ...);
int			ft_asprintf(char **ret, char *fmt, ...);

void		parse_fmt(t_printf *global);
void		parse_arg(t_printf *global, t_buf *buffer);
void		parse_flags(t_printf *global, t_arg *arg);

/*
** flush_buffer.c
*/

t_byte		*join_with_buffer(t_printf *global, t_buf *buffer, size_t size);
void		save_to_ret(t_printf *global, t_buf *buffer, t_string joined);
void		flush_buffer(t_printf *global, t_buf *buffer);
void		flush_buffer_and_str(t_printf *global, t_buf *buffer, t_string str);

void		buffer_set(t_printf *global, t_buf *buffer, t_byte c, size_t size);

void		type_char(t_printf *global, t_arg *arg, t_buf *buffer);
void		type_decimal(t_printf *global, t_arg *arg, t_buf *buffer);
void		type_hexadecimal(t_printf *global, t_arg *arg, t_buf *buffer);
void		type_octal(t_printf *global, t_arg *arg, t_buf *buffer);
void		type_pointer(t_printf *global, t_arg *arg, t_buf *buffer);
void		type_string(t_printf *global, t_arg *arg, t_buf *buffer);
void		type_unsigned(t_printf *global, t_arg *arg, t_buf *buffer);

t_number	get_t_number(t_arg *arg, va_list ap, char c);
void		get_width(t_arg *arg, t_byte num_len, t_byte sign);
void		get_precision(t_arg *arg, t_byte num_len);
t_string	get_itoa_base_string(t_number *num, t_byte base, _Bool uppercase);

void		decimal_to_buffer(t_printf *global, t_buf *buffer, t_number num);
void		string_to_buffer(t_printf *global, t_buf *buffer, t_string str);

#endif
