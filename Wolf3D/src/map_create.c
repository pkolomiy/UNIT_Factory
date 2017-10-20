/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:27:49 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:35:25 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	sprite_validation(t_var *var, _Bool arr[])
{
	VAR_INT(i, 0);
	VAR_INT(j, 0);
	if (arr[5])
		var->i++;
	if ((arr[4] && arr[6]) || (arr[5] && arr[6]) || var->i > 1)
		put_error("Sprites position error\n", 0);
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (arr[i] && arr[j] && i != j)
				put_error("Sprites position error\n", 0);
			j++;
		}
		i++;
	}
}

static inline void	one_more_validation(t_var *var, t_mvar *mvr)
{
	_Bool	arr[7];

	var->y = 0;
	while (var->y < mvr->map_height)
	{
		var->x = 0;
		while (var->x < mvr->map_width)
		{
			arr[0] = mvr->map[var->y][var->x].barrel;
			arr[1] = mvr->map[var->y][var->x].cat;
			arr[2] = mvr->map[var->y][var->x].dog;
			arr[3] = mvr->map[var->y][var->x].sprite;
			arr[4] = mvr->map[var->y][var->x].florin;
			arr[5] = mvr->map[var->y][var->x].player;
			arr[6] = mvr->map[var->y][var->x].lamp;
			sprite_validation(var, arr);
			var->x++;
		}
		var->y++;
	}
	if (!var->i)
		put_error("No player\n", 0);
}

static inline void	fill_cell(t_var *var, t_mvar *mvr, char symbol)
{
	char	cell;

	if (var->str[var->i] == ',')
		var->i++;
	cell = var->str[var->i];
	if (((cell >= '0' && cell <= '2') || cell == ' ' || cell == '\n') &&
		symbol == ',')
		put_error("Invalid map at:\n", var->str + var->i - 1);
	if (cell == 'b' || cell == 'c' || cell == 'd' || cell == 'f' ||
		cell == 'l' || cell == 's')
		mvr->num_sprites++;
	dublicate_check(cell, var, mvr);
	(cell == '0') ? (mvr->map[var->y][var->x].wall = 0) : 0;
	(cell == '1') ? (mvr->map[var->y][var->x].wall = 1) : 0;
	(cell == '2') ? (mvr->map[var->y][var->x].wall = 2) : 0;
	(cell == 'b') ? (mvr->map[var->y][var->x].barrel = 1) : 0;
	(cell == 'c') ? (mvr->map[var->y][var->x].cat = 1) : 0;
	(cell == 'd') ? (mvr->map[var->y][var->x].dog = 1) : 0;
	(cell == 'f') ? (mvr->map[var->y][var->x].florin = 1) : 0;
	(cell == 'l') ? (mvr->map[var->y][var->x].lamp = 1) : 0;
	(cell == 's') ? (mvr->map[var->y][var->x].sprite = 1) : 0;
	(cell == 'p') ? (mvr->map[var->y][var->x].player = 1) : 0;
	var->i++;
}

static inline void	cell_validation(t_var *var, t_mvar *mvr)
{
	while (var->str[var->i] == ' ')
		var->i++;
	if (var->str[var->i] == ',')
		put_error("Invalid map at:\n", var->str + var->i);
	mvr->map[var->y][var->x].x = var->x;
	mvr->map[var->y][var->x].y = var->y;
	mvr->map[var->y][var->x].wall = 0;
	mvr->map[var->y][var->x].barrel = 0;
	mvr->map[var->y][var->x].cat = 0;
	mvr->map[var->y][var->x].dog = 0;
	mvr->map[var->y][var->x].florin = 0;
	mvr->map[var->y][var->x].lamp = 0;
	mvr->map[var->y][var->x].sprite = 0;
	mvr->map[var->y][var->x].player = 0;
	fill_cell(var, mvr, var->str[var->i]);
	if (var->str[var->i] == ',' &&
		!(var->str[var->i - 1] >= '0' && var->str[var->i - 1] <= '2'))
		fill_cell(var, mvr, var->str[var->i]);
	if (var->str[var->i] == ',')
		put_error("Invalid map at:\n", var->str + var->i);
}

void				get_map(t_var *var, t_mvar *mvr)
{
	var->i = 0;
	var->y = 0;
	mvr->num_sprites = 0;
	mvr->map = (t_map**)malloc(sizeof(t_map*) * mvr->map_height);
	while (var->str[var->i])
	{
		var->x = 0;
		mvr->map[var->y] = (t_map*)malloc(sizeof(t_map) * mvr->map_width);
		while (var->str[var->i] != '\n' && var->str[var->i])
		{
			cell_validation(var, mvr);
			if (var->str[var->i] != ' ' && var->str[var->i] != '\n' &&
				var->str[var->i])
				put_error("Invalid map at:\n", var->str + var->i);
			var->x++;
		}
		var->y++;
		if (var->str[var->i])
			var->i++;
	}
	var->i = 0;
	one_more_validation(var, mvr);
}
