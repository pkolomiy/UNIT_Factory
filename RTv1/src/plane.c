/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:11:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 16:19:10 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_object	*plane(t_vector position, t_vector direction, t_color color)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->position = position;
	object->direction = normalize(direction);
	object->color = color;
	object->shine = 0;
	object->intersect = &intersection_plane;
	object->normal = &normal_plane;
	object->next = NULL;
	return (object);
}

_Bool		intersection_plane(t_ray ray, t_object *object, double *t0)
{
	t_vector	pt;
	double		t1;
	double		t2;

	t1 = DOT(object->direction, ray.direction);
	if (!t1)
		return (0);
	pt = SUB(object->position, ray.origin);
	t2 = (DOT(object->direction, pt)) / t1;
	if (t2 > 0.0000001)
		*t0 = t2;
	return (1);
}

t_vector	normal_plane(t_ray ray, t_object *object)
{
	if (DOT(object->direction, ray.direction) > 0)
		return (SCALE(object->direction, -1));
	return (object->direction);
}
