#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 12:48:31 by pkolomiy          #+#    #+#              #
#    Updated: 2017/03/20 17:05:10 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

C = ft_atoi.c ft_atoi_base.c ft_base_converter.c ft_bzero.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c \
ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_nbrlen.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putnchar.c ft_putnstr.c ft_putsnbr.c ft_putstr.c ft_putstr_fd.c \
ft_putunbr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_var.c ft_wchar.c

O = $(C:.c=.o)

all: $(NAME)

$(NAME): $(O)
	@gcc -Wall -Wextra -Werror -c $(C)
	@ar rc $(NAME) $(O)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@rm -rf $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
