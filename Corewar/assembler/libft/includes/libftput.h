/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftput.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:45:27 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/16 19:33:57 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPUT_H
# define _LIBFTPUT_H

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t s);
void				ft_putstr(char const *s);
void				ft_putwstr(wchar_t *str);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);

#endif
