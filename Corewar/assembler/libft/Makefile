# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 19:05:10 by dmulish           #+#    #+#              #
#    Updated: 2018/02/27 18:42:10 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -g

SRCS = ft_atoi.c		\
	   ft_itoa.c		\
	   cpy_list.c		\
	   ft_bzero.c		\
	   ft_lstadd.c		\
	   ft_lstdel.c		\
	   ft_lstmap.c		\
	   ft_lstnew.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_memcpy.c		\
	   ft_memdel.c		\
	   ft_memset.c		\
	   ft_putnbr.c		\
	   ft_putstr.c		\
	   ft_revstr.c		\
	   ft_strcat.c		\
	   ft_strchr.c		\
	   ft_strclr.c		\
	   ft_strcmp.c		\
	   ft_strcpy.c		\
	   ft_strdel.c		\
	   ft_strdup.c		\
	   ft_strequ.c		\
	   ft_strlen.c		\
	   ft_strmap.c		\
	   ft_strnew.c		\
	   ft_strstr.c		\
	   ft_strsub.c		\
	   ft_charnum.c		\
	   ft_isalnum.c		\
	   ft_isalpha.c		\
	   ft_isascii.c		\
	   ft_isdigit.c		\
	   ft_isprint.c		\
	   ft_lstiter.c		\
	   ft_memccpy.c		\
	   ft_memmove.c		\
	   ft_putchar.c		\
	   ft_putendl.c		\
	   ft_putwstr.c		\
	   ft_strlcat.c		\
	   ft_strmapi.c		\
	   ft_strncat.c		\
	   ft_strncmp.c		\
	   ft_strncpy.c		\
	   ft_strndup.c		\
	   ft_strnequ.c		\
	   ft_strnstr.c		\
	   ft_striter.c		\
	   ft_strjoin.c		\
	   ft_strrchr.c		\
	   ft_strtrim.c		\
	   ft_tolower.c		\
	   ft_toupper.c		\
	   ft_wordnum.c		\
	   ft_wstrlen.c		\
	   print_list.c		\
	   ft_digitnum.c	\
	   ft_free_arr.c	\
	   ft_memalloc.c	\
	   ft_putwchar.c	\
	   ft_striteri.c	\
	   ft_strsplit.c	\
	   ft_wcharlen.c	\
	   ft_atoi_base.c	\
	   ft_itoa_base.c	\
	   ft_lstdelone.c	\
	   ft_putnbr_fd.c	\
	   ft_putstr_fd.c	\
	   reverse_list.c	\
	   ft_putchar_fd.c	\
	   ft_putendl_fd.c	\
	   get_next_line.c	\
	   ft_strtrim_any.c	\
	   hash_map/hash_map.c	\
	   ft_skip_whitespace.c	\
	   hash_map/print_hash.c	\
	   ft_split_whitespace.c	\
	   hash_map/resize_hash_map.c	\

PRINTF_SRCS = ft_printf/type_c.c			\
			  ft_printf/type_d.c			\
			  ft_printf/type_o.c			\
			  ft_printf/type_p.c			\
			  ft_printf/type_s.c			\
			  ft_printf/type_u.c			\
			  ft_printf/type_x.c			\
			  ft_printf/type_smth.c		\
			  ft_printf/ft_printf.c		\
			  ft_printf/ft_bstrlen.c		\
			  ft_printf/ft_putwstr.c		\
			  ft_printf/type_big_d.c		\
			  ft_printf/type_big_s.c		\
			  ft_printf/ft_putwchar.c		\
			  ft_printf/ft_wcharlen.c		\
			  ft_printf/print_flags.c		\
			  ft_printf/handle_modif.c	\
			  ft_printf/ft_itoa_long.c	\
			  ft_printf/ft_itoa_ulong.c	\

BINS = $(SRCS:.c=.o)

BINS_PRINTF = $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS) $(BINS_PRINTF)
	ar rcu $(NAME) $(BINS) $(BINS_PRINTF)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS) $(BINS_PRINTF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
