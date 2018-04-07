/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftconvert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:45:27 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/28 02:45:51 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTCONVERT_H
# define _LIBFTCONVERT_H

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_atoi_base(char *str, int base);
int					ft_digitnum(unsigned long long n);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t num, int base, int letter_size);

#endif
