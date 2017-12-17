/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:31:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/15 00:31:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		even_moar_rotate(t_hud h, t_main *m)
{
	mlx_string_put(m->lx.mlx, m->lx.win, 892, 665, h.c[0], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 874, 648, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 878, 648, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 874, 674, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 878, 674, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1055, 655, h.c[2], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1055, 660, h.c[2], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1055, 665, h.c[2], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1066, 658, h.c[3], "=");
	mlx_string_put(m->lx.mlx, m->lx.win, 1066, 659, h.c[3], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1066, 666, h.c[3], "v");
	mlx_string_put(m->lx.mlx, m->lx.win, 1077, 655, h.c[2], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1077, 660, h.c[2], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1077, 665, h.c[2], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 1064, 648, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1060, 648, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1064, 674, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1060, 674, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 400, 650, 0xffffff,
		"To reset all to zero, press [Enter]");
	mlx_string_put(m->lx.mlx, m->lx.win, 950, 5, 0xffffff, "Rotate");
	mlx_string_put(m->lx.mlx, m->lx.win, 865, 3, 0xffffff, "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 870, 18, 0xffffff,
				"-----------------------");
}

void		moar_rotate(t_hud h, t_main *m)
{
	mlx_string_put(m->lx.mlx, m->lx.win, 892, 430, h.c[4], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 875, 424, h.c[4], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 878, 424, h.c[4], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 875, 437, h.c[4], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 878, 437, h.c[4], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 1055, 430, h.c[6], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 1066, 429, h.c[7], "v");
	mlx_string_put(m->lx.mlx, m->lx.win, 1077, 430, h.c[6], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 1060, 424, h.c[6], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1063, 424, h.c[6], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 1060, 437, h.c[6], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1063, 437, h.c[6], "-");
	h.c[0] = m->lx.key == PG_UP ? 0xff0000 : 0xffffff;
	h.c[1] = m->lx.key == PG_UP ? 0x0000ff : 0xffffff;
	h.c[2] = m->lx.key == PG_DN ? 0xff0000 : 0xffffff;
	h.c[3] = m->lx.key == PG_DN ? 0x0000ff : 0xffffff;
	mlx_string_put(m->lx.mlx, m->lx.win, 870, 655, h.c[0], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 870, 660, h.c[0], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 870, 665, h.c[0], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 881, 658, h.c[1], "^");
	mlx_string_put(m->lx.mlx, m->lx.win, 881, 660, h.c[1], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 881, 665, h.c[1], "=");
	mlx_string_put(m->lx.mlx, m->lx.win, 892, 655, h.c[0], "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 892, 660, h.c[0], "|");
	even_moar_rotate(h, m);
}

void		rotate(t_hud h, t_main *m)
{
	h.c[0] = m->lx.key == LEFT ? 0xff0000 : 0xffffff;
	h.c[1] = m->lx.key == LEFT ? 0x0000ff : 0xffffff;
	h.c[2] = m->lx.key == RIGHT ? 0xff0000 : 0xffffff;
	h.c[3] = m->lx.key == RIGHT ? 0x0000ff : 0xffffff;
	mlx_string_put(m->lx.mlx, m->lx.win, 870, 205, h.c[0], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 880, 206, h.c[1], "<");
	mlx_string_put(m->lx.mlx, m->lx.win, 892, 205, h.c[0], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 875, 199, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 878, 199, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 875, 212, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 878, 212, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 1055, 205, h.c[2], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 1065, 206, h.c[3], ">");
	mlx_string_put(m->lx.mlx, m->lx.win, 1077, 205, h.c[2], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 1060, 199, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1063, 199, h.c[2], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 1060, 212, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 1063, 212, h.c[2], "-");
	h.c[4] = m->lx.key == UP ? 0xff0000 : 0xffffff;
	h.c[5] = m->lx.key == UP ? 0x0000ff : 0xffffff;
	h.c[6] = m->lx.key == DOWN ? 0xff0000 : 0xffffff;
	h.c[7] = m->lx.key == DOWN ? 0x0000ff : 0xffffff;
	mlx_string_put(m->lx.mlx, m->lx.win, 870, 430, h.c[4], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 881, 433, h.c[5], "^");
	moar_rotate(h, m);
}
