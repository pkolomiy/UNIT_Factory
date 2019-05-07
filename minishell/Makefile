#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 11:00:59 by pkolomiy          #+#    #+#              #
#    Updated: 2019/03/21 11:01:16 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

CC = gcc -Wall -Wextra -Werror -I includes

SRC =   src_libft/get_next_line.c \
        src_libft/ft_strsplit.c \
        src_libft/ft_memdel.c \
        src_libft/ft_memalloc.c \
        src_libft/ft_memcpy.c \
        src_libft/str_equal.c \
        src_libft/ft_strlen.c \
        src_libft/ft_bzero.c \
        src_libft/ft_strchr.c \
        src_libft/white_space.c \
        src_libft/name_symbol.c \
        src_libft/sub_string.c \
        src_libft/replace_string.c \
        src_libft/trim_char.c \
        src_libft/ft_strcut.c \
        src_libft/ft_strdup.c \
        src_libft/join_with_char.c \
        src_libft/free_strarr.c \
\
        src_minishell/parsing/parse_input.c \
        src_minishell/parsing/parse_input_line.c \
        src_minishell/parsing/parse_arguments.c \
        src_minishell/parsing/parse_quotes.c \
\
        src_minishell/getters/get_from_env.c \
\
        src_minishell/setters/set_new_env.c \
        src_minishell/setters/set_to_env.c \
\
        src_minishell/validation/valid_name.c \
\
        src_minishell/commands/ft_cd.c \
        src_minishell/commands/ft_echo.c \
        src_minishell/commands/ft_env.c \
        src_minishell/commands/ft_setenv.c \
        src_minishell/commands/ft_unsetenv.c \
        src_minishell/commands/ft_exit.c \
        src_minishell/commands/ft_bin.c \
\
        src_minishell/minishell.c \
        src_minishell/error_msg.c \
        src_minishell/ft_signal.c \
\
        main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
