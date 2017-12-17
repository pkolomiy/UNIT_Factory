/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:44:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/14 12:44:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_object	*cylinder(t_vector pos, t_vector dir, t_color color, double radius)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->position = pos;
	object->direction = normalize(dir);
	object->radius = radius * radius;
	object->color = color;
	object->shine = 1;
	object->intersect = &intersection_cylinder;
	object->normal = &normal_cylinder;
	object->next = NULL;
	return (object);
}

_Bool		intersection_cylinder(t_ray ray, t_object *object, double *t0)
{
	t_vector	temp1;
	t_vector	temp2;
	t_vector	temp3;
	double		var[4];

	temp1 = SCALE(object->direction, DOT(ray.direction, object->direction));
	temp1 = SUB(ray.direction, temp1);
	var[A] = DOT(temp1, temp1);
	temp2 = SUB(ray.origin, object->position);
	temp3 = SCALE(object->direction, DOT(temp2, object->direction));
	temp3 = SUB(temp2, temp3);
	var[B] = 2 * DOT(temp1, temp3);
	var[C] = DOT(temp3, temp3) - object->radius;
	var[D] = pow(var[B], 2) - 4 * var[A] * var[C];
	return (solve(var, t0));
}

t_vector	normal_cylinder(t_ray ray, t_object *object)
{
	t_vector	temp1;
	t_vector	temp2;

	temp1 = SUB(ray.hit, object->position);
	temp2 = SCALE(object->direction, DOT(temp1, object->direction));
	return (normalize(SUB(temp1, temp2)));
}
