#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 23:58:52 by pkolomiy          #+#    #+#              #
#    Updated: 2019/03/02 23:59:48 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror -O3 -I includes

SRC = libft/ft_memalloc.c \
      libft/ft_bzero.c \
      libft/ft_memcpy.c \
      libft/ft_memdel.c \
      libft/ft_memset.c \
      libft/ft_strlen.c \
      ft_printf/ft_printf.c \
      ft_printf/parsing/parse_fmt.c \
      ft_printf/parsing/parse_arg.c \
      ft_printf/parsing/parse_flags.c \
      ft_printf/buffer/flush_buffer.c \
      ft_printf/buffer/buffer_set.c \
      ft_printf/buffer/decimal_to_buffer.c \
      ft_printf/buffer/string_to_buffer.c \
      ft_printf/types/type_string.c \
      ft_printf/types/type_pointer.c \
      ft_printf/types/type_decimal.c \
      ft_printf/types/type_octal.c \
      ft_printf/types/type_hexadecimal.c \
      ft_printf/types/type_unsigned.c \
      ft_printf/types/type_char.c \
      ft_printf/getters/get_t_number.c \
      ft_printf/getters/get_width_and_precision.c \
      ft_printf/getters/get_itoa_base_string.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
