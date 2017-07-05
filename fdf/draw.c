/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:39:32 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/27 23:38:50 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	one(t_v *v)
{
	v->d1 = (v->dy << 1) - v->dx;
	v->d2 = v->dy << 1;
	v->d3 = (v->dy - v->dx) << 1;
	v->c = ((v->x0) * 4) + ((v->y0) * 4000);
	C1 ? 0 : (v->st.put[v->c] = v->st.map[v->b][v->a].b);
	C1 ? 0 : (v->st.put[v->c + 1] = v->st.map[v->b][v->a].g);
	C1 ? 0 : (v->st.put[v->c + 2] = v->st.map[v->b][v->a].r);
	v->x = v->x0 + v->sx;
	v->y = v->y0;
	v->i = 1;
	while (v->i <= v->dx)
	{
		(v->d1 > 0) ? (v->y += v->sy) : 0;
		(v->d1 > 0) ? (v->d1 += v->d3) : (v->d1 += v->d2);
		v->c = ((v->x) * 4) + ((v->y) * 4000);
		C2 ? 0 : (v->st.put[v->c] = v->st.map[v->b][v->a].b);
		C2 ? 0 : (v->st.put[v->c + 1] = v->st.map[v->b][v->a].g);
		C2 ? 0 : (v->st.put[v->c + 2] = v->st.map[v->b][v->a].r);
		v->i++;
		v->x += v->sx;
	}
}

void	two(t_v *v)
{
	v->d1 = (v->dx << 1) - v->dy;
	v->d2 = v->dx << 1;
	v->d3 = (v->dx - v->dy) << 1;
	v->c = ((v->x0) * 4) + ((v->y0) * 4000);
	C1 ? 0 : (v->st.put[v->c] = v->st.map[v->b][v->a].b);
	C1 ? 0 : (v->st.put[v->c + 1] = v->st.map[v->b][v->a].g);
	C1 ? 0 : (v->st.put[v->c + 2] = v->st.map[v->b][v->a].r);
	v->y = v->y0 + v->sy;
	v->x = v->x0;
	v->i = 1;
	while (v->i <= v->dy)
	{
		(v->d1 > 0) ? (v->x += v->sx) : 0;
		(v->d1 > 0) ? (v->d1 += v->d3) : (v->d1 += v->d2);
		v->c = ((v->x) * 4) + ((v->y) * 4000);
		C2 ? 0 : (v->st.put[v->c] = v->st.map[v->b][v->a].b);
		C2 ? 0 : (v->st.put[v->c + 1] = v->st.map[v->b][v->a].g);
		C2 ? 0 : (v->st.put[v->c + 2] = v->st.map[v->b][v->a].r);
		v->i++;
		v->y += v->sy;
	}
}

void	line(t_v *v, int n)
{
	v->x0 = X_XN_YN;
	v->y0 = Y_XN_YN;
	!n ? (v->x1 = X_XP_YN) : 0;
	!n ? (v->y1 = Y_XP_YN) : 0;
	n ? (v->x1 = X_XN_YP) : 0;
	n ? (v->y1 = Y_XN_YP) : 0;
	v->dx = abs(v->x1 - v->x0);
	v->dy = abs(v->y1 - v->y0);
	v->sx = v->x1 >= v->x0 ? 1 : -1;
	v->sy = v->y1 >= v->y0 ? 1 : -1;
	(v->dy <= v->dx) ? one(v) : two(v);
}

void	draw(t_v *v, int n)
{
	(n == 1) ? (v->d = 1) : 0;
	(n == 2) ? (v->d = 2) : 0;
	(n == 3) ? (v->d = 3) : 0;
	(n == 4) ? (v->t++) : 0;
	v->st.img = mlx_new_image(v->st.mlx, 1000, 1000);
	v->st.put = mlx_get_data_addr(v->st.img, &v->a, &v->b, &v->c);
	v->a = -1;
	v->b = -1;
	while (++v->b < v->st.mapy)
	{
		while (++v->a < v->st.mapx)
		{
			(v->a != v->st.mapx - 1) ? line(v, 0) : 0;
			(v->b != v->st.mapy - 1) ? line(v, 1) : 0;
		}
		v->a = -1;
	}
	mlx_put_image_to_window(v->st.mlx, v->st.win, v->st.img, 0, 0);
	mlx_destroy_image(v->st.mlx, v->st.img);
	(n == 5 && v->k < 99) ? (v->k++) : 0;
	(n == 6 && v->k > 1) ? (v->k--) : 0;
	(v->t > 1) ? (v->t = 0) : 0;
	(v->t == 1) ? text(v) : 0;
}
