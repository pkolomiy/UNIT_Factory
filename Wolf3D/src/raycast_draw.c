/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:17:40 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:38:02 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	prepare_floor(t_var *var)
{
	if (!var->sd.side && var->sd.ray_dx > 0)
	{
		var->dir.floor_x = var->sd.map_x;
		var->dir.floor_y = var->sd.map_y + var->dir.wall_x;
	}
	else if (!var->sd.side && var->sd.ray_dx < 0)
	{
		var->dir.floor_x = var->sd.map_x + 1.0;
		var->dir.floor_y = var->sd.map_y + var->dir.wall_x;
	}
	else if (var->sd.side == 1 && var->sd.ray_dy > 0)
	{
		var->dir.floor_x = var->sd.map_x + var->dir.wall_x;
		var->dir.floor_y = var->sd.map_y;
	}
	else
	{
		var->dir.floor_x = var->sd.map_x + var->dir.wall_x;
		var->dir.floor_y = var->sd.map_y + 1.0;
	}
	if (var->dir.draw_ex < 0)
		var->dir.draw_ex = WIN_Y;
}

static inline void	fill_put2(t_var *var)
{
	var->lbx.put[var->s + 2] = var->tex.floor[var->b + 2];
	var->lbx.put[var->s + 1] = var->tex.floor[var->b + 1];
	var->lbx.put[var->s] = var->tex.floor[var->b];
	var->s = (var->x * 4) + ((WIN_Y - var->y) * ((WIN_X) * 4));
	var->lbx.put[var->s + 2] = var->tex.ceiling[var->b + 2];
	var->lbx.put[var->s + 1] = var->tex.ceiling[var->b + 1];
	var->lbx.put[var->s] = var->tex.ceiling[var->b];
}

void				draw_floor_and_ceiling(t_var *var)
{
	prepare_floor(var);
	var->y = var->dir.draw_ex;
	while (var->y < WIN_Y)
	{
		var->dir.cur_dist = WIN_Y / (2.0 * var->y - WIN_Y);
		var->dir.cur_fx = (var->dir.cur_dist / var->sd.perp_wd) *
			var->dir.floor_x + (1.0 - (var->dir.cur_dist / var->sd.perp_wd)) *
			var->rc.pos_x;
		var->dir.cur_fy = (var->dir.cur_dist / var->sd.perp_wd) *
			var->dir.floor_y + (1.0 - (var->dir.cur_dist / var->sd.perp_wd)) *
			var->rc.pos_y;
		var->dir.ftx = (int)(var->dir.cur_fx * 350) % 350;
		var->dir.fty = (int)(var->dir.cur_fy * 350) % 350;
		var->b = (350 * var->dir.fty + var->dir.ftx) * 4;
		var->s = (var->x * 4) + (var->y * ((WIN_X) * 4));
		fill_put2(var);
		var->y++;
	}
}

static inline void	fill_put(t_var *var)
{
	if (var->mvr.map[var->sd.map_y][var->sd.map_x].wall == 1)
	{
		var->lbx.put[var->s + 2] = (var->sd.side) ?
			(unsigned char)var->tex.wood[var->b + 2] / 1.5 :
			var->tex.wood[var->b + 2];
		var->lbx.put[var->s + 1] = (var->sd.side) ?
			(unsigned char)var->tex.wood[var->b + 1] / 1.5 :
			var->tex.wood[var->b + 1];
		var->lbx.put[var->s] = (var->sd.side) ?
			(unsigned char)var->tex.wood[var->b] / 1.5 :
			var->tex.wood[var->b];
	}
	else
	{
		var->lbx.put[var->s + 2] = (var->sd.side) ?
			(unsigned char)var->tex.brick[var->b + 2] / 1.5 :
			var->tex.brick[var->b + 2];
		var->lbx.put[var->s + 1] = (var->sd.side) ?
			(unsigned char)var->tex.brick[var->b + 1] / 1.5 :
			var->tex.brick[var->b + 1];
		var->lbx.put[var->s] = (var->sd.side) ?
			(unsigned char)var->tex.brick[var->b] / 1.5 :
			var->tex.brick[var->b];
	}
}

void				draw_walls(t_var *var)
{
	var->y = var->dir.draw_sx;
	while (var->y < var->dir.draw_ex)
	{
		var->dir.tex_y = (((var->y * 256 - WIN_Y * 128 + var->dir.line_h *
							128) * 350) / var->dir.line_h) / 256;
		var->b = ((350 * var->dir.tex_y) + var->dir.tex_x) * 4;
		var->s = (var->x * 4) + (var->y * ((WIN_X) * 4));
		fill_put(var);
		var->y++;
	}
}
