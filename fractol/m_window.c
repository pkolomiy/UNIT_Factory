/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:56:03 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/04/01 02:27:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		keym(int k, t_v *v)
{
	(k == 53) ? exit(0) : 0;
	(k == 69) ? mandelbrot(v, 1) : 0;
	(k == 78) ? mandelbrot(v, 2) : 0;
	(k == 123) ? mandelbrot(v, 3) : 0;
	(k == 124) ? mandelbrot(v, 4) : 0;
	(k == 125) ? mandelbrot(v, 5) : 0;
	(k == 126) ? mandelbrot(v, 6) : 0;
	(k == 67) ? mandelbrot(v, 7) : 0;
	(k == 75) ? mandelbrot(v, 8) : 0;
	(k == 49) ? mandelbrot(v, 9) : 0;
	(k == 18) ? mandelbrot(v, 13) : 0;
	(k == 19) ? mandelbrot(v, 14) : 0;
	(k == 20) ? mandelbrot(v, 15) : 0;
	(k == 21) ? mandelbrot(v, 16) : 0;
	(k == 23) ? mandelbrot(v, 17) : 0;
	return (0);
}

int		mousem(int b, int x, int y, t_v *v)
{
	v->x = x - 500;
	v->y = y - 500;
	(x >= 0 && x <= 1000 && y >= 0 && y <= 1000) && b == 4 ?
		mandelbrot(v, 10) : 0;
	(x >= 0 && x <= 1000 && y >= 0 && y <= 1000) && b == 5 ?
		mandelbrot(v, 11) : 0;
	return (0);
}

void	windowm(t_v v)
{
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, 1000, 1000, v.s);
	v.z = 0.3;
	v.i = 30;
	v.n = 0;
	v.f = (int*)malloc(sizeof(int) * 3);
	v.f[0] = 50;
	v.f[1] = 10;
	v.f[2] = 10;
	v.v = 0;
	v.m1 = -0.5;
	v.m2 = 0;
	mandelbrot(&v, 0);
	mlx_hook(v.win, 2, 5, keym, &v);
	mlx_mouse_hook(v.win, mousem, &v);
	mlx_loop(v.mlx);
}
