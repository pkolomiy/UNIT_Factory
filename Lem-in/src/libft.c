/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:08:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/21 15:16:06 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline unsigned	count(char *str)
{
	unsigned	i;
	int			j;

	i = 0;
	j = -1;
	while (str[++j])
		if (str[j] == ' ')
			i++;
	if (i != 2)
		error();
	i = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		i = (*str && *str != ' ') ? i + 1 : i;
		while (*str && *str != ' ')
			str++;
	}
	return (i);
}

char					**split(t_lem *l, char *str)
{
	int			j;

	l->ptr_len = 0;
	!(l->ptr = (char**)malloc(sizeof(char*) * (count(str) + 1))) ? exit(8) : 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (!*str)
			break ;
		j = 0;
		while (str[j] != ' ' && str[j])
			j++;
		!(l->ptr[l->ptr_len] = (char*)malloc((unsigned)(j + 1))) ? exit(8) : 0;
		j = -1;
		while (str[++j] != ' ' && str[j])
			l->ptr[l->ptr_len][j] = str[j];
		l->ptr[l->ptr_len++][j] = '\0';
		while (*str && *str != ' ')
			str++;
	}
	l->ptr[l->ptr_len] = NULL;
	if (l->ptr_len != 3)
		error();
	return (l->ptr);
}

_Bool					cmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

unsigned				len(const char *str)
{
	unsigned	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char					*copy(const char *str)
{
	unsigned	index;
	char		*dst;

	index = 0;
	while (str[index])
		index++;
	!(dst = (char*)malloc(index + 1)) ? exit(8) : 0;
	index = 0;
	while (str[index])
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
