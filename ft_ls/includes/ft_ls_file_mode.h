/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_file_mode.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:26:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/08 15:26:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FILE_MODE_H
# define FT_LS_FILE_MODE_H

# include "ft_printf.h"

typedef struct s_mode		t_mode;
typedef struct s_bits		t_bits;
typedef union u_file_mode	t_file_mode;
typedef union u_rwx			t_rwx;

struct	s_bits
{
	t_byte	x : 1;
	t_byte	w : 1;
	t_byte	r : 1;
};

union	u_rwx
{
	t_bits	bit;
	t_byte	all;
};

struct	s_mode
{
	t_byte	other : 3;
	t_byte	group : 3;
	t_byte	owner : 3;
	t_byte	mode_other : 1;
	t_byte	mode_group : 1;
	t_byte	mode_owner : 1;
	t_byte	type : 4;
};

# define FILE_TYPE(type) "-pc-d-b---l-s-w"[type]

union	u_file_mode
{
	t_mode	file;
	mode_t	st_mode;
};

#endif
