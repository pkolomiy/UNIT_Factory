/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:29:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 22:53:56 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	main_free(t_main *m)
{
	t_object	*tmp_o;
	t_light		*tmp_l;

	while (m->objects)
	{
		tmp_o = m->objects->next;
		free(m->objects);
		m->objects = tmp_o;
	}
	while (m->lights)
	{
		tmp_l = m->lights->next;
		free(m->lights);
		m->lights = tmp_l;
	}
}

int		key_release(int key, t_main *m)
{
	if (m->move_mode && (key == UP || key == DOWN || key == LEFT ||
	key == RIGHT || key == K_W || key == K_A || key == K_S || key == K_D ||
	key == K_Q || key == K_E || key == PG_UP || key == PG_DN))
	{
		m->lx.key = -1;
		raytracing(m);
	}
	return (0);
}

void	key_press_2(int key, t_main *m)
{
	if (key == K_1 || key == K_2 || key == K_3)
	{
		(m->scene >= 4 && m->scene <= 6) ? camera_scene(m, key) : 0;
		(m->scene == 1) ? scene1(m, key) : 0;
		(m->scene == 2) ? scene2(m, key) : 0;
		(m->scene == 3) ? scene3(m, key) : 0;
		(key == K_1 && !m->scene) ? menu1(m) : 0;
		(key == K_2 && !m->scene) ? menu2(m) : 0;
		(key == K_3 && !m->scene) ? menu3(m) : 0;
	}
	else if (key == BACKSPACE && m->scene)
	{
		main_free(m);
		m->move_mode = 0;
		(m->scene >= 1 && m->scene <= 3) ? menu(m) : 0;
		(m->scene == 4) ? menu1(m) : 0;
		(m->scene == 5) ? menu2(m) : 0;
		(m->scene == 6) ? menu3(m) : 0;
	}
}

int		key_press(int key, t_main *m)
{
	m->lx.key = key;
	if (key == ESC)
		exit(0);
	else if (m->move_mode && (key == UP || key == DOWN || key == LEFT ||
	key == RIGHT || key == K_W || key == K_A || key == K_S || key == K_D ||
	key == K_Q || key == K_E || key == PG_UP || key == PG_DN))
		camera_change(m, key);
	else if (key == ENTER && m->scene > 3)
	{
		camera_set(m, POS(0, 0, 0), DIRECTION(0, 0, 0));
		raytracing(m);
	}
	else if (key == SPACE && m->scene > 3)
	{
		m->move_mode = m->move_mode == 0;
		raytracing(m);
	}
	key_press_2(key, m);
	return (0);
}

int		main(void)
{
	t_main	m;

	m.lx.mlx = mlx_init();
	m.lx.win = mlx_new_window(m.lx.mlx, WX, WY, "rtv1");
	m.move_mode = 0;
	m.objects = NULL;
	m.lights = NULL;
	menu(&m);
	mlx_hook(m.lx.win, 2, 0, key_press, &m);
	mlx_hook(m.lx.win, 3, 0, key_release, &m);
	mlx_hook(m.lx.win, 17, 1L << 17, exit_x, &m);
	mlx_loop(m.lx.mlx);
	return (0);
}
