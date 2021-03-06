/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_symbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:39:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/02 23:39:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

_Bool	name_symbol(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' ||
		(c >= '0' && c <= '9'))
		return (1);
	return (0);
}
