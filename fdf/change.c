/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:43:36 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/27 22:39:54 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	rotx(t_v *v, float n)
{
	v->a = 0;
	v->b = 0;
	(v->st.mapx > v->st.mapy) ? (v->c = 800 / v->st.mapx) :
		(v->c = 800 / v->st.mapy);
	while (v->b < v->st.mapy)
	{
		while (v->a < v->st.mapx)
		{
			v->yt = Y;
			v->zt = Z;
			Y = v->yt * cos(n) + v->zt * sin(n);
			Z = v->zt * cos(n) - v->yt * sin(n);
			!n ? (X = X0) : 0;
			!n ? (Y = Y0) : 0;
			!n ? (Z = Z0) : 0;
			XN = X * v->c;
			YN = Y * v->c;
			v->a++;
		}
		v->a = 0;
		v->b++;
	}
	draw(v, 0);
}

void	roty(t_v *v, float n)
{
	v->a = 0;
	v->b = 0;
	(v->st.mapx > v->st.mapy) ? (v->c = 800 / v->st.mapx) :
		(v->c = 800 / v->st.mapy);
	while (v->b < v->st.mapy)
	{
		while (v->a < v->st.mapx)
		{
			v->xt = X;
			v->zt = Z;
			X = v->xt * cos(n) + v->zt * sin(n);
			Z = v->zt * cos(n) - v->xt * sin(n);
			XN = X * v->c;
			YN = Y * v->c;
			v->a++;
		}
		v->a = 0;
		v->b++;
	}
	draw(v, 0);
}

void	rotz(t_v *v, float n)
{
	v->a = 0;
	v->b = 0;
	(v->st.mapx > v->st.mapy) ? (v->c = 800 / v->st.mapx) :
		(v->c = 800 / v->st.mapy);
	while (v->b < v->st.mapy)
	{
		while (v->a < v->st.mapx)
		{
			v->xt = X;
			v->yt = Y;
			X = v->xt * cos(n) - v->yt * sin(n);
			Y = v->xt * sin(n) + v->yt * cos(n);
			XN = X * v->c;
			YN = Y * v->c;
			v->a++;
		}
		v->a = 0;
		v->b++;
	}
	draw(v, 0);
}

void	move(t_v *v, int n)
{
	v->a = 0;
	v->b = 0;
	(v->st.mapx > v->st.mapy) ? (v->c = 800 / v->st.mapx) :
		(v->c = 800 / v->st.mapy);
	while (v->b < v->st.mapy)
	{
		while (v->a < v->st.mapx)
		{
			n == 1 ? (X = X + v->k) : 0;
			n == 2 ? (Y = Y + v->k) : 0;
			n == 3 ? (X = X - v->k) : 0;
			n == 4 ? (Y = Y - v->k) : 0;
			n == 5 ? (X = X * 1.1) : 0;
			n == 5 ? (Y = Y * 1.1) : 0;
			n == 6 ? (X = X * 0.9) : 0;
			n == 6 ? (Y = Y * 0.9) : 0;
			XN = X * v->c;
			YN = Y * v->c;
			v->a++;
		}
		v->a = 0;
		v->b++;
	}
	draw(v, 0);
}

void	change(t_v *v, int n)
{
	(n == 1) ? move(v, 3) : 0;
	(n == 2) ? move(v, 1) : 0;
	(n == 3) ? move(v, 2) : 0;
	(n == 4) ? move(v, 4) : 0;
	(n == 11) ? move(v, 5) : 0;
	(n == 12) ? move(v, 6) : 0;
	(n == 5) ? roty(v, -0.05) : 0;
	(n == 6) ? roty(v, 0.05) : 0;
	(n == 7) ? rotx(v, 0.05) : 0;
	(n == 8) ? rotx(v, -0.05) : 0;
	(n == 9) ? rotz(v, -0.05) : 0;
	(n == 10) ? rotz(v, 0.05) : 0;
	(n == 15) ? rotx(v, 0) : 0;
}
