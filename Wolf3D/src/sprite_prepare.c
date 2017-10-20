/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_prepare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 23:20:12 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/20 14:50:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	spr_sort(t_var *var)
{
	VAR_INT(gap, var->mvr.num_sprites);
	VAR_INT(swap, 1);
	VAR_INT(i, 0);
	while (swap)
	{
		swap = 0;
		i = 0;
		while (++i < gap)
		{
			if (var->dr.spr_dist[i] - var->dr.spr_dist[i - 1] > 0.1)
			{
				VAR_DBL(c, var->dr.spr_dist[i]);
				var->dr.spr_dist[i] = var->dr.spr_dist[i - 1];
				var->dr.spr_dist[i - 1] = c;
				VAR_INT(t, var->dr.spr_ord[i]);
				var->dr.spr_ord[i] = var->dr.spr_ord[i - 1];
				var->dr.spr_ord[i - 1] = t;
				swap = 1;
			}
		}
	}
}

void				sprite_prepare(t_var *var)
{
	if (var->mvr.num_sprites)
	{
		var->dr.spr_ord = (int*)malloc(sizeof(int) * var->mvr.num_sprites);
		var->dr.spr_dist = (double*)malloc(sizeof(double) *
										var->mvr.num_sprites);
		VAR_INT(i, 0);
		while (i < var->mvr.num_sprites)
		{
			var->dr.spr_ord[i] = i;
			var->dr.spr_dist[i] = ((var->rc.pos_x - var->mvr.sprite[i].x) *
								(var->rc.pos_x - var->mvr.sprite[i].x)) +
				((var->rc.pos_y - var->mvr.sprite[i].y) *
				(var->rc.pos_y - var->mvr.sprite[i].y));
			i++;
		}
		spr_sort(var);
	}
	else
	{
		var->dr.z_buff = 0;
		var->dr.spr_ord = 0;
		var->dr.spr_dist = 0;
	}
}
