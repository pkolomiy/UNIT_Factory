/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:03:19 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:36:25 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	free_sprites(t_var *var)
{
	if (var->mvr.num_sprites)
	{
		free(var->dr.z_buff);
		free(var->dr.spr_ord);
		free(var->dr.spr_dist);
		var->dr.z_buff = 0;
		var->dr.spr_ord = 0;
		var->dr.spr_dist = 0;
	}
}

void				raycasting(t_var *var)
{
	var->lbx.img = mlx_new_image(var->lbx.mlx, WIN_X, WIN_Y);
	var->lbx.put = mlx_get_data_addr(var->lbx.img, &var->b, &var->s, &var->e);
	var->x = 0;
	if (var->mvr.num_sprites)
		var->dr.z_buff = (double*)malloc(sizeof(double) * WIN_X);
	while (var->x < WIN_X)
	{
		raycast_prepare(var);
		draw_walls(var);
		if (var->mvr.num_sprites)
			var->dr.z_buff[var->x] = var->sd.perp_wd;
		draw_floor_and_ceiling(var);
		var->x++;
	}
	sprite_prepare(var);
	var->i = 0;
	while (var->i < var->mvr.num_sprites)
	{
		sprite_calculate(var);
		sprite_draw(var);
		var->i++;
	}
	free_sprites(var);
	mlx_put_image_to_window(var->lbx.mlx, var->lbx.win, var->lbx.img, 0, 0);
	mlx_destroy_image(var->lbx.mlx, var->lbx.img);
}
