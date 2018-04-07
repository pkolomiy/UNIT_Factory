/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:00:38 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:16:12 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void		ft_write(char *error, char *s1, char *s2)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		error[i] = s1[i];
	error[i++] = (char)(g_err.arg + 48);
	error[i++] = ' ';
	while (s2[j] != '\0')
		error[i++] = s2[j++];
	j = 0;
	while (g_err.process[j])
	{
		error[i++] = g_err.process[j];
		j++;
	}
	error[i] = '\0';
}

void		three_digit_number(char *error, int num, int *j)
{
	int		i;
	int		s;

	i = 3;
	s = 100;
	while (i > 0)
	{
		error[*j] = num / s + 48;
		num %= s;
		s /= 10;
		i--;
		(*j)++;
	}
}

void		ft_write_lable_error_norm(char *error, int j, char *k, char *h)
{
	ft_strcpy(&error[14], g_err.process);
	j = 0;
	j = 14 + ft_strlen(g_err.process);
	ft_strcpy(&error[j], h);
	j += ft_strlen(h);
	three_digit_number(error, g_err.line + 1, &j);
	error[j++] = LABEL_CHAR;
	three_digit_number(error, g_err.t_char + 1, &j);
	error[j++] = ']';
	ft_strcpy(&error[j], k);
	error[j + 14] = LINE;
	j += 17;
	ft_strcpy(&error[j], g_err.process);
	j += ft_strlen(g_err.process);
	error[j++] = LINE;
	error[j] = '\0';
}

void		ft_write_lable_error(char *error)
{
	char	z[15];
	char	h[50];
	int		j;
	char	k[18];

	j = 0;
	ft_strcpy(z, "No such label ");
	ft_strcpy(h, " while attempting to dereference token [TOKEN][");
	ft_strcpy(k, " DIRECT_LABEL  %:");
	ft_strcpy(error, z);
	if (g_err.process != NULL)
		ft_write_lable_error_norm(error, j, k, h);
}
