/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:02:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/21 11:02:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

# define GETCWD_BUF 1024

enum {NOT_FOUND, PERMISSION_DENIED, ALL_OK};

typedef struct s_sh		t_sh;
typedef struct s_env	t_env;
typedef struct stat		t_stat;

struct		s_env
{
	char	*key;
	char	*val;
	t_env	*prev;
	t_env	*next;
};

struct		s_sh
{
	t_env		*env_end;
	t_env		*env;
	size_t		env_len;
	char		*line;
	t_strarr	arg;
	_Bool		exit;
};

/*
** getters
*/

char		*get_from_env(t_env *env, char *key);

/*
** setters
*/

void		set_new_env(t_sh *sh, char *key, char *val);
_Bool		set_to_env(t_sh *sh, char *key, char *val);

/*
** parsing
*/

void		parse_input(t_sh *sh);
void		parse_input_line(t_sh *sh);
void		parse_arguments(t_sh *sh);
void		parse_quotes(t_sh *sh);

/*
** validation
*/

_Bool		valid_name(char *name);

/*
** main sources
*/

void		minishell(t_sh *sh);
void		error_msg(char *str1, char *str2, char *str3, char *str4);
void		ft_signal(int sig);
void		ft_signal2(int sig);

int			g_sig;

#endif
