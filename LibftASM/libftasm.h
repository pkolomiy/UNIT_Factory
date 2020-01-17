/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:51:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2020/01/10 19:51:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define OK "\e[32;1mOK\e[0m"
#define KO "\e[31;1mKO\e[0m"

// part 1
void ft_bzero(void *ptr, size_t n);
char *ft_strcat(char *s1, char *s2);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_puts(char *s);

// part 2
size_t ft_strlen(char *str);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, void *src, size_t n);
char *ft_strdup(char *s1);

// part 3
void ft_cat(int fd);

// bonus
void *ft_memalloc(size_t size);
int ft_strcmp(char *s1, char *s2);
char *ft_strjoin(char *s1, char *s2);
void ft_putchar(char c);
void ft_putnbr(int nbr);

#endif
