#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 16:06:56 by pkolomiy          #+#    #+#              #
#    Updated: 2017/02/27 23:55:59 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

C = change.c projection.c text.c draw.c read.c window.c save_map.c

O = change.o projection.o text.o draw.o read.o window.o save_map.o

all: $(NAME)

$(NAME):
	@gcc -c $(C)
	@gcc -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(O)

clean:
	@rm -f $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all