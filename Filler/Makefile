# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 16:18:20 by pkolomiy          #+#    #+#              #
#    Updated: 2017/12/19 21:33:31 by pkolomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pkolomiy.filler

CC = gcc -Wall -Wextra -Werror -O3

SRC = main.c filler.c get_next_line.c

OBJ = $(addprefix src/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
