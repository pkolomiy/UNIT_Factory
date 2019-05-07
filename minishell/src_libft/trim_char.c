/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/03 12:30:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim_char(char *str, char c)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(str);
	start = 0;
	while (str[start] && str[start] == c)
		start++;
	if (start == end)
		return (NULL);
	end--;
	while (end > 0 && str[end] == c)
		end--;
	return (ft_strcut(str, start, end));
}
