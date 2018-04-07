/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:38:28 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/29 21:43:28 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSER_H
# define ASM_PARSER_H

# define TWO 0xffff
# define FOUR 0xffffffff
# define COM_NAME 2192
# define LINE '"'

# include "asm.h"

typedef struct				s_bit
{
	int						bit;
	int						size;
	char					*t;
	int						t_char;
}							t_bit;

typedef struct				s_process_name
{
	int						process_number;
	int						last_suma_bit;
	int						size_bit;
	int						size_process;
	t_bit					operation[3];
	struct s_process_name	*next;
}							t_process_name;

typedef struct				s_block
{
	int						line;
	int						size;
	char					*name;
	t_process_name			*process;
	t_process_name			*cop_process;
	struct s_block			*next;
}							t_block;

typedef struct				s_error
{
	int						arg;
	int						line;
	int						t_char;
	char					*process;
}							t_error;

typedef struct				s_count
{
	int						count;
	int						num_par;
	int						f;
	int						z;
}							t_count;
t_error	g_err;

int							ft_islable(char c);
int							ft_comment(char *j);
int							ft_la_size(t_block *b4);
int							ft_isdigit_minus(int c);
int							is_lable(char *s, char c);
int							ft_cheak_label(char *lab);
int							ft_power(int num, int pow);
int							ft_count_size(t_block *b2);
int							ft_empty_line(char *name, int f);
int							ft_search_labe(char *name, t_block *b1, int q,
																		int f);
int							ft_seach_process_name(char *str, int *f);
int							ft_search_lable_size(char *s, t_block *b1);
int							ft_serch_name_proc(char *str, int *f, int q, int r);
int							ft_bite(char *file, t_count *o, t_block *block);
int							ft_dir_command(int num_of_static_val, int count);
int							ft_ind_command(int num_of_static_val, int count);
int							ft_reg_command(int num_of_static_val, int count);
int							bit_write_to_string(t_block *b1,
										unsigned char *ret, int d);
int							ft_time_variable(char *time_variable,
										int q, int f, char *name);
int							cre_struct_data_labels_proc(t_file *cop,
										t_block *b2, int p, int f);
int							ft_cheak_inctruction(char *file, int *f,
										int num_of_static_val, t_block *block);

void						ft_free(t_file *file, t_block *b1);
void						ft_write_lable_error(char *error);
void						creat_process_block(t_block *block);
void						ft_write(char *error, char *s1, char *s2);
void						three_digit_number(char *error, int num, int *j);
t_file						*ft_search_comment(t_file *cop, unsigned char *ret);
void						creat_file(char *argv, int num, unsigned char *ret);
void						ft_convert_nbr(int numb, int power,
											unsigned char *ret, int *d);

t_block						*first_block(t_file *cop, t_block *b2,
											int num_of_static_val, int p);

unsigned char				*asm_parser(char **error, int *size, char **argv,
											t_file *file);
t_file						*name_comment(t_file *cop,
											unsigned char *ret, int f);
t_file						*reader(char *name, int fd);
unsigned char				*create_line(unsigned char *ret, int *size);
int							the_comm(char *str, int f);

#endif
