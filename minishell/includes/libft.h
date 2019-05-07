/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:56:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/07 15:56:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef unsigned char	t_byte;

typedef struct s_strarr	t_strarr;
typedef struct s_gnl	t_gnl;

struct		s_strarr
{
	char	**ptr;
	size_t	len;
};

struct		s_gnl
{
	char	*start;
	char	*middle;
	char	*end;
};

_Bool		str_equal(char *s1, char *s2);
_Bool		white_space(char c);
_Bool		name_symbol(char c);

size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, t_byte c);
char		*ft_strdup(char *str);
char		*join_with_char(char *part1, char *part2, char c);
t_strarr	ft_strsplit(char *str, char c);
char		*ft_strcut(char *str, size_t start, size_t end);
char		*trim_char(char *str, char c);
char		*sub_string(char *src, size_t start, size_t len);
char		*replace_string(char *src, char *dst, size_t start, size_t len);

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ptr);
void		ft_memcpy(void *dst, void *src, size_t size);
void		ft_bzero(void *ptr, size_t size);

void		free_strarr(t_strarr *arr);

int			get_next_line(int fd, char **line);

#endif
