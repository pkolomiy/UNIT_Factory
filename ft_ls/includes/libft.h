/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:48:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/02/24 18:48:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

typedef struct s_string	t_string;

struct	s_string
{
	t_byte	*ptr;
	size_t	size;
};

size_t	ft_strlen(char *str);
size_t	ft_nbrlen(size_t nbr);
char	*ft_strdup(char *str);
void	ft_stringclone(char *src, t_string *dst);
_Bool	ft_strcmp(char *s1, char *s2);

void	*ft_memalloc(size_t size);
void	*ft_memdup(void *src, size_t size);
void	ft_memcpy(void *dst, void *src, size_t size);
void	ft_memmove(void *dst, void *src, size_t size);
void	ft_bzero(void *ptr, size_t size);
void	ft_memdel(void **ptr);
void	ft_memset(void *ptr, t_byte b, size_t size);

#endif
