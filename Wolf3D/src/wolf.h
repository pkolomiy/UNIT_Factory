/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:34:34 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/20 14:50:22 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define VAR_INT(x, y) int x = y
# define VAR_DBL(x, y) double x = y

# define TEX_X 350
# define TEX_Y 350

# define WIN_X 1200
# define WIN_Y 750

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define SPACE 49
# define ENTER 36
# define LSHIFT 257
# define PLUS 69
# define MINUS 78
# define MULT 67
# define DIVIDE 75

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_sprite
{
	double			x;
	double			y;
	char			type;
}					t_sprite;

typedef struct		s_map
{
	int				x;
	int				y;
	unsigned char	wall : 2;
	_Bool			player;
	_Bool			barrel;
	_Bool			cat;
	_Bool			dog;
	_Bool			florin;
	_Bool			lamp;
	_Bool			sprite;
}					t_map;

typedef struct		s_mvar
{
	t_map			**map;
	int				map_width;
	int				map_height;
	t_sprite		*sprite;
	int				num_sprites;
}					t_mvar;

typedef struct		s_raycast
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
}					t_raycast;

typedef struct		s_sides
{
	double			ray_dx;
	double			ray_dy;
	int				map_x;
	int				map_y;
	double			side_dx;
	double			side_dy;
	double			delta_x;
	double			delta_y;
	double			perp_wd;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_sides;

typedef struct		s_dir
{
	int				line_h;
	int				draw_sx;
	int				draw_sy;
	int				draw_ex;
	int				draw_ey;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			floor_x;
	double			floor_y;
	double			cur_dist;
	double			cur_fx;
	double			cur_fy;
	int				ftx;
	int				fty;
}					t_dir;

typedef struct		s_spr
{
	double			tr_y;
	int				spr_sx;
	int				spr_h;
	int				spr_w;
	char			red;
	char			green;
	char			blue;
}					t_spr;

typedef struct		s_draw
{
	double			*z_buff;
	int				*spr_ord;
	double			*spr_dist;
}					t_draw;

typedef struct		s_moves
{
	int				x;
	char			turn[2];
	char			move[2];
	char			strafe[2];
	_Bool			mouse;
}					t_moves;

typedef struct		s_textures
{
	char			*wood;
	char			*brick;
	char			*ceiling;
	char			*floor;
	char			*barrel;
	char			*lamp;
	char			*cat;
	char			*dog;
	char			*florin;
	char			*sprite;
}					t_textures;

typedef struct		s_lbx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*put;
}					t_lbx;

typedef struct		s_var
{
	t_mvar			mvr;
	t_raycast		rc;
	t_moves			mvs;
	t_textures		tex;
	t_lbx			lbx;
	t_draw			dr;
	t_sides			sd;
	t_dir			dir;
	t_spr			spr;
	int				b;
	int				s;
	int				e;
	char			*str;
	int				i;
	int				x;
	int				y;
}					t_var;

void				put_error(char *message, char *second_message);
void				read_file(char *file);
void				get_map(t_var *var, t_mvar *mvr);
void				create_sprite_map(t_var *var, t_mvar *mvr);
void				dublicate_check(char cell, t_var *var, t_mvar *mvr);
void				fill_var(t_var var);
int					key_press(int key, t_var *var);
int					key_release(int key, t_var *var);
int					mouse_look(int x, int y, t_var *var);
int					mouse_press(int button, int x, int y, t_var *var);
int					loop(t_var *var);
void				raycasting(t_var *var);
void				sprite_prepare(t_var *var);
void				raycast_prepare(t_var *var);
void				draw_walls(t_var *var);
void				draw_floor_and_ceiling(t_var *var);
void				sprite_calculate(t_var *var);
void				sprite_draw(t_var *var);

#endif
