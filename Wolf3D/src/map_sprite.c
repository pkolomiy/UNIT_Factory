/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:50:47 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:34:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				dublicate_check(char cell, t_var *var, t_mvar *mvr)
{
	if ((cell == '1' && mvr->map[var->y][var->x].wall == 1) ||
		(cell == '2' && mvr->map[var->y][var->x].wall == 2) ||
		(cell == 'b' && mvr->map[var->y][var->x].barrel) ||
		(cell == 'c' && mvr->map[var->y][var->x].cat) ||
		(cell == 'd' && mvr->map[var->y][var->x].dog) ||
		(cell == 'f' && mvr->map[var->y][var->x].florin) ||
		(cell == 'l' && mvr->map[var->y][var->x].lamp) ||
		(cell == 's' && mvr->map[var->y][var->x].sprite) ||
		(cell == 'p' && mvr->map[var->y][var->x].player))
		put_error("Sprites dublicate error\n", 0);
}

static inline void	sprite_fill(t_var *var, t_mvar *mvr)
{
	_Bool	arr[6];

	VAR_INT(i, 0);
	arr[0] = mvr->map[var->y][var->x].barrel;
	arr[1] = mvr->map[var->y][var->x].cat;
	arr[2] = mvr->map[var->y][var->x].dog;
	arr[3] = mvr->map[var->y][var->x].sprite;
	arr[4] = mvr->map[var->y][var->x].florin;
	arr[5] = mvr->map[var->y][var->x].lamp;
	while (i < 6)
	{
		if (arr[i])
		{
			mvr->sprite[var->i].x = (double)var->x + 0.5;
			mvr->sprite[var->i].y = (double)var->y + 0.5;
			(i == 0) ? (mvr->sprite[var->i].type = 'b') : 0;
			(i == 1) ? (mvr->sprite[var->i].type = 'c') : 0;
			(i == 2) ? (mvr->sprite[var->i].type = 'd') : 0;
			(i == 3) ? (mvr->sprite[var->i].type = 's') : 0;
			(i == 4) ? (mvr->sprite[var->i].type = 'f') : 0;
			(i == 5) ? (mvr->sprite[var->i].type = 'l') : 0;
			var->i++;
		}
		i++;
	}
}

static inline void	final_map_validation(t_mvar *mvr)
{
	VAR_INT(x, 0);
	VAR_INT(y, 0);
	while (y < mvr->map_height)
	{
		x = 0;
		while (x < mvr->map_width)
		{
			if ((x == 0 || y == 0 || x == mvr->map_width - 1 ||
				y == mvr->map_height - 1) && !mvr->map[y][x].wall)
				put_error("Map incomplete\n", 0);
			x++;
		}
		y++;
	}
}

void				create_sprite_map(t_var *var, t_mvar *mvr)
{
	var->i = 0;
	var->y = 0;
	mvr->sprite = (t_sprite*)malloc(sizeof(t_sprite) * mvr->num_sprites);
	while (var->y < mvr->map_height)
	{
		var->x = 0;
		while (var->x < mvr->map_width)
		{
			if (mvr->map[var->y][var->x].player)
			{
				var->rc.pos_x = (double)var->x + 0.5;
				var->rc.pos_y = (double)var->y + 0.5;
			}
			sprite_fill(var, mvr);
			var->x++;
		}
		var->y++;
	}
	final_map_validation(mvr);
}
