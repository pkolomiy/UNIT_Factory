/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:13:18 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/27 22:36:26 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	projection(t_v *v, int n)
{
	v->a = 0;
	v->b = 0;
	while (v->b < v->st.mapy)
	{
		while (v->a < v->st.mapx)
		{
			X = X0;
			Y = Y0;
			(n == 1) ? (Z = Z0 * 0.15) : 0;
			(n == 2) ? (Z = Z0) : 0;
			v->a++;
		}
		v->a = 0;
		v->b++;
	}
	(n == 1) ? rotx(v, 5.84) : 0;
	(n == 1) ? roty(v, 5.84) : 0;
	(n == 1) ? rotz(v, 0.61) : 0;
	(n == 2) ? rotx(v, 5.44) : 0;
	(n == 2) ? roty(v, -5.63) : 0;
	(n == 2) ? rotz(v, -0.52) : 0;
}