/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_and_comm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:20:57 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/28 16:58:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool	valid_name(char *name, char **error, int j)
{
	int	i;
	int	fl;
	int	len;
	int	count;

	i = -1;
	fl = 1;
	count = 0;
	while (name[++i])
	{
		if (name[i] == '\"')
			count++;
	}
	len = (int)ft_strlen(name);
	while (fl <= len && (name[len - fl] == ' ' || name[len - fl] == '\t'))
		fl++;
	if (count > 2 || name[len - fl] != '\"')
	{
		ft_memdel((void**)&name);
		(!(*error)) ? *error = error_message(j, 'h') : 0;
		return (0);
	}
	return (1);
}

char	*join_hard_str(char **file, char *tmp, int n, int *i)
{
	int		fl;
	char	*tmp_cp;

	fl = n;
	n = 0;
	while (fl != 2 && file[*i] && n != 2)
	{
		count_char(file[*i], &n, '\"');
		tmp_cp = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
		tmp = ft_strjoin(tmp_cp, file[*i]);
		ft_memdel((void**)&tmp_cp);
		if (n < 2)
			(*i)++;
		if (n > 3)
		{
			ft_memdel((void**)&tmp);
			return (NULL);
		}
	}
	return (tmp);
}

void	check_line(char *str, char **error, int j)
{
	int	i;

	if (!ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		i = ft_strlen(COMMENT_CMD_STRING) - 1;
		if (ft_strlen(ft_strchr(str, '\"')) > COMMENT_LENGTH + 2)
			(!(*error)) ? *error = ft_strdup("Your comment is too long!") : 0;
		while (str[++i] != '\"')
		{
			if (str[i] != ' ' && str[i] != '\t')
				(!(*error)) ? *error = error_message(j, 'h') : 0;
		}
	}
	else if (!ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		i = ft_strlen(NAME_CMD_STRING) - 1;
		if (ft_strlen(ft_strchr(str, '\"')) > PROG_NAME_LENGTH + 2)
			(!(*error)) ? *error = ft_strdup("Champ's name is too long!") : 0;
		while (str[++i] != '\"')
		{
			if (str[i] != ' ' && str[i] != '\t')
				(!(*error)) ? *error = error_message(j, 'h') : 0;
		}
	}
}

char	*deal_with_it(char **file, char **error, int *i)
{
	int		n;
	char	*tmp;
	char	*name;

	n = 0;
	check_line(file[*i], error, *i);
	if (count_char(file[*i], &n, '\"') > 2 || !ft_strchr(file[*i], '\"'))
	{
		(!(*error)) ? *error = error_message(*i, 'h') : 0;
		return (NULL);
	}
	tmp = (n == 2) ? ft_strdup(file[*i]) : NULL;
	if ((tmp = join_hard_str(file, tmp, n, i)) == NULL)
	{
		(!(*error)) ? *error = error_message(*i, 'h') : 0;
		return (NULL);
	}
	name = ft_strdup(tmp);
	ft_memdel((void**)&tmp);
	if (!valid_name(name, error, *i))
		return (NULL);
	return (name);
}

_Bool	valid_name_and_comm(char **file, t_asm *s_file, char **error, int *i)
{
	while (file[++(*i)] && (!s_file->name || !s_file->comment))
	{
		if (ft_strlen(file[*i]) == 0)
			continue ;
		if (!ft_strncmp(file[*i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			(s_file->name) ? *error = name_comment_error(*i, "Name") :
			(s_file->name = deal_with_it(file, error, i));
		}
		else if (!ft_strncmp(file[*i], COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)))
		{
			(s_file->comment) ? *error = name_comment_error(*i, "Comment") :
			(s_file->comment = deal_with_it(file, error, i));
		}
		else if (ft_strstr(file[*i], COMMENT_CMD_STRING) ||
				ft_strstr(file[*i], NAME_CMD_STRING))
			*error = error_message(*i, 'l');
		else if (!s_file->name || !s_file->comment)
			(!(*error)) ? *error = error_message(*i, 'm') : 0;
		if (*error)
			return (0);
	}
	return (1);
}
