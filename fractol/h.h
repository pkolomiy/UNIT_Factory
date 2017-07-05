/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:35:02 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/04 19:33:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define C ((int)((v->x * 4) + (v->y * 4000)))

typedef struct	s_var
{
	int			a;
	int			b;
	int			c;
	int			n;
	int			*f;
	double		i;
	double		x;
	double		y;
	double		x1;
	double		y1;
	double		m1;
	double		m2;
	double		z;
	double		*v;
	void		*mlx;
	void		*win;
	void		*img;
	char		*put;
	char		*s;
}				t_v;

void			mandelbrot(t_v *v, int n);
void			julia(t_v *v, int n);
void			newton(t_v *v, int n);
void			ship(t_v *v, int n);
void			windowj(t_v v);
void			windown(t_v v);
void			windowm(t_v v);
void			windows(t_v v);
void			color(t_v *v, int n);

#endif
