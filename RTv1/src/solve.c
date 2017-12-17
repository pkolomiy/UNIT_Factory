/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:48:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/07 15:48:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector	normalize(t_vector v)
{
	double	l;

	if ((l = LEN(v)) > 0)
	{
		l = 1 / sqrt(l);
		return ((t_vector){v.x * l, v.y * l, v.z * l});
	}
	return ((t_vector){0, 0, 0});
}

_Bool		solve(double var[], double *t0)
{
	double		t;
	double		t1;
	double		t2;

	if (var[D] < 0)
		return (0);
	else if (var[D] == 0)
		*t0 = -0.5 * var[B] / var[A];
	else
	{
		t = (var[B] > 0) ?
		-0.5 * (var[B] + sqrt(var[D])) :
		-0.5 * (var[B] - sqrt(var[D]));
		t1 = t / var[A];
		t2 = var[C] / t;
		t1 = t1 > t2 ? t2 : t1;
		if (t1 > 0.000001)
			*t0 = t1;
	}
	return (1);
}
