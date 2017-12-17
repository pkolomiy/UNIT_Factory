/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 21:50:02 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int		exit_x(void)
{
	exit(0);
}

void	new(t_main *m, t_object *object)
{
	object->next = m->objects;
	m->objects = object;
}

void	add_light(t_main *m, t_vector position)
{
	t_light	*light;

	light = (t_light*)malloc(sizeof(t_light));
	light->position = position;
	light->next = m->lights;
	m->lights = light;
}

void	hud(t_main *m)
{
	t_hud	h;

	h.type = X;
	compas(h, m, 975, 40);
	h.type = Y;
	compas(h, m, 975, 265);
	h.type = Z;
	compas(h, m, 975, 500);
	rotate(h, m);
	move(h, m);
}
