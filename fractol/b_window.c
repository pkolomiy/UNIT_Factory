/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:53:36 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/04/01 02:30:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		keys(int k, t_v *v)
{
	(k == 53) ? exit(0) : 0;
	(k == 69) ? ship(v, 1) : 0;
	(k == 78) ? ship(v, 2) : 0;
	(k == 123) ? ship(v, 3) : 0;
	(k == 124) ? ship(v, 4) : 0;
	(k == 125) ? ship(v, 5) : 0;
	(k == 126) ? ship(v, 6) : 0;
	(k == 67) ? ship(v, 7) : 0;
	(k == 75) ? ship(v, 8) : 0;
	(k == 49) ? ship(v, 9) : 0;
	(k == 18) ? ship(v, 13) : 0;
	(k == 19) ? ship(v, 14) : 0;
	(k == 20) ? ship(v, 15) : 0;
	(k == 21) ? ship(v, 16) : 0;
	(k == 23) ? ship(v, 17) : 0;
	return (0);
}

int		mouses(int b, int x, int y, t_v *v)
{
	v->x = x - 500;
	v->y = y - 500;
	(x >= 0 && x <= 1000 && y >= 0 && y <= 1000) && b == 4 ?
		ship(v, 10) : 0;
	(x >= 0 && x <= 1000 && y >= 0 && y <= 1000) && b == 5 ?
		ship(v, 11) : 0;
	return (0);
}

void	windows(t_v v)
{
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, 1000, 1000, v.s);
	v.z = 0.4;
	v.i = 60;
	v.v = 0;
	v.f = (int*)malloc(sizeof(int) * 3);
	v.f[0] = 50;
	v.f[1] = 10;
	v.f[2] = 10;
	v.m1 = -0.75;
	v.m2 = -0.5;
	ship(&v, 0);
	mlx_hook(v.win, 2, 5, keys, &v);
	mlx_mouse_hook(v.win, mouses, &v);
	mlx_loop(v.mlx);
}
