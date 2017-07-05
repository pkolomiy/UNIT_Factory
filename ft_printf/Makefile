#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 16:54:47 by pkolomiy          #+#    #+#              #
#    Updated: 2017/02/11 17:16:22 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

C = extra2.c type_pcs.c extra3.c just_char.c type_st.c convert.c extra4.c \
print.c type_su.c extra.c ft_printf.c type_o.c type_x.c

O = extra2.o type_pcs.o extra3.o just_char.o type_st.o convert.o extra4.o \
print.o type_su.o extra.o ft_printf.o type_o.o type_x.o

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(C)
	@ar rc $(NAME) $(O)

all: $(NAME)

clean:
	@rm -f $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all