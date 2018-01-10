/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:47:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/08 22:09:47 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "get_next_line.h"

/*
**..............................................................................
**...................................Typedef....................................
**..............................................................................
*/

typedef struct s_stack	t_stack;
typedef struct s_main	t_main;
typedef struct s_ins	t_ins;

/*
**..............................................................................
**....................................Stack.....................................
**..............................................................................
*/

struct		s_stack
{
	int		nbr;
	t_stack	*next;
};

/*
**..............................................................................
**................................Instructions..................................
**..............................................................................
*/

struct		s_ins
{
	unsigned char	len;
	char			*inst;
	t_ins			*prev;
	t_ins			*next;
};

/*
**..............................................................................
**.................................Operations...................................
**..............................................................................
*/

enum {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

void		sa_sb_ss(char action, t_main *m);
void		pa_pb(char action, t_main *m);
void		ra_rb_rr(char action, t_main *m);
void		rra_rrb_rrr(char action, t_main *m);

/*
**..............................................................................
**....................................Sort......................................
**..............................................................................
*/

enum {A, B};

int			find_pivot(t_stack *tmp, int len);
void		sorting(t_main *m, _Bool stack);
void		sort_3_elem(_Bool stack, t_main *m);

/*
**..............................................................................
**.................................Visualizer...................................
**..............................................................................
*/

# define ENTER 10
# define SPACE 32
# define LEFT 260
# define RIGHT 261

void		visualizer(t_main *m);
void		apply(t_main *m, const char *inst);

/*
**..............................................................................
**....................................Main......................................
**..............................................................................
*/

enum {PUSH_SWAP, CHECKER, VISUALIZER};

struct		s_main
{
	char	program;
	_Bool	stack;
	_Bool	final;
	t_stack	*a;
	t_stack	*b;
	t_ins	*ins;
	t_ins	*tmp;
	int		a_len;
	int		b_len;
	int		temp;
	int		len;
};

void		init_main(t_main *m);
void		validate_arguments(char **argv, t_main *m);
void		optimizer(t_main *m);

/*
**..............................................................................
**....................................Libft.....................................
**..............................................................................
*/

void		nbr(int n);
_Bool		cmp(const char *s1, const char *s2);

#endif
