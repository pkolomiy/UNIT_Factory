#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 19:10:35 by pkolomiy          #+#    #+#              #
#    Updated: 2017/04/01 02:32:48 by marvin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

C = b_window.c j_window.c main.c newton.c burning.c julia.c mandelbrot.c \
m_window.c n_window.c

O = b_window.o j_window.o main.o newton.o burning.o julia.o mandelbrot.o \
m_window.o n_window.o

all: $(NAME)

$(NAME):
	@gcc -c $(C)
	@gcc -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(O)

clean:
	@rm -f $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
