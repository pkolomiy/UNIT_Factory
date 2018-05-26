/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:52:34 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/05/26 18:02:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list	t_gnl;

struct		s_gnl_list
{
	int		fd;
	int		start;
	int		end;
	int		len;
	char	*str;
	t_gnl	*next;
};

int			get_next_line(const int fd, char **line);

#endif
