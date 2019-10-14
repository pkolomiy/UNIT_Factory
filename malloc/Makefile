#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:18:14 by pkolomiy          #+#    #+#              #
#    Updated: 2019/09/10 16:18:16 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK_NAME = libft_malloc.so

CC = gcc -Wall -Wextra -Werror -I includes

SRC =   add_chunk_leftover.c \
        before_return.c \
        free.c \
        ft_memcpy.c \
        ft_mmap.c \
        global.c \
        malloc.c \
        malloc_zone.c \
        realloc.c \
        try_realloc_free_space.c \
        show_alloc_mem.c \

OBJ = $(addprefix src/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	gcc $^ -shared -fPIC -o $@
	if [ ! -e ${LINK_NAME} ]; then ln -s ${NAME} ${LINK_NAME}; fi

test0: all
	gcc -o test0 tests/test0.c -I includes -L. -lft_malloc
	/usr/bin/time -l ./test0

test1: all
	gcc -o test1 tests/test1.c -I includes -L. -lft_malloc
	/usr/bin/time -l ./test1

test2: all
	gcc -o test2 tests/test2.c -I includes -L. -lft_malloc
	/usr/bin/time -l ./test2

test3: all
	gcc -o test3 tests/test3.c -I includes -L. -lft_malloc
	./test3

test3_mod: all
	gcc -o test3_mod tests/test3_mod.c -I includes -L. -lft_malloc
	./test3_mod

test4: all
	gcc -o test4 tests/test4.c -I includes -L. -lft_malloc
	./test4

test5: all
	gcc -o test5 tests/test5.c -w -I includes -L. -lft_malloc
	./test5

test6: all
	gcc -o test6 tests/test6.c -I includes -L. -lft_malloc
	./test6

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LINK_NAME)
	rm -f test0 test1 test2 test3 test3_mod test4 test5 test6

re: fclean all
