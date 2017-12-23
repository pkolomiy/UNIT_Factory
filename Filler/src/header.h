/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:20:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/19 18:23:48 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

# include "get_next_line.h"

typedef struct s_filler		t_fil;

struct	s_filler
{
	char			me;
	char			enemy;
	unsigned char	map_x;
	unsigned char	map_y;
	unsigned char	fig_x;
	unsigned char	fig_y;
	char			**map;
	unsigned char	**dist_enemy;
	unsigned char	**enemy_buf;
	char			**figure;
	_Bool			flag;
	unsigned char	x;
	unsigned char	y;
	unsigned short	sum;
};

void	read_map_and_piece(t_fil *f);
void	make_distance_map(t_fil *f);

#endif
