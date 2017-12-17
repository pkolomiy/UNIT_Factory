/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:56:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/17 00:06:15 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_object	*intersection(t_ray *ray, t_object *objects)
{
	t_object	*object;
	double		tnear;
	double		t0;

	tnear = INFINITY;
	object = NULL;
	while (objects)
	{
		t0 = INFINITY;
		if (objects->intersect(*ray, objects, &t0))
		{
			if (t0 < tnear)
			{
				tnear = t0;
				object = objects;
			}
		}
		objects = objects->next;
	}
	if (object)
		ray->hit = ADD(SCALE(ray->direction, tnear), ray->origin);
	return (object);
}

t_ray		get_ray(int x, int y, t_camera cam)
{
	t_ray	ray;
	double	w;
	double	h;

	w = (2 * ((x + 0.5) * INVX) - 1) * ANGLE * ASPECT_RATIO;
	h = (1 - 2 * ((y + 0.5) * INVY)) * ANGLE;
	ray.origin = (t_vector){cam.position.x, cam.position.y, cam.position.z};
	ray.direction = normalize((t_vector){
	(w * cam.cos.x + (-h * cam.sin.y - cam.cos.y) * cam.sin.x) * cam.cos.z +
	(h * cam.cos.y - cam.sin.y) * cam.sin.z,
	-(w * cam.cos.x + (-h * cam.sin.y - cam.cos.y) * cam.sin.x) * cam.sin.z +
	(h * cam.cos.y - cam.sin.y) * cam.cos.z,
	-w * cam.sin.x + (-h * cam.sin.y - cam.cos.y) * cam.cos.x});
	return (ray);
}

void		draw(t_main *m)
{
	int			x;
	int			y;
	t_ray		ray;
	t_object	*object;

	y = -1;
	while (++y < WY)
	{
		x = -1;
		while (++x < WX)
		{
			ray = get_ray(x, y, m->camera);
			if (!(object = intersection(&ray, m->objects)))
				continue ;
			m->pixel_color = light(object, ray, m);
			m->lx.arr[(x * 4) + (y * WX * 4) + 2] =
			(char)(m->pixel_color.red * 255);
			m->lx.arr[(x * 4) + (y * WX * 4) + 1] =
			(char)(m->pixel_color.green * 255);
			m->lx.arr[(x * 4) + (y * WX * 4)] =
			(char)(m->pixel_color.blue * 255);
		}
	}
}

void		raytracing(t_main *m)
{
	m->lx.img = mlx_new_image(m->lx.mlx, WX, WY);
	m->lx.arr = mlx_get_data_addr(m->lx.img, &m->lx.b, &m->lx.s, &m->lx.e);
	draw(m);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 0, 0);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	if (m->scene == 1 || m->scene == 2 || m->scene == 3)
		mlx_string_put(m->lx.mlx, m->lx.win, 400, 600, 0xffffff,
					"ON/OFF \"Move mode\" - press [Space]");
	if (m->scene == 1 || m->scene == 2)
		m->scene = m->scene == 1 ? (char)4 : (char)5;
	else if (m->scene == 3)
		m->scene = 6;
	if (m->move_mode)
		hud(m);
}
