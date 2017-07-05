/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:29:32 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/23 12:28:22 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	filxy(t_v *v)
{
	v->a = -1;
	v->b = 0;
	while (v->str[++v->a])
		(v->str[v->a] == 10) ? v->b++ : 0;
	v->st.mapx = v->c;
	v->st.mapy = v->b;
	v->st.map = (t_map**)malloc(sizeof(t_map*) * (v->st.mapy));
	v->st.maps = v->b * v->c;
	v->b = 0;
	v->c = 0;
	while (v->b < v->st.mapy)
	{
		v->st.map[v->b] = (t_map*)malloc(sizeof(t_map) * (v->st.mapx));
		while (v->c < v->st.mapx)
		{
			v->st.map[v->b][v->c].x = v->c;
			v->st.map[v->b][v->c].y = v->b;
			v->c++;
		}
		v->c = 0;
		v->b++;
	}
}

t_uc	get_color(char f1, char f2)
{
	t_uc	c;

	c = 0;
	(f1 >= 48 && f1 <= 57) ? (f1 = f1 - 48) : 0;
	(f2 >= 48 && f2 <= 57) ? (f2 = f2 - 48) : 0;
	(f1 >= 65 && f1 <= 70) ? (f1 = f1 - 55) : 0;
	(f2 >= 65 && f2 <= 70) ? (f2 = f2 - 55) : 0;
	(f1 >= 97 && f1 <= 102) ? (f1 = f1 - 87) : 0;
	(f2 >= 97 && f2 <= 102) ? (f2 = f2 - 87) : 0;
	c = (f1 * 16) + f2;
	return (c);
}

void	filrgb(t_v *v, int n)
{
	if (n == 2)
		v->st.map[v->e][v->f].b = get_color(v->str[v->a - 2], v->str[v->a - 1]);
	else if (n == 4)
	{
		v->st.map[v->e][v->f].b = get_color(v->str[v->a - 2], v->str[v->a - 1]);
		v->st.map[v->e][v->f].g = get_color(v->str[v->a - 4], v->str[v->a - 3]);
	}
	else if (n == 6)
	{
		v->st.map[v->e][v->f].b = get_color(v->str[v->a - 2], v->str[v->a - 1]);
		v->st.map[v->e][v->f].g = get_color(v->str[v->a - 4], v->str[v->a - 3]);
		v->st.map[v->e][v->f].r = get_color(v->str[v->a - 6], v->str[v->a - 5]);
	}
	else if (!n)
	{
		v->st.map[v->e][v->f].b = 255;
		v->st.map[v->e][v->f].g = 255;
		v->st.map[v->e][v->f].r = 255;
	}
}

void	filzrgb(t_v *v)
{
	v->str[v->a] == 45 ? (v->c = 1) : 0;
	v->str[v->a] == 45 ? (v->a++) : 0;
	v->st.map[v->e][v->f].z = v->str[v->a] - 48;
	v->a++;
	while (v->str[v->a] != 44 && v->str[v->a] != 32 && v->str[v->a] != 10)
	{
		v->st.map[v->e][v->f].z = (v->st.map[v->e][v->f].z * 10) +
			(v->str[v->a] - 48);
		v->a++;
	}
	v->c ? (v->st.map[v->e][v->f].z = v->st.map[v->e][v->f].z * -1) : 0;
	if (v->str[v->a] == 44)
	{
		v->a = v->a + 3;
		v->c = v->a;
		while (v->str[v->a] != 32 && v->str[v->a] != 10)
			v->a++;
		v->c = v->a - v->c;
		(v->c == 2) ? filrgb(v, 2) : 0;
		(v->c == 4) ? filrgb(v, 4) : 0;
		(v->c == 6) ? filrgb(v, 6) : 0;
	}
	else
		filrgb(v, 0);
}

void	save_map(t_v v)
{
	filxy(&v);
	v.a = 0;
	v.b = 0;
	v.e = 0;
	v.f = 0;
	while (v.b < v.st.maps)
	{
		v.c = 0;
		while (v.str[v.a] == 32)
			v.a++;
		filzrgb(&v);
		while (v.str[v.a] != 32 && v.str[v.a] != 10)
			v.a++;
		while (v.str[v.a] == 32)
			v.a++;
		v.str[v.a] == 10 ? v.a++ : 0;
		v.b++;
		(v.f < v.st.mapx - 1) ? (v.f++) : (v.f = 0);
		(!v.f) ? (v.e++) : 0;
	}
	free(v.str);
	window(v);
}
