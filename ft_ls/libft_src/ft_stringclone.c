/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringclone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 17:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/09 17:07:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stringclone(char *src, t_string *dst)
{
	dst->size = ft_strlen(src);
	dst->ptr = (t_byte*)malloc(dst->size + 1);
	ft_memcpy((void*)dst->ptr, (void*)src, dst->size);
	dst->ptr[dst->size] = '\0';
}
