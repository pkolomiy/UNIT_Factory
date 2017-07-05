/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <kzahreba@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 12:44:40 by kzahreba          #+#    #+#             */
/*   Updated: 2017/05/21 21:17:55 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_alum
{
	int			*board;
	int			len;
	int			index;
}				t_alum;

typedef struct	s_l
{
	int			i;
	struct s_l	*next;
}				t_lst;

int				new_map(int fd, t_alum *var);
int				map(t_alum *var, t_lst **lst);
void			ft_putnbr(int n);
void			game(t_alum *alum);
void			print_board(t_alum *alum);
int				read_number(int num);
void			won(void);
void			lost(void);

#endif
