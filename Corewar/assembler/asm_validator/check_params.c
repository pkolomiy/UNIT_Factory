/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:25:20 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/27 19:28:25 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*anti_leaks_skip_spaces(char *str)
{
	char	*res;

	str = ft_skip_whitespace(str, 0);
	res = ft_revstr(str);
	ft_memdel((void**)&str);
	res = ft_skip_whitespace(res, 0);
	str = ft_revstr(res);
	ft_memdel((void**)&res);
	return (str);
}

_Bool		invalid_param(char *prm, int len)
{
	if (!len || (len == 1 && !ft_isdigit(prm[0])))
		return (1);
	if (prm[0] != 'r' && !ft_isdigit(prm[0]) && prm[0] != '-' &&
		prm[0] != DIRECT_CHAR && prm[0] != LABEL_CHAR)
		return (1);
	if (prm[0] == DIRECT_CHAR && (prm[1] != '-' &&
		prm[1] != LABEL_CHAR && !ft_isdigit(prm[1])))
		return (1);
	if (prm[0] == DIRECT_CHAR && ((len == 2 && (prm[1] == '-' || prm[1] == '+'))
			|| (len == 3 && prm[1] == '-' && prm[2] == '0')))
		return (1);
	return (0);
}

static void	check_error(char c, char **error, int j)
{
	if (!ft_isdigit(c))
		(!(*error)) ? *error = error_message(j, 'p') : 0;
}

_Bool		valid_param(char *str, char **error, int j)
{
	int		i;
	int		len;
	char	*prm;

	i = 0;
	prm = ft_strdup(str);
	prm = anti_leaks_skip_spaces(prm);
	len = (int)ft_strlen(prm);
	if (invalid_param(prm, len))
	{
		ft_memdel((void**)&prm);
		(!(*error)) ? *error = error_message(j, 'p') : 0;
		return (0);
	}
	if (len > 1 && ((prm[0] != DIRECT_CHAR && prm[0] != LABEL_CHAR) ||
					(prm[0] == DIRECT_CHAR && prm[1] != LABEL_CHAR)))
	{
		(i == 0 && prm[0] == DIRECT_CHAR && prm[1] == '-') ? i++ : 0;
		while (prm[++i] && !(*error))
			check_error(prm[i], error, j);
	}
	ft_memdel((void**)&prm);
	if (*error)
		return (0);
	return (1);
}

_Bool		check_params(char *prm, int ret, char **error, int j)
{
	int		i;
	int		sep;
	int		res;
	int		num;
	char	**arr;

	i = -1;
	res = 1;
	sep = 0;
	num = ft_wordnum(prm, SEPARATOR_CHAR);
	if (num != g_op_tab[ret].args_num)
	{
		(!(*error)) ? *error = error_message(j, 'n') : 0;
		return (0);
	}
	count_char(prm, &sep, SEPARATOR_CHAR);
	((sep != num - 1) && !(*error)) ? *error = error_message(j, 'l') : NULL;
	arr = ft_strsplit(prm, SEPARATOR_CHAR);
	while (arr[++i])
	{
		if (!valid_param(arr[i], error, j))
			res = 0;
	}
	ft_free_arr(arr);
	return (res);
}
