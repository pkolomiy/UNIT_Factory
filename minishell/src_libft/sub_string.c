/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:00:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/02 23:00:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub_string(char *src, size_t start, size_t len)
{
	char	*str;

	str = (char*)malloc(len + 1);
	ft_memcpy((void*)str, (void*)(src + start), len);
	str[len] = '\0';
	return (str);
}
