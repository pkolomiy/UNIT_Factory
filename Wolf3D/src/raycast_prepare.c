/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 23:42:46 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:37:05 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	more_calculations(t_var *var)
{
	var->dir.line_h = WIN_Y / var->sd.perp_wd;
	var->dir.draw_sx = -var->dir.line_h / 2 + WIN_Y / 2;
	if (var->dir.draw_sx < 0)
		var->dir.draw_sx = 0;
	var->dir.draw_ex = var->dir.line_h / 2 + WIN_Y / 2;
	if (var->dir.draw_ex >= WIN_Y)
		var->dir.draw_ex = WIN_Y - 1;
	var->dir.wall_x = (!var->sd.side) ?
		(var->rc.pos_y + var->sd.perp_wd * var->sd.ray_dy) :
		(var->rc.pos_x + var->sd.perp_wd * var->sd.ray_dx);
	var->dir.wall_x -= (int)var->dir.wall_x;
	var->dir.tex_x = var->dir.wall_x * 350;
	if ((!var->sd.side && var->sd.ray_dx > 0) ||
		(var->sd.side == 1 && var->sd.ray_dy < 0))
		var->dir.tex_x = 350 - var->dir.tex_x - 1;
}

static inline void	continue_preparation(t_var *var)
{
	while (!var->sd.hit)
	{
		if (var->sd.side_dx < var->sd.side_dy)
		{
			var->sd.side_dx += var->sd.delta_x;
			var->sd.map_x += var->sd.step_x;
			var->sd.side = 0;
		}
		else
		{
			var->sd.side_dy += var->sd.delta_y;
			var->sd.map_y += var->sd.step_y;
			var->sd.side = 1;
		}
		if (var->mvr.map[var->sd.map_y][var->sd.map_x].wall > 0)
			var->sd.hit = 1;
	}
	if (!var->sd.side)
		var->sd.perp_wd = (var->sd.map_x - var->rc.pos_x +
						(1 - var->sd.step_x) / 2) / var->sd.ray_dx;
	else
		var->sd.perp_wd = (var->sd.map_y - var->rc.pos_y +
						(1 - var->sd.step_y) / 2) / var->sd.ray_dy;
	more_calculations(var);
}

void				raycast_prepare(t_var *var)
{
	var->sd.ray_dx = var->rc.dir_x + var->rc.plane_x *
		(((2 * var->x) / (double)WIN_X) - 1);
	var->sd.ray_dy = var->rc.dir_y + var->rc.plane_y *
		(((2 * var->x) / (double)WIN_X) - 1);
	var->sd.map_x = var->rc.pos_x;
	var->sd.map_y = var->rc.pos_y;
	var->sd.delta_x = sqrt(1 + (var->sd.ray_dy * var->sd.ray_dy) /
							(var->sd.ray_dx * var->sd.ray_dx));
	var->sd.delta_y = sqrt(1 + (var->sd.ray_dx * var->sd.ray_dx) /
							(var->sd.ray_dy * var->sd.ray_dy));
	var->sd.hit = 0;
	var->sd.step_x = (var->sd.ray_dx < 0) ? -1 : 1;
	var->sd.step_y = (var->sd.ray_dy < 0) ? -1 : 1;
	if (var->sd.ray_dx < 0)
		var->sd.side_dx = (var->rc.pos_x - var->sd.map_x) * var->sd.delta_x;
	else
		var->sd.side_dx = (var->sd.map_x + 1.0 - var->rc.pos_x) *
			var->sd.delta_x;
	if (var->sd.ray_dy < 0)
		var->sd.side_dy = (var->rc.pos_y - var->sd.map_y) * var->sd.delta_y;
	else
		var->sd.side_dy = (var->sd.map_y + 1.0 - var->rc.pos_y) *
			var->sd.delta_y;
	continue_preparation(var);
}
