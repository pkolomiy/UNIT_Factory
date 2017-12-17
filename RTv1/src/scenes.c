/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 20:28:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 22:53:07 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	scene1(t_main *m, int key)
{
	new(m, sphere(POS(20, 54, -75), COL(0.8, 0.1, 0.1), RAD(6)));
	new(m, sphere(POS(-20, 10, -80), COL(0.8, 0.1, 0.8), RAD(10)));
	new(m, cone(POS(0, 30, -100), DIR(-1, 1, 0), COL(0, 0.5, 0.8),
				RAD(20)));
	new(m, cylinder(POS(10, 0, -100), DIR(0.3, 1, 0), COL(0.8, 0.5, 0),
					RAD(5)));
	new(m, cylinder(POS(-20, 50, -90), DIR(-1, -0.2, 0.1), COL(0.8, 0.7, 0),
					RAD(5)));
	add_light(m, POS(-20, 10, -40));
	add_light(m, POS(20, 80, -50));
	new(m, plane(POS(0, -50, 0), DIR(0, 1, 0), COL(0, 0.1, 0.3)));
	new(m, plane(POS(0, 0, -120), DIR(0, 0, 1), COL(0.2, 0.2, 0.2)));
	new(m, plane(POS(30, 0, 0), DIR(1, 0, 0), COL(0.3, 0.1, 0)));
	new(m, plane(POS(-30, 0, 0), DIR(-1, 0, 0), COL(0.1, 0.3, 0)));
	key == K_1 ? camera_set(m, POS(0, 30, 40), DIRECTION(0, 0, -8)) : 0;
	key == K_2 ? camera_set(m, POS(-28.5, 159.5, -31.5),
							DIRECTION(56, -9, -39)) : 0;
	key == K_3 ? camera_set(m, POS(29, 172.5, 33.5), DIRECTION(8, -2, -16)) : 0;
	raytracing(m);
}

void	scene2_2(t_main *m, int key)
{
	key == K_1 ? camera_set(m, POS(210, 0, 285), DIRECTION(4, 0, 0)) : 0;
	key == K_2 ? camera_set(m, POS(-235, -5, -300), DIRECTION(38, 0, 0)) : 0;
	key == K_3 ? camera_set(m, POS(-70, 55, -40), DIRECTION(50, -57, 0)) : 0;
	raytracing(m);
}

void	scene2(t_main *m, int key)
{
	new(m, cylinder(POS(15, 0, -50), DIR(1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(15, 5, -54), DIR(1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(15, 10, -58), DIR(1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(15, 15, -62), DIR(1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(15, 20, -66), DIR(1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(-15, 0, -52), DIR(-1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(-15, 5, -56), DIR(-1, 1, 0), COL(0.8, 0.5, 0), RAD(1)));
	new(m, cylinder(POS(-15, 10, -60), DIR(-1, 1, 0), COL(0.8, 0.5, 0),
					RAD(1)));
	new(m, cylinder(POS(-15, 15, -64), DIR(-1, 1, 0), COL(0.8, 0.5, 0),
					RAD(1)));
	new(m, cylinder(POS(-15, 20, -68), DIR(-1, 1, 0), COL(0.8, 0.5, 0),
					RAD(1)));
	new(m, sphere(POS(-63, 60, -65), COL(0.8, 0.5, 0), RAD(20)));
	new(m, sphere(POS(63, 60, -60), COL(0.8, 0.5, 0), RAD(20)));
	new(m, sphere(POS(-62, -70, -59), COL(0.8, 0.5, 0), RAD(20)));
	new(m, sphere(POS(62, -70, -64), COL(0.8, 0.5, 0), RAD(20)));
	new(m, plane(POS(0, 60, 0), DIR(0, 1, 0), COL(0.1, 0.3, 0)));
	new(m, plane(POS(0, 0, -300), DIR(0, 0, 1), COL(0.1, 0.1, 0.3)));
	new(m, plane(POS(0, -60, 0), DIR(0, 1, -0.2), COL(0.4, 0.5, 0.4)));
	add_light(m, POS(0, 40, 150));
	add_light(m, POS(0, -50, -150));
	scene2_2(m, key);
}

void	scene3_2(t_main *m, int key)
{
	new(m, sphere(POS(25, 0, -80), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(0, 0, -90), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(10, 0, -90), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-10, 0, -90), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(20, 0, -90), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-20, 0, -90), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(30, 0, -90), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(5, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-5, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(15, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-15, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(25, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-25, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(35, 0, -100), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(0, 0, -110), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(10, 0, -110), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(5, 0, -120), COL(0.73, 0, 0), RAD(3)));
	add_light(m, POS(50, 30, -80));
	add_light(m, POS(-50, 30, -80));
	add_light(m, POS(0, 30, -145));
	add_light(m, POS(0, 30, -25));
	key == K_1 ? camera_set(m, POS(-15, 40, 30), DIRECTION(61, -59, 0)) : 0;
	key == K_2 ? camera_set(m, POS(65, 0, 40), DIRECTION(5, 0, 0)) : 0;
	key == K_3 ? camera_set(m, POS(5, -9, -16), DIRECTION(0, -1, 0)) : 0;
	raytracing(m);
}

void	scene3(t_main *m, int key)
{
	new(m, plane(POS(0, -10, 0), DIR(0, 1, 0), COL(0.1, 0.1, 0.3)));
	new(m, sphere(POS(5, 0, -40), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(0, 0, -50), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(10, 0, -50), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(5, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-5, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(15, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-15, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(25, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-25, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(35, 0, -60), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(0, 0, -70), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(10, 0, -70), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-10, 0, -70), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(20, 0, -70), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-20, 0, -70), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(30, 0, -70), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(5, 0, -80), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-5, 0, -80), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(15, 0, -80), COL(0.73, 0, 0), RAD(3)));
	new(m, sphere(POS(-15, 0, -80), COL(0.73, 0, 0), RAD(3)));
	scene3_2(m, key);
}
