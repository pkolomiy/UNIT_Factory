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

NAME = ft_ls

CC = gcc -Wall -Wextra -Werror -O3 -I includes

SRC =	main.c \
		libft_src/ft_memalloc.c \
		libft_src/ft_memdup.c \
		libft_src/ft_bzero.c \
		libft_src/ft_memcpy.c \
		libft_src/ft_memmove.c \
		libft_src/ft_memdel.c \
		libft_src/ft_memset.c \
		libft_src/ft_strlen.c \
		libft_src/ft_nbrlen.c \
		libft_src/ft_strdup.c \
		libft_src/ft_stringclone.c \
		libft_src/ft_strcmp.c \
		ft_printf_src/ft_printf.c \
		ft_printf_src/parsing/parse_fmt.c \
		ft_printf_src/parsing/parse_arg.c \
		ft_printf_src/parsing/parse_flags.c \
		ft_printf_src/buffer/flush_buffer.c \
		ft_printf_src/buffer/buffer_set.c \
		ft_printf_src/buffer/decimal_to_buffer.c \
		ft_printf_src/buffer/string_to_buffer.c \
		ft_printf_src/types/type_string.c \
		ft_printf_src/types/type_pointer.c \
		ft_printf_src/types/type_decimal.c \
		ft_printf_src/types/type_octal.c \
		ft_printf_src/types/type_hexadecimal.c \
		ft_printf_src/types/type_unsigned.c \
		ft_printf_src/types/type_char.c \
		ft_printf_src/getters/get_t_number.c \
		ft_printf_src/getters/get_width_and_precision.c \
		ft_printf_src/getters/get_itoa_base_string.c \
		ft_ls_src/ft_ls.c \
		ft_ls_src/big_r_recursion.c \
		ft_ls_src/read_whole_dir.c \
		ft_ls_src/get_files_arr.c \
		ft_ls_src/show_dir.c \
		ft_ls_src/show_dir_l_flag.c \
		ft_ls_src/free_dir.c \
		ft_ls_src/link.c \
		ft_ls_src/create_t_file.c \
		ft_ls_src/show_dev.c \
		ft_ls_src/l_flag.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
