/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:18:09 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/27 22:40:51 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define X v->st.map[v->b][v->a].x
# define Y v->st.map[v->b][v->a].y
# define Z v->st.map[v->b][v->a].z
# define X0 v->st.map[v->b][v->a].x0
# define Y0 v->st.map[v->b][v->a].y0
# define Z0 v->st.map[v->b][v->a].z0
# define VZ v->st.z[v->b][v->a]
# define XN v->st.map[v->b][v->a].xn
# define YN v->st.map[v->b][v->a].yn
# define X_XN_YN v->st.map[v->b][v->a].xn + 500
# define Y_XN_YN v->st.map[v->b][v->a].yn + 500
# define XX_XN_YN v.st.map[v.b][v.a].xn + 500
# define YY_XN_YN v.st.map[v.b][v.a].yn + 500
# define X_XP_YN v->st.map[v->b][v->a + 1].xn + 500
# define Y_XP_YN v->st.map[v->b][v->a + 1].yn + 500
# define X_XN_YP v->st.map[v->b + 1][v->a].xn + 500
# define Y_XN_YP v->st.map[v->b + 1][v->a].yn + 500
# define XX_XP_YN v.st.map[v.b][v.a + 1].xn + 500
# define YY_XP_YN v.st.map[v.b][v.a + 1].yn + 500
# define XX_XN_YP v.st.map[v.b + 1][v.a].xn + 500
# define YY_XN_YP v.st.map[v.b + 1][v.a].yn + 500
# define X_XP_YP v->st.map[v->b + 1][v->a + 1].xn + 500
# define Y_XP_YP v->st.map[v->b + 1][v->a + 1].yn + 500
# define M mlx_string_put
# define V v->st.mlx, v->st.win
# define C1 (v->c > 4000000) || (v->c < 0) || (v->x0 > 999) || (v->x0 < 0)
# define C2 (v->c > 4000000) || (v->c < 0) || (v->x > 999) || (v->x < 0)

typedef unsigned char	t_uc;

typedef struct	s_map
{
	float		x;
	float		x0;
	float		y;
	float		y0;
	float		z;
	float		z0;
	float		xn;
	float		yn;
	t_uc		r;
	t_uc		g;
	t_uc		b;
}				t_map;

typedef struct	s_
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*put;
	int			mapx;
	int			mapy;
	int			maps;
	int			**z;
	t_map		**map;
}				t_st;

typedef struct	s_var
{
	int			a;
	int			b;
	int			c;
	int			d;
	int			e;
	int			f;
	int			t;
	int			k;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			x;
	int			y;
	int			i;
	int			d1;
	int			d2;
	int			d3;
	float		xt;
	float		yt;
	float		zt;
	float		xn;
	float		yn;
	float		zn;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	char		*str;
	char		*name;
	t_st		st;
}				t_v;

void			save_map(t_v v);
void			window(t_v v);
void			change(t_v *v, int n);
void			draw(t_v *v, int n);
void			rotx(t_v *v, float n);
void			roty(t_v *v, float n);
void			rotz(t_v *v, float n);
void			projection(t_v *v, int n);
void			text(t_v *v);

#endif
