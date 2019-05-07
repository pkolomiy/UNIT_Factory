/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_with_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:55:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/05 16:55:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_with_char(char *part1, char *part2, char c)
{
	char	*path;
	size_t	part1_len;
	size_t	part2_len;

	if (!part1 || !part2)
		return (NULL);
	part1_len = ft_strlen(part1);
	part2_len = ft_strlen(part2);
	path = (char*)malloc(part1_len + part2_len + 2);
	ft_memcpy((void*)path, part1, part1_len);
	path[part1_len] = c;
	ft_memcpy((void*)(path + part1_len + 1), part2, part2_len);
	path[part1_len + part2_len + 1] = '\0';
	return (path);
}
