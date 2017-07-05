#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzahreba <kzahreba@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 17:21:13 by kzahreba          #+#    #+#              #
#    Updated: 2017/05/21 20:49:20 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = alum1
CFLAGS = -Wall -Wextra -Werror
FILES = main.c ft_putnbr.c new_map.c game.c additional_functions.c message.c
CC = gcc
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
