/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:52:19 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*join_result(char *str, char *result)
{
	char	*tmp;
	char	*line;
	char	*res_cpy;

	if (ft_strlen(str) == 0)
		line = ft_strdup("\t");
	else
		line = ft_strdup(str);
	tmp = ft_strjoin(line, "\n");
	ft_memdel((void**)&line);
	res_cpy = ft_strdup(result);
	ft_memdel((void**)&result);
	result = ft_strjoin(res_cpy, tmp);
	ft_memdel((void**)&res_cpy);
	ft_memdel((void**)&tmp);
	return (result);
}

char	*asm_reader(char *name)
{
	int		i;
	int		fd;
	char	*line;
	char	*result;

	result = NULL;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((i = get_next_line(fd, &line)))
	{
		if (i == -1)
		{
			ft_memdel((void**)&result);
			break ;
		}
		result = join_result(line, result);
		ft_memdel((void**)&line);
	}
	close(fd);
	return (result);
}
