/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 22:58:36 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	direction2(t_main *m, int key)
{
	if (key == PG_DN && m->camera.direction.z == 0)
		m->camera.direction.z = -63;
	m->camera.direction.z += key == PG_DN ? 1 : -1;
	if (m->camera.direction.z < -62)
		m->camera.direction.z = 0;
	m->camera.cos.z = cos((double)m->camera.direction.z / 10);
	m->camera.sin.z = sin((double)m->camera.direction.z / 10);
}

void	direction(t_main *m, int key)
{
	if (key == LEFT || key == RIGHT)
	{
		if (key == RIGHT && m->camera.direction.x == 0)
			m->camera.direction.x = 63;
		m->camera.direction.x -= key == RIGHT ? 1 : -1;
		if (m->camera.direction.x > 62)
			m->camera.direction.x = 0;
		m->camera.cos.x = cos((double)m->camera.direction.x / 10);
		m->camera.sin.x = sin((double)m->camera.direction.x / 10);
	}
	else if (key == UP || key == DOWN)
	{
		if (key == DOWN && m->camera.direction.y == 0)
			m->camera.direction.y = -63;
		m->camera.direction.y += key == DOWN ? 1 : -1;
		if (m->camera.direction.y < -62)
			m->camera.direction.y = 0;
		m->camera.cos.y = cos((double)m->camera.direction.y / 10);
		m->camera.sin.y = sin((double)m->camera.direction.y / 10);
	}
	else
		direction2(m, key);
}

void	camera_set(t_main *m, t_vector position, t_int direction)
{
	m->camera.position = position;
	m->camera.direction = direction;
	m->camera.cos.x = cos((double)m->camera.direction.x / 10);
	m->camera.sin.x = sin((double)m->camera.direction.x / 10);
	m->camera.cos.y = cos((double)m->camera.direction.y / 10);
	m->camera.sin.y = sin((double)m->camera.direction.y / 10);
	m->camera.cos.z = cos((double)m->camera.direction.z / 10);
	m->camera.sin.z = sin((double)m->camera.direction.z / 10);
}

void	camera_scene(t_main *m, int key)
{
	if (key == K_1)
		m->scene == 4 ? camera_set(m, POS(0, 30, 40), DIRECTION(0, 0, -8)) : 0;
	if (key == K_1)
		m->scene == 5 ? camera_set(m, POS(210, 0, 285), DIRECTION(4, 0, 0)) : 0;
	if (key == K_1)
		m->scene == 6 ? camera_set(m, POS(-15, 40, 30), DIRECTION(61, -59, 0))
		: 0;
	if (key == K_2)
		m->scene == 4 ? camera_set(m, POS(-28.5, 159.5, -31.5),
								DIRECTION(56, -9, -39)) : 0;
	if (key == K_2)
		m->scene == 5 ? camera_set(m, POS(-235, -5, -300), DIRECTION(38, 0, 0))
		: 0;
	if (key == K_2)
		m->scene == 6 ? camera_set(m, POS(65, 0, 40), DIRECTION(5, 0, 0)) : 0;
	if (key == K_3)
		m->scene == 4 ? camera_set(m, POS(29, 172.5, 33.5),
								DIRECTION(8, -2, -16)) : 0;
	if (key == K_3)
		m->scene == 5 ? camera_set(m, POS(-70, 55, -40), DIRECTION(50, -57, 0))
		: 0;
	if (key == K_3)
		m->scene == 6 ? camera_set(m, POS(5, -9, -16), DIRECTION(0, -1, 0)) : 0;
	raytracing(m);
}

void	camera_change(t_main *m, int key)
{
	if (key == K_W || key == K_A || key == K_S ||
		key == K_D || key == K_Q || key == K_E)
	{
		if (key == K_A || key == K_D)
			m->camera.position.x -= key == K_A ? SPEED : -SPEED;
		else if (key == K_Q || key == K_E)
			m->camera.position.y -= key == K_Q ? SPEED : -SPEED;
		else
			m->camera.position.z -= key == K_W ? SPEED : -SPEED;
	}
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT ||
	key == PG_UP || key == PG_DN)
		direction(m, key);
	raytracing(m);
}
