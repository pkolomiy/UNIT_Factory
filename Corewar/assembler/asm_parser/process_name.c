/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:25:35 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

int			ft_time_variable(char *time_variable, int q, int f, char *name)
{
	int		a;

	a = 0;
	f -= q + 1;
	ft_bzero(time_variable, 0);
	while (q && (name[f] != ' ' || name[f] != '\t'))
	{
		time_variable[a++] = name[f++];
		q--;
	}
	time_variable[a] = '\0';
	if (ft_isdigit(name[f - 1]))
		f += 2;
	f++;
	return (f);
}

int			ft_seach_process_name(char *str, int *f)
{
	int		j;

	j = 0;
	while (str[j] != '\0')
	{
		if (ft_isalpha(str[j]) || ft_isdigit(str[j]))
			break ;
		j++;
	}
	if (str[j] == '\0')
		return (-1);
	if (*f == -1)
		(*f)++;
	return (ft_serch_name_proc(str, f, 0, 0));
}

int			ft_serch_name_proc(char *str, int *f, int q, int s)
{
	int		num_of_static_val;
	char	*time_variable;

	while (ft_isalpha(str[*f]) == 0)
		(*f)++;
	while (ft_isalpha(str[(*f)]) || ft_isdigit(str[(*f)]))
	{
		q++;
		(*f)++;
	}
	(*f)++;
	time_variable = malloc(q + 1);
	s = *f;
	s = ft_time_variable(time_variable, q, s, str);
	num_of_static_val = 0;
	while (ft_strcmp(g_op_tab[num_of_static_val].name, time_variable) != 0)
	{
		num_of_static_val++;
		if (num_of_static_val == 16)
			break ;
	}
	if (str[*f - 1] == '%' || ft_isalpha(str[(*f)]) || ft_isdigit(str[(*f)]))
		(*f)--;
	free(time_variable);
	return (num_of_static_val);
}
