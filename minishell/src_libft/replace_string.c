/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:17:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/02 23:17:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_string(char *src, char *dst, size_t start, size_t len)
{
	size_t	dst_len;
	size_t	src_len;
	char	*new_str;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	new_str = (char*)malloc(dst_len + src_len - len + 1);
	ft_memcpy((void*)new_str, (void*)src, start);
	ft_memcpy((void*)(new_str + start), (void*)dst, dst_len);
	ft_memcpy((void*)(new_str + start + dst_len),
			(void*)(src + start + len), src_len - len - start);
	new_str[dst_len + src_len - len] = '\0';
	return (new_str);
}
