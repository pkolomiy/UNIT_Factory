/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:59:52 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

int			labe_character(char c)
{
	int		i;
	char	*z;

	i = 0;
	z = LABEL_CHARS;
	while (z[i] != '\0')
	{
		if (z[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			is_lable(char *s, char c)
{
	int		x;

	x = 0;
	while (s[x] == ' ' || s[x] == '\t')
		x++;
	while (labe_character(s[x]) && s[x] != c && s[x] != '\0')
		x++;
	if (s[x] == c && s[x - 1] != DIRECT_CHAR)
	{
		return (x);
	}
	else
		return (-1);
}

int			ft_search_labe(char *name, t_block *b1, int q, int f)
{
	int		x;

	x = 0;
	while (name[f] == ' ' || name[f] == '\t')
		f++;
	while (ft_strchr(LABEL_CHARS, name[f]) != NULL)
	{
		q++;
		f++;
	}
	if (name[f] != LABEL_CHAR)
		return (-1);
	b1->name = malloc(q + 1);
	b1->next = NULL;
	f -= q;
	while (q > 0)
	{
		b1->name[x++] = name[f++];
		q--;
	}
	b1->name[x] = '\0';
	return (f);
}
