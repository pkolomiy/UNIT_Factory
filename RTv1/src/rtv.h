/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:27:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/17 00:16:10 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

/*
**..............................................................................
**....................................Screen....................................
**..............................................................................
*/

# define WX 1100
# define WY 700
# define INVX (1 / (double)WX)
# define INVY (1 /(double)WY)
# define ASPECT_RATIO (WX / (double)WY)
# define ANGLE (tan(M_PI * 0.5 * 30 / 180))

/*
**..............................................................................
**...................................Keyboard...................................
**..............................................................................
*/

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define SPACE 49
# define ENTER 36
# define BACKSPACE 51
# define PG_UP 116
# define PG_DN 121

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_Q 12
# define K_E 14

# define K_1 18
# define K_2 19
# define K_3 20

/*
**..............................................................................
**...................................Typedef....................................
**..............................................................................
*/

typedef struct s_mlx		t_mlx;
typedef struct s_hud		t_hud;
typedef struct s_main		t_main;
typedef struct s_int		t_int;
typedef struct s_camera		t_camera;
typedef struct s_object		t_object;
typedef struct s_ray		t_ray;
typedef struct s_vector		t_vector;
typedef struct s_color		t_color;
typedef struct s_light		t_light;
typedef struct s_shader		t_shader;

/*
**..............................................................................
**....................................Vector....................................
**..............................................................................
*/

struct		s_vector
{
	double	x;
	double	y;
	double	z;
};

# define ADD(v1, v2) ((t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z})
# define SUB(v1, v2) ((t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z})
# define SCALE(v, c) ((t_vector){v.x * c, v.y * c, v.z * c})
# define LEN(v) ((v.x * v.x) + (v.y * v.y) + (v.z * v.z))
# define DOT(v1, v2) ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z))

enum {A, B, C, D};

t_vector	normalize(t_vector v);
_Bool		solve(double var[], double *t0);

/*
**..............................................................................
**....................................Color.....................................
**..............................................................................
*/

struct		s_color
{
	double	red;
	double	green;
	double	blue;
};

/*
**..............................................................................
**....................................Light.....................................
**..............................................................................
*/

struct		s_light
{
	t_vector	position;
	t_light		*next;
};

struct		s_shader
{
	double		specular;
	double		diffuse;
	t_vector	hit;
	t_vector	object_norm;
	t_vector	light_direction;
	t_vector	camera_position;
};

# define AMBIENT 0

t_color		light(t_object *object, t_ray ray, t_main *m);

/*
**..............................................................................
**....................................Object....................................
**..............................................................................
*/

struct		s_object
{
	t_vector	position;
	t_vector	direction;
	t_color		color;
	double		radius;
	double		shine;
	_Bool		(*intersect)(t_ray ray, t_object *object, double *t0);
	t_vector	(*normal)(t_ray ray, t_object *object);
	t_object	*next;
};

# define POS(x, y, z) ((t_vector){x, y, z})
# define DIR(x, y, z) ((t_vector){x, y, z})
# define COL(red, blue, green) ((t_color){red, blue, green})
# define RAD(r) (r)

/*
**..............................................................................
**....................................Plane.....................................
**..............................................................................
*/

t_object	*plane(t_vector position, t_vector direction, t_color color);
_Bool		intersection_plane(t_ray hit, t_object *object, double *t0);
t_vector	normal_plane(t_ray ray, t_object *object);

/*
**..............................................................................
**....................................Sphere....................................
**..............................................................................
*/

t_object	*sphere(t_vector pos, t_color color, double radius);
_Bool		intersection_sphere(t_ray ray, t_object *object, double *t0);
t_vector	normal_sphere(t_ray ray, t_object *object);

/*
**..............................................................................
**...................................Cylinder...................................
**..............................................................................
*/

t_object	*cylinder(t_vector pos, t_vector dir, t_color color, double radius);
_Bool		intersection_cylinder(t_ray ray, t_object *object, double *t0);
t_vector	normal_cylinder(t_ray ray, t_object *object);

/*
**..............................................................................
**.....................................Cone.....................................
**..............................................................................
*/

t_object	*cone(t_vector pos, t_vector dir, t_color color, double radius);
_Bool		intersection_cone(t_ray ray, t_object *object, double *t0);
t_vector	normal_cone(t_ray ray, t_object *object);

/*
**..............................................................................
**.....................................MLX......................................
**..............................................................................
*/

struct		s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*arr;
	int		b;
	int		s;
	int		e;
	int		key;
};

/*
**..............................................................................
**.....................................Hud......................................
**..............................................................................
*/

struct		s_hud
{
	char	type;
	char	t;
	int		v;
	char	*n;
	int		x0;
	int		y0;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		err;
	int		c[8];
};

enum {X, Y, Z};

void		hud(t_main *m);
void		compas(t_hud h, t_main *m, int x, int y);
void		rotate(t_hud h, t_main *m);
void		move(t_hud h, t_main *m);

/*
**..............................................................................
**.....................................Ray......................................
**..............................................................................
*/

struct		s_ray
{
	t_vector	origin;
	t_vector	direction;
	t_vector	hit;
};

/*
**..............................................................................
**....................................Camera....................................
**..............................................................................
*/

struct		s_int
{
	int	x;
	int	y;
	int	z;
};

struct		s_camera
{
	t_vector	position;
	t_int		direction;
	t_vector	cos;
	t_vector	sin;
};

# define DIRECTION(x, y, z) ((t_int){x, y, z})
# define SPEED 5

void		camera_change(t_main *m, int key);
void		camera_set(t_main *m, t_vector position, t_int direction);
void		camera_scene(t_main *m, int key);

/*
**..............................................................................
**.....................................Main.....................................
**..............................................................................
*/

struct		s_main
{
	t_mlx		lx;
	t_camera	camera;
	t_object	*objects;
	t_light		*lights;
	t_color		pixel_color;
	_Bool		move_mode;
	char		scene;
};

void		raytracing(t_main *m);
void		scene1(t_main *m, int key);
void		scene2(t_main *m, int key);
void		scene3(t_main *m, int key);
void		menu(t_main *m);
void		menu1(t_main *m);
void		menu2(t_main *m);
void		menu3(t_main *m);
int			exit_x(void);
void		new(t_main *m, t_object *object);
void		add_light(t_main *m, t_vector position);

#endif
