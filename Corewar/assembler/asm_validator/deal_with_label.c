/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:53:01 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/27 18:46:24 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool	check_lexical_error(char *str, char **error, int i)
{
	int	j;
	int	len;

	j = -1;
	len = ft_strlen(str);
	if (str[0] == LABEL_CHAR)
	{
		*error = error_message(i, 'l');
		return (0);
	}
	while (++j < len - 2)
	{
		if ((str[j] == LABEL_CHAR && str[j + 1] == LABEL_CHAR))
		{
			*error = error_message(i, 'l');
			return (0);
		}
	}
	return (1);
}

int		cut_label(char **str, int len)
{
	int		i;
	int		j;
	int		n;
	char	*res;

	j = 0;
	i = len;
	n = ft_strlen(*str);
	if (len >= n)
		return (1);
	res = ft_strnew(n - (size_t)(len + 1));
	while (++i < n)
	{
		res[j] = (*str)[i];
		j++;
	}
	res[j] = '\0';
	(*str) ? free(*str) : 0;
	*str = ft_skip_whitespace(res, 0);
	return (0);
}

_Bool	valid_label(char **str, char **arr, int words, t_asm *s_file)
{
	int	i;
	int fl;
	int	len;
	int	slen;

	i = -1;
	fl = 0;
	while (++i < words)
	{
		slen = ft_strlen(*str);
		len = ft_strlen(arr[i]);
		if (is_label_char(arr[i][len - 1]) && (i != words - 1 ||
					(i == words - 1 && (*str)[slen - 1] == LABEL_CHAR)))
		{
			if (!s_file->labels)
				s_file->labels = ft_lstnew(arr[i], (size_t)len);
			else
				ft_lstadd(&s_file->labels, ft_lstnew(arr[i], (size_t)len));
			fl += (cut_label(str, len)) ? 1 : 0;
			fl++;
		}
		if (fl > 1)
			return (0);
	}
	return (1);
}

void	check_labels_is_label_char(t_list *labels, char **error, int i)
{
	int		j;
	int		len;
	t_list	*tmp;

	tmp = labels;
	while (tmp)
	{
		j = -1;
		len = (int)ft_strlen((char*)(tmp->content));
		while (++j < len)
		{
			if (!is_label_char(((char*)tmp->content)[j]))
			{
				(!(*error)) ? *error = error_message(i, 'l') : 0;
				return ;
			}
		}
		tmp = tmp->next;
	}
}

void	deal_with_label(char **str, t_asm *s_file, char **error, int i)
{
	int		words;
	char	**tmp;

	if (ft_strchr(*str, LABEL_CHAR))
	{
		words = (int)ft_wordnum(*str, LABEL_CHAR);
		if (!check_lexical_error(*str, error, i))
			return ;
		tmp = ft_strsplit(*str, LABEL_CHAR);
		if (!valid_label(str, tmp, words, s_file))
			*error = name_comment_error(i, "Label");
		ft_free_arr(tmp);
	}
	else if (!ft_strchr(*str, ' ') && !ft_strchr(*str, '\t')
									&& !ft_strchr(*str, DIRECT_CHAR))
		(!(*error)) ? *error = error_message(i, 'h') : 0;
	check_labels_is_label_char(s_file->labels, error, i);
}
