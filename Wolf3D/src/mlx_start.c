/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:33:46 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/08 18:20:23 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline int	exit_x(void *ptr)
{
	ptr = NULL;
	exit(1);
	return (0);
}

static inline void	textures_name(char *arr[])
{
	arr[0] = "xpm/textures/wood.xpm";
	arr[1] = "xpm/textures/brick.xpm";
	arr[2] = "xpm/textures/ceiling.xpm";
	arr[3] = "xpm/textures/floor.xpm";
	arr[4] = "xpm/sprites/barrel.xpm";
	arr[5] = "xpm/sprites/lamp.xpm";
	arr[6] = "xpm/sprites/cat.xpm";
	arr[7] = "xpm/sprites/dog.xpm";
	arr[8] = "xpm/sprites/florin.xpm";
	arr[9] = "xpm/sprites/sprite.xpm";
}

static inline void	load_textures(t_var *var)
{
	void	*img[10];
	char	*arr[10];

	VAR_INT(i, -1);
	textures_name(arr);
	while (++i < 10)
		img[i] = mlx_xpm_file_to_image(var->lbx.mlx, arr[i], &var->b, &var->s);
	var->tex.wood = mlx_get_data_addr(img[0], &var->b, &var->s, &var->e);
	var->tex.brick = mlx_get_data_addr(img[1], &var->b, &var->s, &var->e);
	var->tex.ceiling = mlx_get_data_addr(img[2], &var->b, &var->s, &var->e);
	var->tex.floor = mlx_get_data_addr(img[3], &var->b, &var->s, &var->e);
	var->tex.barrel = mlx_get_data_addr(img[4], &var->b, &var->s, &var->e);
	var->tex.lamp = mlx_get_data_addr(img[5], &var->b, &var->s, &var->e);
	var->tex.cat = mlx_get_data_addr(img[6], &var->b, &var->s, &var->e);
	var->tex.dog = mlx_get_data_addr(img[7], &var->b, &var->s, &var->e);
	var->tex.florin = mlx_get_data_addr(img[8], &var->b, &var->s, &var->e);
	var->tex.sprite = mlx_get_data_addr(img[9], &var->b, &var->s, &var->e);
}

static inline void	mlx_start(t_var var)
{
	var.lbx.mlx = mlx_init();
	var.lbx.win = mlx_new_window(var.lbx.mlx, WIN_X, WIN_Y, "wolf3d");
	load_textures(&var);
	raycasting(&var);
	mlx_hook(var.lbx.win, 17, 1L << 17, exit_x, &var);
	mlx_hook(var.lbx.win, 2, 1, key_press, &var);
	mlx_hook(var.lbx.win, 3, 2, key_release, &var);
	mlx_hook(var.lbx.win, 6, 64, mouse_look, &var);
	mlx_mouse_hook(var.lbx.win, mouse_press, &var);
	mlx_loop_hook(var.lbx.mlx, loop, &var);
	mlx_loop(var.lbx.mlx);
}

void				fill_var(t_var var)
{
	var.rc.dir_x = 1.0;
	var.rc.dir_y = 0;
	var.rc.plane_x = 0;
	var.rc.plane_y = 0.66;
	var.rc.move_speed = 0.1;
	var.rc.rot_speed = 0.05;
	var.mvs.x = 0;
	var.mvs.turn[0] = -1;
	var.mvs.move[0] = -1;
	var.mvs.strafe[0] = -1;
	var.mvs.turn[1] = -1;
	var.mvs.move[1] = -1;
	var.mvs.strafe[1] = -1;
	var.mvs.mouse = 0;
	mlx_start(var);
}
