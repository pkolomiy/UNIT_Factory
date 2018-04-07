/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:44:03 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/26 19:27:10 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	flag == 0 - soft whitespace
**	flag == 1 - hard whitespace
**	deallocate old string!
*/

char	*ft_skip_whitespace(char *line, int flag)
{
	int		i;
	int		j;
	int		len;
	char	*res;
	char	*tmp;

	i = 0;
	j = -1;
	if (!line)
		return (NULL);
	tmp = (ft_strlen(line)) ? ft_strdup(line) : ft_strdup("\t");
	ft_memdel((void**)&line);
	while (tmp[i] == ' ' || tmp[i] == '\t' || (flag == 1 && tmp[i] == '\n'))
		i++;
	if (i == 0)
		return (tmp);
	len = (int)ft_strlen(tmp) - i + 1;
	res = (char*)ft_memalloc(len);
	while (++j < len)
		res[j] = tmp[i++];
	res[j] = '\0';
	ft_memdel((void**)&tmp);
	return (res);
}
