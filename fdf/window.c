/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:44:35 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/27 23:44:07 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		key(int k, t_v *v)
{
	(k == 53) ? exit(0) : 0;
	(k == 18) ? draw(v, 1) : 0;
	(k == 19) ? draw(v, 2) : 0;
	(k == 20) ? draw(v, 3) : 0;
	(k == 123 && v->d == 1) ? change(v, 1) : 0;
	(k == 124 && v->d == 1) ? change(v, 2) : 0;
	(k == 125 && v->d == 1) ? change(v, 3) : 0;
	(k == 126 && v->d == 1) ? change(v, 4) : 0;
	(k == 123 && v->d == 2) ? change(v, 5) : 0;
	(k == 124 && v->d == 2) ? change(v, 6) : 0;
	(k == 125 && v->d == 2) ? change(v, 7) : 0;
	(k == 126 && v->d == 2) ? change(v, 8) : 0;
	(k == 123 && v->d == 3) ? change(v, 9) : 0;
	(k == 124 && v->d == 3) ? change(v, 10) : 0;
	(k == 69 && v->d == 3) ? change(v, 11) : 0;
	(k == 78 && v->d == 3) ? change(v, 12) : 0;
	(k == 69 && v->d == 1) ? draw(v, 5) : 0;
	(k == 78 && v->d == 1) ? draw(v, 6) : 0;
	(k == 36) ? draw(v, 4) : 0;
	(k == 83) ? projection(v, 1) : 0;
	(k == 84) ? projection(v, 2) : 0;
	(k == 85) ? change(v, 15) : 0;
	return (0);
}

void	center(t_v *v)
{
	v->a = 0;
	v->b = 0;
	while (v->b < v->st.mapy)
	{
		while (v->a < v->st.mapx)
		{
			X = (X - (v->st.mapx / 2));
			Y = (Y - (v->st.mapy / 2));
			X0 = X;
			Y0 = Y;
			Z0 = Z;
			Z = Z * 0.15;
			v->a++;
		}
		v->a = 0;
		v->b++;
	}
	draw(v, 0);
}

void	window(t_v v)
{
	v.st.mlx = mlx_init();
	v.st.win = mlx_new_window(v.st.mlx, 1000, 1000, v.name);
	v.t = 0;
	v.k = 1;
	v.d = 0;
	center(&v);
	rotx(&v, 5.84);
	roty(&v, 5.84);
	rotz(&v, 0.61);
	mlx_string_put(v.st.mlx, v.st.win, 800, 100, 0xffffff, "Press [Enter]");
	mlx_hook(v.st.win, 2, 5, key, &v);
	mlx_loop(v.st.mlx);
}
