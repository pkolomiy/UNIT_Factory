/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:09:25 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/11 19:18:23 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define C1(x) (x) == 's' || (x) == 'S' || (x) == 'p' || (x) == 'd'
# define C2(x) (x) == 'D' || (x) == 'i' || (x) == 'O' || (x) == 'o'
# define C3(x) (x) == 'u' || (x) == 'U' || (x) == 'x' || (x) == 'X'
# define C4(x) (x) == 'c' || (x) == 'C'
# define D1(x) (x) == 45 || (x) == 48
# define D2(x) (x) == 32 || (x) == 35 || (x) == 43 || (x) == 46
# define D3(x) (x) == 104 || (x) == 106 || (x) == 108 || (x) == 122
# define D4(x) (x) == 49 || (x) == 50 || (x) == 51 || (x) == 52 || (x) == 53
# define D5(x) (x) == 54 || (x) == 55 || (x) == 56 || (x) == 57
# define V1(x) (x) != 45 && (x) != 48 && (x) != 32 && (x) != 35 && (x) != 43
# define V2(x) (x) != 46 && (x) != 104 && (x) != 106 && (x) != 108 && (x) != 122
# define V3(x) (x) != 49 && (x) != 50 && (x) != 51 && (x) != 52 && (x) != 53
# define V4(x) (x) != 54 && (x) != 55 && (x) != 56 && (x) != 57
# define A1 (a == 0) || (a == 1) || (a == 8)
# define A2 (a == 0) || (a == 1) || (a == 2) || (a == 8) || (a == 16)
# define A3 (a == 3) || (a == 24)
# define B1 (a != 0) && (a != 1) && (a != 8)
# define B2 (a != 0) && (a != 1) && (a != 2) && (a != 8) && (a != 16)
# define B3 (a != 3) && (a != 24)
# define E1 (c != 9) && (c != 8) && (c != 2) && (c != 1) && (c != 0)
# define E2 (c != 17) && (c != 16) && (c != 3)
# define E3 (c != 25) && (c != 24)

typedef struct	s_c
{
	int			n;
	int			m;
	int			zr;
}				t_c;

typedef struct	s_t
{
	int			n;
	int			d;
	int			d2;
	int			m;
	int			p;
	int			sp;
	int			zr;
	int			sh;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_t;

int				ft_printf(const char *s, ...);
int				just_char2(char *b, int a, int d);
int				any_type(char *b, char c, void *d, int f);
int				get_num(char *b, int *a);
int				type_sig(char *b, void *d, int f, int c);
int				type_uns(char *b, void *d, int f, int c);
int				type_8(char *b, void *d, int f, int c);
int				type_16(char *b, void *d, int f, int c);
int				type_c(char *b, void *d, int f);
int				type_p(char *b, void *d, int f);
int				type_s(char *b, void *d, int f, int c);
int				convert(char *b, wchar_t *d, t_t *fl);
int				type_st(char *b, long d, t_t *fl);
int				type_su(char *b, unsigned long d, t_t *fl);
int				type_o(char *b, unsigned long d, t_t *fl);
int				type_x(char *b, unsigned long d, t_t *fl, int c);
int				type_pc(char *b, char d, t_t *fl);
int				type_ps(char *b, char *d, t_t *fl, int c);
int				type_pp(int a, unsigned long d, t_t *fl);
int				len_s(long a);
int				len_m(char *s);
int				len_u(unsigned long a);
int				empty(int c, int d);
int				pr_zs(int n, int a, int t);
int				btod(char *b, int *a);
t_t				*str(void);
char			*tob(unsigned long d, int b, int *e, int c);
char			*nul(void);
void			ignor(t_t **fl);
void			prs(char *b, int *a);
void			pr_st(char *s, int d, int *a);
void			c_flag(char *b, int a, t_t **fl);
void			nbr_s(long n, int num, int *a);
void			nbr_u(unsigned long n, int num, int *a);
void			nbr_o(char *s, int num, int *a);

#endif
