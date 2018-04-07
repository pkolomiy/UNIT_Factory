/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:19:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/29 23:19:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ncurses.h>

# include "op.h"

typedef struct s_cor_file	t_cor;
typedef struct s_flags		t_flags;
typedef struct s_player		t_player;
typedef struct s_reading	t_reading;

typedef struct s_process	t_process;
typedef struct s_memory		t_memory;

typedef struct s_visual		t_visual;

typedef union u_integer		t_integer;
typedef struct s_bits		t_bits;
typedef union u_codage		t_codage;
typedef struct s_op			t_op;
typedef struct s_args		t_args;

struct			s_cor_file
{
	t_header	*header;
	t_byte		*program;
};

struct			s_flags
{
	_Bool			live;
	_Bool			visual;
	_Bool			dump;
	unsigned int	nbr;
};

struct			s_player
{
	t_cor			*file;
	int				pos;
	unsigned int	nbr;
	int				current_lives;
	int				last_live;
	t_player		*next;
};

struct			s_reading
{
	int				i;
	int				players_pos;
	unsigned int	players_num;
	unsigned int	n_num;
	_Bool			n_flag;
	char			**argv;
};

union			u_integer
{
	unsigned int	u4;
	short			s2;
	t_byte			byte[4];
};

struct			s_bits
{
	t_byte	not_used : 2;
	t_byte	third : 2;
	t_byte	second : 2;
	t_byte	first : 2;
};

/*
** в u_codage юнионе происходит разбивка одного байта (byte)
** на 4 переменных (в структурке s_bits) по 2 бита
*/

union			u_codage
{
	t_byte	byte;
	t_bits	bits;
};

/*
** vm_commands
*/

void			vm_commands(t_memory *vm);
void			check_command(t_memory *vm, t_process *process);

/*
** commands
*/

void			cmd_live(t_memory *vm, t_process *process);
void			cmd_ld_lld(t_memory *vm, t_process *process);
void			cmd_st(t_memory *vm, t_process *process);
void			cmd_add_sub(t_memory *vm, t_process *process);
void			cmd_and_or_xor(t_memory *vm, t_process *process);
void			cmd_zjmp(t_memory *vm, t_process *process);
void			cmd_ldi_lldi(t_memory *vm, t_process *process);
void			cmd_sti(t_memory *vm, t_process *process);
void			cmd_fork_lfork(t_memory *vm, t_process *process);
void			cmd_aff(t_memory *vm, t_process *process);

/*
** commands_operations.c
*/

int				change_pos(int move);
t_byte			get_byte(t_byte *mem, int index);
int				get_move_size(t_memory *vm, t_codage codage, t_byte args_num);
void			move_process_pos(t_memory *vm, t_process *process);
t_integer		update_argument(t_memory *vm, t_process *process, t_byte number,
														t_integer old_argument);

/*
** get_arguments.c
*/

_Bool			get_arguments(t_memory *vm, t_process *process,
															t_integer args[]);
t_integer		get_t_reg(const t_byte *mem, int pos, t_op cmd, _Bool *error);
t_integer		get_t_dir(const t_byte *mem, int pos, t_op cmd, _Bool *error);
t_integer		get_t_ind(const t_byte *mem, int pos, t_op cmd, _Bool *error);
t_integer		get_ind_bytes(const t_byte *mem, t_integer ind, int pos);

struct			s_op
{
	char	*name;
	t_byte	args_num;
	t_byte	arg[3];
	t_byte	opcode;
	int		wait;
	_Bool	codage;
	t_byte	t_dir_size;
	void	(*command)(t_memory *vm, t_process *process);
};

/*
** name - имя функции/операции/команды
** args_num - количество аргументов функция принимает
** arg[3] - сами аргументы
** opcode - порядковый номер функции
** wait - сколь циклов нужно ждать перед выполнением команды
** codage - флаг определяет есть ли у функции кодирующий байт (codage)
** t_dir_size - размер для T_DIR аргумента
** command - указатель на функцию обработки команды
*/

static t_op	g_op_tab[16] =
{
	{"live", 1, {T_DIR}, 1, 10, 0, 4, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 4, 0},
	{"st", 2, {T_REG, T_REG | T_IND}, 3, 5, 1, 4, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 4, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 4, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 6, 1,
		4, 0},
	{"or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 7, 6, 1,
		4, 0},
	{"xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 8, 6, 1,
		4, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, 0, 2, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 10, 25, 1, 2, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR}, 11, 25, 1, 2, 0},
	{"fork", 1, {T_DIR}, 12, 800, 0, 2, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 4, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 14, 50, 1, 2, 0},
	{"lfork", 1, {T_DIR}, 15, 1000, 0, 2, 0},
	{"aff", 1, {T_REG}, 16, 2, 1, 4, 0}
};

void (*g_command[16])(t_memory *vm, t_process *process);

struct			s_args
{
	t_byte		code;
	t_byte		size;
	t_integer	(*get)(const t_byte *mem, int pos, t_op cmd, _Bool *error);
};

struct			s_process
{
	int			pos;
	int			wait;
	int			player;
	_Bool		alive;
	_Bool		execute;
	_Bool		carry;
	t_integer	reg[REG_NUMBER];
	t_codage	codage;
	t_op		cmd;
	t_process	*next;
};

struct			s_visual
{
	_Bool	pause;
	_Bool	first_time;
	int		nbr_processes;
	int		step;
	t_byte	*colors;
	t_byte	*carets;
	t_byte	delay;
};

struct			s_memory
{
	int			cycle;
	int			cycle_to_die;
	int			nbr_live;
	int			max_checks;
	int			winner;
	t_args		args[4];
	t_byte		*mem;
	t_flags		flags;
	t_player	*players;
	t_process	*processes;
	t_visual	vis;
};

/*
** main
*/

void			vm_init(t_memory *vm);
int				malloc_error(const char *str);
size_t			string_len(const char *str);
_Bool			cmp(const char *s1, const char *s2);

/*
** vm_args
*/

_Bool			vm_args(char **argv, t_player **players, t_flags *flags,
																char **error);
t_cor			*vm_reader(char *name, char **error);

/*
** vm_program
*/

void			vm_program(t_memory *vm);

/*
** vm_visualizer
*/

void			vm_visualizer(t_memory *vm, _Bool flag);
void			menu(t_memory *vm);
void			key_press(t_memory *vm);

_Bool	g_recalculate_carets_positions;

#endif
