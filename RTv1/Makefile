# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 14:34:15 by pkolomiy          #+#    #+#              #
#    Updated: 2017/12/16 22:59:34 by pkolomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

CC = gcc -Wall -Wextra -Werror -O3

MLX = -framework OpenGL -framework AppKit -lmlx

SRC = camera.c compas.c cone.c cylinder.c hud.c light_and_shadow.c main.c \
	menu.c move.c plane.c raytracing.c rotate.c scenes.c solve.c sphere.c

OBJ = $(addprefix src/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(MLX) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
