/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:48:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/05/05 15:07:37 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

size_t	ft_strlen(char *str);
t_byte	ft_strlen(size_t nbr);

void	*ft_memalloc(size_t size);
void	ft_memcpy(void *dst, void *src, size_t size);
void	ft_bzero(void *ptr, size_t size);
void	ft_memdel(void **ptr);
void	ft_memset(void *ptr, t_byte b, size_t size);

#endif
