/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 11:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/03 11:30:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# pragma pack(1)

# include "ft_ls_file_mode.h"

# define HALF_YEAR 15724800
# define READ_LINK_BUFF 512

typedef struct dirent		t_dirent;
typedef struct stat			t_stat;
typedef struct passwd		t_passwd;
typedef struct group		t_group;

typedef struct s_file		t_file;
typedef struct s_dir		t_dir;
typedef struct s_padding	t_padding;
typedef struct s_ls_flags	t_ls_flags;
typedef struct s_name		t_name;

struct	s_name
{
	char	*name;
	char	type;
	t_name	*next;
};

struct	s_padding
{
	t_byte	nlink;
	t_byte	pw_name;
	t_byte	gr_name;
	t_byte	st_size;
	t_byte	dev_maj;
	t_byte	dev_min;
};

struct	s_file
{
	char		type;
	t_stat		*stat;
	char		*name;
	char		*full_name;
	char		*link;
	t_string	user;
	t_string	group;
	t_file		*next;
};

struct	s_dir
{
	char		*name;
	blkcnt_t	total;
	int			files_counter;
	t_file		*files;
	t_file		**files_arr;
	t_padding	padding;
	_Bool		dev;
	_Bool		dir;
};

struct	s_ls_flags
{
	t_byte	a : 1;
	t_byte	f : 1;
	t_byte	l : 1;
	t_byte	r : 1;
	t_byte	big_r : 1;
	t_byte	t : 1;
	int		argc;
};

/*
** link.c
*/

ssize_t	try_readlink(t_file *file);
t_dir	*check_if_link(t_ls_flags flags, char *name);

/*
** l_flag.c
*/
void	print_permissions(char type, mode_t st_mode);
char	*get_date(time_t tv_sec);

void	big_r_recursion(t_ls_flags flags, char *name, int arg);

t_dir	*read_whole_dir(t_ls_flags flags, char *name);
void	read_all_arg_files(t_ls_flags flags, t_name *names, int *arg);

t_file	*create_t_file(t_ls_flags flags, t_dir *dir, char *name);
t_file	**get_files_arr(t_ls_flags flags, t_dir *dir);
void	show_dir(t_ls_flags flags, t_dir *dir, int arg);
void	show_dir_l_flag(t_dir *dir);

void	show_dev(t_dir *dir);

void	ft_ls(t_ls_flags flags, char **names);
void	free_dir(t_dir **dir);

void	my_perror(char *s);

#endif
