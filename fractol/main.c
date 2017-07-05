/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:13:36 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/04/01 02:25:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int		name2(char *z, t_v v)
{
	v.s = "newton";
	v.a = -1;
	v.b = 0;
	while (z[++v.a])
		(z[v.a] == v.s[v.a]) ? (v.b++) : 0;
	if (v.a == v.b && v.a == 6)
		return (v.a);
	v.s = "ship";
	v.a = -1;
	v.b = 0;
	while (z[++v.a])
		(z[v.a] == v.s[v.a]) ? (v.b++) : 0;
	if (v.a == v.b && v.a == 4)
		return (v.a);
	return (0);
}

int		name(char *z, t_v v)
{
	v.s = "mandelbrot";
	v.a = -1;
	v.b = 0;
	while (z[++v.a])
		(z[v.a] == v.s[v.a]) ? (v.b++) : 0;
	if (v.a == v.b && v.a == 10)
		return (v.a);
	v.s = "julia";
	v.a = -1;
	v.b = 0;
	while (z[++v.a])
		(z[v.a] == v.s[v.a]) ? (v.b++) : 0;
	if (v.a == v.b && v.a == 5)
		return (v.a);
	return (name2(z, v));
}

int		main(int x, char **z)
{
	t_v	v;

	if (x != 2 || !(v.a = name(z[1], v)))
	{
		write(1, "Usage : ./fractol mandelbrot\n", 30);
		write(1, "                  julia\n", 25);
		write(1, "                  newton\n", 26);
		write(1, "                  ship\n", 24);
	}
	(x == 2) ? (v.s = z[1]) : 0;
	(v.a == 4) ? windows(v) : 0;
	(v.a == 5) ? windowj(v) : 0;
	(v.a == 6) ? windown(v) : 0;
	(v.a == 10) ? windowm(v) : 0;
	return (0);
}
