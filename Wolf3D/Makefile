#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 16:06:56 by pkolomiy          #+#    #+#              #
#    Updated: 2017/10/20 14:49:55 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

FLAGS = -O3 -lmlx -framework OpenGL -framework AppKit

CC = gcc -Wall -Wextra -Werror -I src

SRC = src/

OBJ = main.o \
	map_read.o map_create.o map_sprite.o \
	mlx_start.o mlx_events.o mlx_loop.o \
	raycasting.o raycast_prepare.o raycast_draw.o \
	sprite_prepare.o sprite_calculate.o sprite_draw.o \
	error.o

FILES = $(addprefix $(SRC), $(OBJ))

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $^ $(FLAGS) -o $@

clean:
	rm -f $(FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
