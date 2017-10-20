/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 23:39:15 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:42:51 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	strafe(t_var *var, char strafe)
{
	if (strafe == K_D)
	{
		var->x = var->rc.pos_x + ((var->rc.plane_x * var->rc.move_speed) * 3);
		var->y = var->rc.pos_y;
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_x += var->rc.plane_x * var->rc.move_speed;
		var->x = var->rc.pos_x;
		var->y = var->rc.pos_y + ((var->rc.plane_y * var->rc.move_speed) * 3);
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_y += var->rc.plane_y * var->rc.move_speed;
	}
	else
	{
		var->x = var->rc.pos_x - ((var->rc.plane_x * var->rc.move_speed) * 3);
		var->y = var->rc.pos_y;
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_x -= var->rc.plane_x * var->rc.move_speed;
		var->x = var->rc.pos_x;
		var->y = var->rc.pos_y - ((var->rc.plane_y * var->rc.move_speed) * 3);
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_y -= var->rc.plane_y * var->rc.move_speed;
	}
}

static inline void	move(t_var *var, char move)
{
	if (move == UP || move == K_W)
	{
		var->x = var->rc.pos_x + ((var->rc.dir_x * var->rc.move_speed) * 3);
		var->y = var->rc.pos_y;
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_x += var->rc.dir_x * var->rc.move_speed;
		var->x = var->rc.pos_x;
		var->y = var->rc.pos_y + ((var->rc.dir_y * var->rc.move_speed) * 3);
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_y += var->rc.dir_y * var->rc.move_speed;
	}
	else
	{
		var->x = var->rc.pos_x - ((var->rc.dir_x * var->rc.move_speed) * 3);
		var->y = var->rc.pos_y;
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_x -= var->rc.dir_x * var->rc.move_speed;
		var->x = var->rc.pos_x;
		var->y = var->rc.pos_y - ((var->rc.dir_y * var->rc.move_speed) * 3);
		if (var->mvr.map[var->y][var->x].wall == 0)
			var->rc.pos_y -= var->rc.dir_y * var->rc.move_speed;
	}
}

static inline void	turn(t_var *var)
{
	VAR_DBL(old_dx, var->rc.dir_x);
	VAR_DBL(old_px, var->rc.plane_x);
	if (!var->mvs.mouse)
	{
		var->rc.rot_speed = (var->mvs.turn[0] == RIGHT) ? 0.05 : -0.05;
		if (var->mvs.turn[1] != -1)
			var->rc.rot_speed = (var->mvs.turn[1] == RIGHT) ? 0.05 : -0.05;
	}
	var->rc.dir_x = old_dx * cos(var->rc.rot_speed) -
		var->rc.dir_y * sin(var->rc.rot_speed);
	var->rc.dir_y = old_dx * sin(var->rc.rot_speed) +
		var->rc.dir_y * cos(var->rc.rot_speed);
	var->rc.plane_x = old_px * cos(var->rc.rot_speed) -
		var->rc.plane_y * sin(var->rc.rot_speed);
	var->rc.plane_y = old_px * sin(var->rc.rot_speed) +
		var->rc.plane_y * cos(var->rc.rot_speed);
}

int					loop(t_var *var)
{
	if (var->mvs.strafe[0] != -1 || var->mvs.move[0] != -1 ||
		var->mvs.turn[0] != -1 || (var->mvs.mouse &&
		(var->mvs.x > (WIN_X / 10) || var->mvs.x < -(WIN_X / 10))))
	{
		if (var->mvs.turn[0] != -1 || (var->mvs.mouse &&
			(var->mvs.x > (WIN_X / 10) || var->mvs.x < -(WIN_X / 10))))
			turn(var);
		if (var->mvs.move[0] != -1)
		{
			if (var->mvs.move[1] != -1)
				move(var, var->mvs.move[1]);
			else
				move(var, var->mvs.move[0]);
		}
		if (var->mvs.strafe[0] != -1)
		{
			if (var->mvs.strafe[1] != -1)
				strafe(var, var->mvs.strafe[1]);
			else
				strafe(var, var->mvs.strafe[0]);
		}
		raycasting(var);
	}
	return (0);
}
