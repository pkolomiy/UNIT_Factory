/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:52:19 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/29 21:43:28 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "header.h"
# include "libft.h"

typedef struct		s_asm
{
	char			*name;
	char			*comment;
	t_list			*labels;
	t_list			*instructions;
}					t_asm;

typedef struct		s_file
{
	int				num;
	char			*line;
	struct s_file	*next;
}					t_file;

int					is_label_char(char c);
int					count_char(char *str, int *res, char c);
int					check_instruction(char *arg, char **error, int j);

char				*asm_reader(char *name);
char				*error_message(int a, int flag);
char				*anti_leaks_skip_spaces(char *str);
char				*name_comment_error(int a, char *str);

void				deal_with_label(char **str, t_asm *s_file,
												char **error, int i);
void				valid_lab_and_instr(char **file, t_asm *s_file,
												char **error, int i);
void				valid_instruction(char *str, t_asm *s_file,
												char **error, int i);

_Bool				asm_validator(char *file, char **error);
_Bool				check_params(char *prm, int ret, char **error, int j);
_Bool				valid_name_and_comm(char **file, t_asm *s_file,
												char **error, int *i);

#endif
