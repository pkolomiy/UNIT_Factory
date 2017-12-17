/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:41:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/09 19:41:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_object	*sphere(t_vector position, t_color color, double radius)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->position = position;
	object->radius = radius * radius;
	object->color = color;
	object->shine = 1;
	object->intersect = &intersection_sphere;
	object->normal = &normal_sphere;
	object->next = NULL;
	return (object);
}

_Bool		intersection_sphere(t_ray ray, t_object *object, double *t0)
{
	t_vector	len;
	double		d2;
	double		tca;

	len = SUB(object->position, ray.origin);
	if ((tca = DOT(len, ray.direction)) < 0.0000001 ||
		(d2 = DOT(len, len) - pow(tca, 2)) > object->radius)
		return (0);
	*t0 = tca - sqrt(object->radius - d2);
	if (*t0 < 0.0000001)
		*t0 += tca;
	return (1);
}

t_vector	normal_sphere(t_ray ray, t_object *object)
{
	return (normalize(SUB(ray.hit, object->position)));
}
