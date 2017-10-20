/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:00:23 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:39:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	more_textures(t_var *var)
{
	if (var->mvr.sprite[var->dr.spr_ord[var->i]].type == 'f')
	{
		var->spr.red = var->tex.florin[var->b + 2];
		var->spr.green = var->tex.florin[var->b + 1];
		var->spr.blue = var->tex.florin[var->b];
	}
	else if (var->mvr.sprite[var->dr.spr_ord[var->i]].type == 'l')
	{
		var->spr.red = var->tex.lamp[var->b + 2];
		var->spr.green = var->tex.lamp[var->b + 1];
		var->spr.blue = var->tex.lamp[var->b];
	}
	else
	{
		var->spr.red = var->tex.sprite[var->b + 2];
		var->spr.green = var->tex.sprite[var->b + 1];
		var->spr.blue = var->tex.sprite[var->b];
	}
}

static inline void	choose_texture(t_var *var)
{
	var->b = (350 * ((((var->y * 256 - WIN_Y * 128 + var->spr.spr_h * 128) *
					350) / var->spr.spr_h) / 256) + var->dir.tex_x) * 4;
	var->s = (var->x * 4) + (var->y * ((WIN_X) * 4));
	if (var->mvr.sprite[var->dr.spr_ord[var->i]].type == 'b')
	{
		var->spr.red = var->tex.barrel[var->b + 2];
		var->spr.green = var->tex.barrel[var->b + 1];
		var->spr.blue = var->tex.barrel[var->b];
	}
	else if (var->mvr.sprite[var->dr.spr_ord[var->i]].type == 'c')
	{
		var->spr.red = var->tex.cat[var->b + 2];
		var->spr.green = var->tex.cat[var->b + 1];
		var->spr.blue = var->tex.cat[var->b];
	}
	else if (var->mvr.sprite[var->dr.spr_ord[var->i]].type == 'd')
	{
		var->spr.red = var->tex.dog[var->b + 2];
		var->spr.green = var->tex.dog[var->b + 1];
		var->spr.blue = var->tex.dog[var->b];
	}
	else
		more_textures(var);
}

void				sprite_draw(t_var *var)
{
	var->x = var->dir.draw_sx;
	while (var->x < var->dir.draw_ex)
	{
		var->dir.tex_x = (256 * (var->x - (-var->spr.spr_w / 2 +
			var->spr.spr_sx)) * 350 / var->spr.spr_w) / 256;
		if (var->spr.tr_y > 0 && var->x > 0 && var->x < WIN_X &&
			var->spr.tr_y < var->dr.z_buff[var->x])
		{
			var->y = var->dir.draw_sy;
			while (var->y < var->dir.draw_ey)
			{
				choose_texture(var);
				if (var->spr.green)
				{
					var->lbx.put[var->s + 2] = var->spr.red;
					var->lbx.put[var->s + 1] = var->spr.green;
					var->lbx.put[var->s] = var->spr.blue;
				}
				var->y++;
			}
		}
		var->x++;
	}
}
