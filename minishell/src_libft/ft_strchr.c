/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:44:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/02 22:44:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, t_byte c)
{
	t_byte	*temp;

	if (str == NULL)
		return (NULL);
	temp = (t_byte*)str;
	while (*temp)
	{
		if (*temp == c)
			return ((char*)temp);
		temp++;
	}
	return (NULL);
}
