/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:49:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/11/26 16:04:32 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include <unistd.h>
# include <stdlib.h>

# define SEARCH_NEWLINE 1
# define MAKE_A_COPY 2
# define STRING_LENGTH 3
# define CROP_STRING 4

typedef struct		s_lst
{
	int				fd;
	char			*str;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_var
{
	int				nbr;
	int				index;
	int				first_char;
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	t_lst			*lst;
}					t_var;

int					get_next_line(const int fd, char **line);

#endif
