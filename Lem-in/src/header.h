/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:21:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/12/25 21:59:51 by pkolomiy         ###   ########.fr       */
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

typedef struct s_lemin	t_lem;
typedef struct s_rooms	t_rooms;
typedef struct s_links	t_links;
typedef struct s_way	t_way;
typedef struct s_ways	t_ways;

/*
**..............................................................................
**....................................Links.....................................
**..............................................................................
*/

enum {FIRST, SECOND};

struct		s_links
{
	char	*first;
	char	*second;
	int		lvl1;
	int		lvl2;
	t_links	*next;
};

/*
**..............................................................................
**.....................................Way......................................
**..............................................................................
*/

enum {SET, GET};

struct		s_way
{
	int		len;
	t_rooms	*rooms;
	t_way	*next;
};

enum {LEN, SUM};

struct		s_ways
{
	int		len;
	int		sum;
	t_way	*ways;
	t_ways	*next;
};

_Bool		one_way(t_lem *l);
void		set_levels(t_lem *l);
int			get_level(t_rooms *rooms, char *room);
void		add_end(t_lem *l, char *room, int level);
void		dublicate_way(t_way *ways, char *room, int links);
void		del_way(t_lem *l, t_way **cur, t_way **prev);
void		remove_intersection(t_lem *l);
t_way		*dublicate_rooms(t_rooms *rooms, int len);
void		free_rooms(t_way **way);
void		clean_ways(t_lem *l);

/*
**..............................................................................
**....................................Rooms.....................................
**..............................................................................
*/

struct		s_rooms
{
	char		*name;
	unsigned	ant;
	int			level;
	t_rooms		*next;
};

/*
**..............................................................................
**...................................Lem-in.....................................
**..............................................................................
*/

struct		s_lemin
{
	unsigned long	ants;
	char			*start;
	char			*end;
	t_rooms			*rooms;
	t_links			*links;
	t_way			*ways;
	t_ways			*groups;
	unsigned char	stage : 2;
	char			*str;
	unsigned		str_len;
	char			**ptr;
	unsigned		ptr_len;
};

void		error();
void		put(t_lem *l);
void		get_ant(t_lem *l);
void		get_room(t_lem *l);
void		get_links(t_lem *l);
_Bool		final_validation(t_lem *l);
void		del_link(t_lem *l, t_links **cur, t_links **prev);
void		remove_unlink_rooms(t_lem *l);
void		remove_trash_links(t_lem *l);
void		remove_trash_rooms(t_lem *l);
void		lem_in(t_lem *l);
void		prepare(t_way *ways);
void		colors(char *arr[]);
void		print(t_lem *l);
void		show_ways(t_way *ways);
int			count_ways(t_way *ways);

/*
**..............................................................................
**..................................Validation..................................
**..............................................................................
*/

_Bool		valid_comment(t_lem *l);
_Bool		valid_int(char *str);
_Bool		valid_room(char *str);
_Bool		valid_link_string(const char *str);
_Bool		valid_link(t_links	links, t_lem *l);

/*
**..............................................................................
**....................................Libft.....................................
**..............................................................................
*/

void		nbr(unsigned n);
_Bool		cmp(const char *s1, const char *s2);
unsigned	len(const char *str);
char		*copy(const char *str);
char		**split(t_lem *l, char *str);

#endif
