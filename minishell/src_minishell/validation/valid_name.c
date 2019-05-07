/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:42:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/03 20:42:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	valid_name(char *name)
{
	if (name[0] >= '0' && name[0] <= '9')
		return (0);
	while (*name)
	{
		if (name_symbol(*name) == 0)
			return (0);
		name++;
	}
	return (1);
}
