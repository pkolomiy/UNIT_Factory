/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:12:04 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 17:20:46 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	let_num(char const *s, char c, int i)
{
	int	n;

	n = 0;
	while (s[i + n] != c && s[i + n])
		n++;
	return (n);
}

static char	*put_word(char const *s, char c, int *i)
{
	int		j;
	char	*word;

	word = (char*)malloc(sizeof(char) * let_num(s, c, *i) + 1);
	if (word == NULL)
		return (0);
	j = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		word[j] = s[*i];
		(*i)++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	char			**arr;

	if (!s || !c)
		return (0);
	i = 0;
	j = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * ft_wordnum((char*)s, c) + 1)))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if ((arr[j] = put_word(s, c, &i)) == 0)
				return (0);
			j++;
		}
		else
			i++;
	}
	arr[j] = 0;
	return (arr);
}
