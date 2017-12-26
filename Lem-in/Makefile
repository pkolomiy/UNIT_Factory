# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 16:18:20 by pkolomiy          #+#    #+#              #
#    Updated: 2017/12/25 22:03:11 by pkolomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc -Wall -Wextra -Werror -O3

SRC = main.c libft.c get_next_line.c \
	  validation.c valid_data.c final_validation.c cleaning.c \
	  one_way.c set_levels.c lem_in.c ways.c print.c intersection.c prepare.c

OBJ = $(addprefix src/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
