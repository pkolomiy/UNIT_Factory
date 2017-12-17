/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:27:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/14 23:27:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	moar(t_main *m, t_hud h)
{
	if (!(h.c[4] = (h.y == 12 && h.v == 10) || (h.y == 24 && h.v == 11) ||
	(h.y == 36 && h.v == 12) || (h.y == 48 && h.v == 13) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.y, h.y0 - h.x + 3,
					0xffffff, "o");
	if (!(h.c[5] = (h.y == 12 && h.v == 19) || (h.y == 24 && h.v == 20) ||
	(h.y == 36 && h.v == 21) || (h.y == 48 && h.v == 22) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.x, h.y0 + h.y + 3,
					0xffffff, "o");
	if (!(h.c[6] = (h.y == 12 && h.v == 28) || (h.y == 24 && h.v == 29) ||
	(h.y == 36 && h.v == 30) || (h.y == 48 && h.v == 31) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.y, h.y0 + h.x + 3,
					0xffffff, "o");
	if (!(h.c[7] = (h.y == 12 && h.v == 35) || (h.y == 24 && h.v == 34) ||
	(h.y == 36 && h.v == 33) || (h.y == 48 && h.v == 32) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.x, h.y0 + h.y + 3,
					0xffffff, "o");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.y, h.y0 - h.x, h.c[4], ".");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.x, h.y0 + h.y, h.c[5], ".");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.y, h.y0 + h.x, h.c[6], ".");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.x, h.y0 + h.y, h.c[7], ".");
}

void	put(t_main *m, t_hud h)
{
	if (!(h.c[0] = (!h.y && !h.v) || (h.y == 12 && h.v == 1) ||
	(h.y == 24 && h.v == 2) || (h.y == 36 && h.v == 3) ||
	(h.y == 48 && h.v == 4) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.x, h.y0 - h.y + 3,
					0xffffff, "o");
	if (!(h.c[1] = (!h.y && h.v == 9) || (h.y == 12 && h.v == 8) ||
	(h.y == 24 && h.v == 7) || (h.y == 36 && h.v == 6) ||
	(h.y == 48 && h.v == 5) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.y, h.y0 - h.x + 3,
					0xffffff, "o");
	if (!(h.c[2] = (!h.y && h.v == 18) || (h.y == 12 && h.v == 17) ||
	(h.y == 24 && h.v == 16) || (h.y == 36 && h.v == 15) ||
	(h.y == 48 && h.v == 14) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.x, h.y0 - h.y + 3,
					0xffffff, "o");
	if (!(h.c[3] = (!h.y && h.v == 27) || (h.y == 12 && h.v == 26) ||
	(h.y == 24 && h.v == 25) || (h.y == 36 && h.v == 24) ||
	(h.y == 48 && h.v == 23) ? 0 : 0xffffff))
		mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.y, h.y0 + h.x + 3,
					0xffffff, "o");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.x, h.y0 - h.y, h.c[0], ".");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 + h.y, h.y0 - h.x, h.c[1], ".");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.x, h.y0 - h.y, h.c[2], ".");
	mlx_string_put(m->lx.mlx, m->lx.win, h.x0 - h.y, h.y0 + h.x, h.c[3], ".");
	(h.y) ? moar(m, h) : 0;
}

void	drawcircle(int radius, t_main *m, t_hud h)
{
	h.x = radius - 1;
	h.y = 0;
	h.dx = 1;
	h.dy = 1;
	h.err = h.dx - (radius << 1);
	while (h.x >= h.y)
	{
		if (!(h.y % 12))
			put(m, h);
		if (h.err <= 0)
		{
			h.y += 1;
			h.err += h.dy;
			h.dy += 2;
		}
		if (h.err > 0)
		{
			h.x -= 1;
			h.dx += 2;
			h.err += h.dx - (radius << 1);
		}
	}
}

void	putnbr(t_hud h, t_main *m, int x, int y)
{
	h.dx = -1;
	h.dy = h.v == 9 ? -1 : 1;
	while ((!h.v || h.v == 9 || h.v == 18 || h.v == 27) && ++h.dx < 2)
	{
		mlx_string_put(m->lx.mlx, m->lx.win, h.x + (h.v ? -h.dx : h.dx),
					h.y + h.dy, 0xffffff, h.n);
		mlx_string_put(m->lx.mlx, m->lx.win, h.x + (h.v && h.v != 9 ? -h.dy :
		h.dy), h.y + (h.v == 9 ? -h.dx : h.dx), 0xffffff, h.n);
		h.dy = h.v == 9 ? h.dy - 1 : h.dy + 1;
	}
	mlx_string_put(m->lx.mlx, m->lx.win, x + 85, y + 79, !h.v ? 0 :
	0xffffff, "0");
	mlx_string_put(m->lx.mlx, m->lx.win, x - 5, y - 8, h.v == 9 ? 0 :
	0xffffff, "90");
	mlx_string_put(m->lx.mlx, m->lx.win, x - 107, y + 79, h.v == 18 ? 0 :
	0xffffff, "180");
	mlx_string_put(m->lx.mlx, m->lx.win, x - 10, y + 168, h.v == 27 ? 0 :
	0xffffff, "270");
}

void	compas(t_hud h, t_main *m, int x, int y)
{
	(h.type == X) ? (h.v = (int)(m->camera.direction.x / (63. / 36))) : 0;
	(h.type == Y) ? (h.v = (int)(-m->camera.direction.y / (63. / 36))) : 0;
	(h.type == Z) ? (h.v = (int)(-m->camera.direction.z / (63. / 36))) : 0;
	h.x0 = x;
	h.y0 = y + 75;
	drawcircle(75, m, h);
	if (!h.v || h.v == 18)
	{
		h.x = !h.v ? x + 84 : x - 106;
		h.y = y + 78;
		h.n = !h.v ? "0" : "180";
	}
	else if (h.v == 9 || h.v == 27)
	{
		h.x = h.v == 9 ? x - 4 : x - 9;
		h.y = h.v == 9 ? y - 7 : y + 167;
		h.n = h.v == 9 ? "90" : "270";
	}
	putnbr(h, m, x, y);
	if (h.type == X || h.type == Y)
		h.n = h.type == X ? "X" : "Y";
	else
		h.n = "Z";
	mlx_string_put(m->lx.mlx, m->lx.win, x, y + 75, 0xffffff, h.n);
}
