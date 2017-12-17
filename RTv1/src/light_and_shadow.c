/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:13:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 19:08:09 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_color	final_color(t_object *object, double diffuse, double specular)
{
	t_color	final;

	if ((final.red = object->color.red * (diffuse + AMBIENT) +
	(specular * object->shine)) > 1)
		final.red = 1;
	if ((final.green = object->color.green * (diffuse + AMBIENT) +
	(specular * object->shine)) > 1)
		final.green = 1;
	if ((final.blue = object->color.blue * (diffuse + AMBIENT) +
	(specular * object->shine)) > 1)
		final.blue = 1;
	return (final);
}

void	calculate_specular(t_shader *shader)
{
	t_vector	r;
	t_vector	v;
	double		h;
	double		specular;

	h = 2 * DOT(shader->object_norm, shader->light_direction);
	r = SCALE(shader->object_norm, h);
	r = normalize(SUB(shader->light_direction, r));
	v = normalize(SUB(shader->hit, shader->camera_position));
	if ((specular = DOT(v, r)) > 0)
	{
		specular = pow(specular, 10);
		specular *= 0.9;
		shader->specular += specular;
	}
}

_Bool	shadow(t_ray ray, t_vector light_position, t_object *objects)
{
	double		tnear;
	double		t0;

	ray.direction = SCALE(normalize(SUB(ray.hit, light_position)), -1);
	ray.origin = ray.hit;
	tnear = sqrt(LEN(SUB(ray.hit, light_position)));
	t0 = INFINITY;
	while (objects)
	{
		if (objects->intersect(ray, objects, &t0))
		{
			if (t0 < tnear)
				return (1);
		}
		objects = objects->next;
	}
	return (0);
}

t_color	light(t_object *object, t_ray ray, t_main *m)
{
	t_light		*light;
	t_shader	shader;
	double		diffuse;

	if (m->move_mode)
		return (object->color);
	shader.diffuse = 0;
	shader.specular = 0;
	shader.hit = ray.hit;
	shader.object_norm = object->normal(ray, object);
	shader.camera_position = m->camera.position;
	light = m->lights;
	while (light)
	{
		if (!shadow(ray, light->position, m->objects))
		{
			shader.light_direction = normalize(SUB(light->position, ray.hit));
			if ((diffuse = DOT(shader.object_norm, shader.light_direction)) > 0)
				shader.diffuse += diffuse;
			calculate_specular(&shader);
		}
		light = light->next;
	}
	return (final_color(object, shader.diffuse, shader.specular));
}
