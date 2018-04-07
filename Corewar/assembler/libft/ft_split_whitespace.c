/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:01:53 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/06 18:33:19 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		let_num(char const *s, int i)
{
	int	n;

	n = 0;
	while (s[i + n] != ' ' && s[i + n] != '\t' && s[i + n])
		n++;
	return (n);
}

static char		*put_word(char const *s, int *i)
{
	int		j;
	char	*word;

	word = (char *)malloc(sizeof(char) * let_num(s, *i) + 1);
	if (word == NULL)
		return (0);
	j = 0;
	while (s[*i] != '\0' && s[*i] != ' ' && s[*i] != '\t')
	{
		word[j] = s[*i];
		(*i)++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

size_t			wordnum(char *s)
{
	int		i;
	size_t	num;

	i = -1;
	num = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\t' &&
			((s[i + 1] == ' ' || s[i + 1] == '\t') || s[i + 1] == '\0'))
			num++;
	}
	return (num);
}

char			**ft_split_whitespace(char const *s)
{
	int				i;
	int				j;
	char			**arr;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	if ((arr = (char **)malloc(sizeof(char *) * wordnum((char *)s) + 1)) == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			if ((arr[j] = put_word(s, &i)) == 0)
				return (0);
			j++;
		}
		else
			i++;
	}
	arr[j] = 0;
	return (arr);
}
