/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:26:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/15 13:26:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_object	*cone(t_vector pos, t_vector dir, t_color color, double radius)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->position = pos;
	object->direction = normalize(dir);
	object->radius = (M_PI * radius) / 180.;
	object->color = color;
	object->shine = 1;
	object->intersect = &intersection_cone;
	object->normal = &normal_cone;
	object->next = NULL;
	return (object);
}

_Bool		intersection_cone(t_ray ray, t_object *object, double *t0)
{
	t_vector	temp[3];
	double		var[4];
	double		dt[4];

	dt[0] = DOT(ray.direction, object->direction);
	dt[1] = pow(cos(object->radius), 2);
	dt[2] = pow(sin(object->radius), 2);
	temp[0] = SCALE(object->direction, dt[0]);
	temp[0] = SUB(ray.direction, temp[0]);
	var[A] = dt[1] * DOT(temp[0], temp[0]) - dt[2] * pow(dt[0], 2);
	temp[1] = SUB(ray.origin, object->position);
	dt[3] = DOT(temp[1], object->direction);
	temp[2] = SCALE(object->direction, DOT(temp[1], object->direction));
	temp[2] = SUB(temp[1], temp[2]);
	var[B] = 2 * dt[1] * DOT(temp[0], temp[2]) - 2 * dt[2] * dt[0] * dt[3];
	var[C] = dt[1] * DOT(temp[2], temp[2]) - dt[2] * pow(dt[3], 2);
	var[D] = pow(var[B], 2) - 4 * var[A] * var[C];
	return (solve(var, t0));
}

t_vector	normal_cone(t_ray ray, t_object *object)
{
	t_vector	temp1;
	t_vector	temp2;

	temp1 = normalize(SUB(ray.hit, object->position));
	temp2 = SCALE(object->direction, (sqrt(LEN(temp1)) / cos(object->radius)));
	if (DOT(temp1, object->direction) < 0)
		temp2 = SCALE(temp2, -1);
	return (normalize(SUB(temp1, temp2)));
}
