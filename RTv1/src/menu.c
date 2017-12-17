/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:23:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 14:20:45 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	menu1(t_main *m)
{
	int		wh[2];

	m->scene = 1;
	m->lx.img = mlx_new_image(m->lx.mlx, WX, WY);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 0, 0);
	mlx_string_put(m->lx.mlx, m->lx.win, 515, 120, 0xffffff, "Viewpoint");
	mlx_string_put(m->lx.mlx, m->lx.win, 185, 470, 0xffffff,
"[1]                                 [2]                                [3]");
	mlx_string_put(m->lx.mlx, m->lx.win, 440, 560, 0xffffff,
"Return, press [Backspace]");
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene11.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 50, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene12.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 400, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene13.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 750, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
}

void	menu2(t_main *m)
{
	int		wh[2];

	m->scene = 2;
	m->lx.img = mlx_new_image(m->lx.mlx, WX, WY);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 0, 0);
	mlx_string_put(m->lx.mlx, m->lx.win, 515, 120, 0xffffff, "Viewpoint");
	mlx_string_put(m->lx.mlx, m->lx.win, 185, 470, 0xffffff,
"[1]                                 [2]                                [3]");
	mlx_string_put(m->lx.mlx, m->lx.win, 440, 560, 0xffffff,
"Return, press [Backspace]");
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene21.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 50, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene22.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 400, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene23.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 750, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
}

void	menu3(t_main *m)
{
	int		wh[2];

	m->scene = 3;
	m->lx.img = mlx_new_image(m->lx.mlx, WX, WY);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 0, 0);
	mlx_string_put(m->lx.mlx, m->lx.win, 515, 120, 0xffffff, "Viewpoint");
	mlx_string_put(m->lx.mlx, m->lx.win, 185, 470, 0xffffff,
"[1]                                 [2]                                [3]");
	mlx_string_put(m->lx.mlx, m->lx.win, 440, 560, 0xffffff,
"Return, press [Backspace]");
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene31.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 50, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene32.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 400, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene33.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 750, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
}

void	menu(t_main *m)
{
	int		wh[2];

	m->scene = 0;
	m->lx.img = mlx_new_image(m->lx.mlx, WX, WY);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 0, 0);
	mlx_string_put(m->lx.mlx, m->lx.win, 500, 120, 0xffffff, "Choose scene");
	mlx_string_put(m->lx.mlx, m->lx.win, 185, 470, 0xffffff,
"[1]                                 [2]                                [3]");
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene1.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 50, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene2.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 400, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
	m->lx.img = mlx_xpm_file_to_image(m->lx.mlx, "menu/scene3.xpm",
									&wh[0], &wh[1]);
	mlx_put_image_to_window(m->lx.mlx, m->lx.win, m->lx.img, 750, 250);
	mlx_destroy_image(m->lx.mlx, m->lx.img);
}
