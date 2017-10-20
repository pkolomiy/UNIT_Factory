/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calculate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:40:09 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/01 18:03:37 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sprite_calculate(t_var *var)
{
	var->spr.tr_y = (1.0 / (var->rc.plane_x * var->rc.dir_y - var->rc.dir_x *
							var->rc.plane_y)) * (-var->rc.plane_y *
		(var->mvr.sprite[var->dr.spr_ord[var->i]].x - var->rc.pos_x) +
		var->rc.plane_x * (var->mvr.sprite[var->dr.spr_ord[var->i]].y -
						var->rc.pos_y));
	var->spr.spr_sx = ((WIN_X / 2) * (1 + ((1.0 / (var->rc.plane_x *
		var->rc.dir_y - var->rc.dir_x * var->rc.plane_y)) * (var->rc.dir_y *
		(var->mvr.sprite[var->dr.spr_ord[var->i]].x - var->rc.pos_x) -
		var->rc.dir_x * (var->mvr.sprite[var->dr.spr_ord[var->i]].y -
						var->rc.pos_y))) / var->spr.tr_y));
	var->spr.spr_h = fabs(WIN_Y / var->spr.tr_y);
	var->dir.draw_sy = -var->spr.spr_h / 2 + WIN_Y / 2;
	if (var->dir.draw_sy < 0)
		var->dir.draw_sy = 0;
	var->dir.draw_ey = var->spr.spr_h / 2 + WIN_Y / 2;
	if (var->dir.draw_ey >= WIN_Y)
		var->dir.draw_ey = WIN_Y - 1;
	var->spr.spr_w = fabs(WIN_Y / var->spr.tr_y);
	var->dir.draw_sx = -var->spr.spr_w / 2 + var->spr.spr_sx;
	if (var->dir.draw_sx < 0)
		var->dir.draw_sx = 0;
	var->dir.draw_ex = var->spr.spr_w / 2 + var->spr.spr_sx;
	if (var->dir.draw_ex >= WIN_X)
		var->dir.draw_ex = WIN_X - 1;
}
