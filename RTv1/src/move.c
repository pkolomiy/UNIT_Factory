/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:44:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/16 22:14:06 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

char	*getnbr(t_hud h)
{
	h.dx = 0;
	while (h.x)
	{
		h.x /= 10;
		h.dx++;
	}
	h.n = (char*)malloc((unsigned)(h.dx + 1));
	h.y = 0;
	while (h.v)
	{
		h.n[h.y] = (char)(48 + (h.v % 10));
		h.v /= 10;
		h.y++;
	}
	h.n[h.y--] = 0;
	while (h.v < h.y)
	{
		h.t = h.n[h.v];
		h.n[h.v++] = h.n[h.y];
		h.n[h.y--] = h.t;
	}
	return (h.n);
}

void	putpos(t_hud h, t_main *m, int y)
{
	if ((h.type == X && (h.v = (int)(m->camera.position.x)) < 0) ||
	(h.type == Y && (h.v = (int)(m->camera.position.y)) < 0) ||
	(h.type == Z && (h.v = (int)(m->camera.position.z)) < 0))
	{
		h.x = h.v;
		h.v = -h.v;
	}
	else
		h.x = h.v;
	h.n = h.v ? getnbr(h) : "0";
	if (h.x < 0)
		mlx_string_put(m->lx.mlx, m->lx.win, 190, y, 0xffffff, "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 200, y, 0xffffff, h.n);
	(h.n[0] != '0') ? free(h.n) : 0;
}

void	even_more_keys(t_hud h, t_main *m)
{
	mlx_string_put(m->lx.mlx, m->lx.win, 105, 167, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 108, 167, h.c[2], "-");
	h.c[0] = m->lx.key == K_W ? 0xff0000 : 0xffffff;
	h.c[1] = m->lx.key == K_W ? 0x0000ff : 0xffffff;
	h.c[2] = m->lx.key == K_S ? 0xff0000 : 0xffffff;
	h.c[3] = m->lx.key == K_S ? 0x0000ff : 0xffffff;
	mlx_string_put(m->lx.mlx, m->lx.win, 25, 260, h.c[0], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 36, 261, h.c[1], "W");
	mlx_string_put(m->lx.mlx, m->lx.win, 47, 260, h.c[0], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 30, 254, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 33, 254, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 30, 267, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 33, 267, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 100, 260, h.c[2], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 111, 261, h.c[3], "S");
	mlx_string_put(m->lx.mlx, m->lx.win, 122, 260, h.c[2], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 105, 254, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 108, 254, h.c[2], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 105, 267, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 108, 267, h.c[2], "-");
}

void	move_keys(t_hud h, t_main *m)
{
	mlx_string_put(m->lx.mlx, m->lx.win, 33, 67, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 100, 60, h.c[2], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 111, 61, h.c[3], "D");
	mlx_string_put(m->lx.mlx, m->lx.win, 122, 60, h.c[2], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 105, 54, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 108, 54, h.c[2], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 105, 67, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 108, 67, h.c[2], "-");
	h.c[0] = m->lx.key == K_Q ? 0xff0000 : 0xffffff;
	h.c[1] = m->lx.key == K_Q ? 0x0000ff : 0xffffff;
	h.c[2] = m->lx.key == K_E ? 0xff0000 : 0xffffff;
	h.c[3] = m->lx.key == K_E ? 0x0000ff : 0xffffff;
	mlx_string_put(m->lx.mlx, m->lx.win, 25, 160, h.c[0], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 36, 161, h.c[1], "Q");
	mlx_string_put(m->lx.mlx, m->lx.win, 47, 160, h.c[0], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 30, 154, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 33, 154, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 30, 167, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 33, 167, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 100, 160, h.c[2], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 111, 161, h.c[3], "E");
	mlx_string_put(m->lx.mlx, m->lx.win, 122, 160, h.c[2], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 105, 154, h.c[2], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 108, 154, h.c[2], "-");
	even_more_keys(h, m);
}

void	move(t_hud h, t_main *m)
{
	mlx_string_put(m->lx.mlx, m->lx.win, 95, 5, 0xffffff, "Move");
	mlx_string_put(m->lx.mlx, m->lx.win, 228, 3, 0xffffff, "|");
	mlx_string_put(m->lx.mlx, m->lx.win, 2, 18, 0xffffff,
				"-----------------------");
	mlx_string_put(m->lx.mlx, m->lx.win, 25, 100, 0xffffff, "Position X");
	mlx_string_put(m->lx.mlx, m->lx.win, 25, 200, 0xffffff, "Position Y");
	mlx_string_put(m->lx.mlx, m->lx.win, 25, 300, 0xffffff, "Position Z");
	h.type = X;
	putpos(h, m, 100);
	h.type = Y;
	putpos(h, m, 200);
	h.type = Z;
	putpos(h, m, 300);
	h.c[0] = m->lx.key == K_A ? 0xff0000 : 0xffffff;
	h.c[1] = m->lx.key == K_A ? 0x0000ff : 0xffffff;
	h.c[2] = m->lx.key == K_D ? 0xff0000 : 0xffffff;
	h.c[3] = m->lx.key == K_D ? 0x0000ff : 0xffffff;
	mlx_string_put(m->lx.mlx, m->lx.win, 25, 60, h.c[0], "[");
	mlx_string_put(m->lx.mlx, m->lx.win, 36, 61, h.c[1], "A");
	mlx_string_put(m->lx.mlx, m->lx.win, 47, 60, h.c[0], "]");
	mlx_string_put(m->lx.mlx, m->lx.win, 30, 54, h.c[0], "--");
	mlx_string_put(m->lx.mlx, m->lx.win, 33, 54, h.c[0], "-");
	mlx_string_put(m->lx.mlx, m->lx.win, 30, 67, h.c[0], "--");
	move_keys(h, m);
}
