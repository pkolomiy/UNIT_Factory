/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 23:05:47 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:42:15 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press(int key, t_var *var)
{
	if (key == ESC)
		exit(1);
	if ((key == RIGHT || key == LEFT) && var->mvs.turn[1] == -1)
	{
		(var->mvs.turn[0] == -1) ? (var->mvs.turn[0] = key) : 0;
		(var->mvs.turn[0] != key) ? (var->mvs.turn[1] = key) : 0;
	}
	if ((key == K_W || key == UP || key == K_S || key == DOWN) &&
		var->mvs.move[1] == -1)
	{
		(var->mvs.move[0] == -1) ? (var->mvs.move[0] = key) : 0;
		(var->mvs.move[0] != key) ? (var->mvs.move[1] = key) : 0;
	}
	if ((key == K_D || key == K_A) && var->mvs.strafe[1] == -1)
	{
		(var->mvs.strafe[0] == -1) ? (var->mvs.strafe[0] = key) : 0;
		(var->mvs.strafe[0] != key) ? (var->mvs.strafe[1] = key) : 0;
	}
	if (key == LSHIFT)
		var->rc.move_speed = 0.2;
	return (0);
}

int		key_release(int key, t_var *var)
{
	if (key == RIGHT || key == LEFT)
	{
		if (var->mvs.turn[0] == key)
			var->mvs.turn[0] = var->mvs.turn[1];
		var->mvs.turn[1] = -1;
	}
	if (key == K_W || key == UP || key == K_S || key == DOWN)
	{
		if (var->mvs.move[0] == key)
			var->mvs.move[0] = var->mvs.move[1];
		var->mvs.move[1] = -1;
	}
	if (key == K_D || key == K_A)
	{
		if (var->mvs.strafe[0] == key)
			var->mvs.strafe[0] = var->mvs.strafe[1];
		var->mvs.strafe[1] = -1;
	}
	if (key == LSHIFT)
		var->rc.move_speed = 0.1;
	return (0);
}

int		mouse_look(int x, int y, t_var *var)
{
	(void)y;
	var->mvs.x = x - WIN_X / 2;
	var->rc.rot_speed = 0.03 * var->mvs.x / 100 / 3;
	return (0);
}

int		mouse_press(int button, int x, int y, t_var *var)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		var->rc.rot_speed = 0.05;
		var->mvs.x = 0;
		var->mvs.mouse--;
	}
	return (0);
}
