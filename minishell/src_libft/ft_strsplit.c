/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:44:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/11 19:44:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split_parts(char *str, char c)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			counter++;
		while (*str && *str != c)
			str++;
	}
	return (counter);
}

static char		*cut(char **str, char c)
{
	char	*temp;
	char	*ret;

	temp = *str;
	while (*temp && *temp != c)
		temp++;
	ret = (char*)malloc(temp - *str + 1);
	temp = ret;
	while (*(*str) && *(*str) != c)
	{
		*temp = *(*str);
		(*str)++;
		temp++;
	}
	*temp = '\0';
	return (ret);
}

t_strarr		ft_strsplit(char *str, char c)
{
	t_strarr	arr;
	char		**temp;

	arr = (t_strarr){NULL, 0};
	if (str == NULL || c == '\0')
		return (arr);
	arr.len = count_split_parts(str, c);
	arr.ptr = (char**)malloc(sizeof(char*) * (arr.len + 1));
	temp = arr.ptr;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			*temp = cut(&str, c);
			temp++;
		}
	}
	*temp = NULL;
	return (arr);
}
