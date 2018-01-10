# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 16:18:20 by pkolomiy          #+#    #+#              #
#    Updated: 2018/01/08 23:49:44 by pkolomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

NAME3 = randomizer

NAME = $(NAME1) $(NAME2) $(NAME3)

CC = gcc -Wall -Wextra -Werror -O3

SRC1 = push_swap.c validation.c libft.c pivot.c operations.c sorting.c sort3.c optimizer.c

SRC2 = checker.c validation.c libft.c get_next_line.c operations.c visualizer.c

SRC3 = randomizer.c

OBJ1 = $(addprefix src/, $(SRC1:.c=.o))

OBJ2 = $(addprefix src/, $(SRC2:.c=.o))

OBJ3 = $(addprefix src/, $(SRC3:.c=.o))

all: $(NAME1) $(NAME2) $(NAME3) usage

$(NAME1): $(OBJ1)
	$(CC) $^ -o $@

$(NAME2): $(OBJ2)
	$(CC) $^ -lcurses -o $@

$(NAME3): $(OBJ3)
	$(CC) $^ -o $@

usage:
	@echo "\n      \033[34;1m* * * * * * * * * * * * * * * * * * * * * * * * \033[32mUSAGE\033[34m * * * * * * * * * * * * * * * * * * * * * * * * \033[0m\n"
	@echo "\t\033[1m1.\033[0m add random array of numbers to a variable: \033[1mARG=\"\`./randomizer [\033[31mnumber1\033[0m\033[1m] [\033[32mnumber2\033[0m\033[1m] [\033[34mnumber3\033[0m\033[1m]\`\"\033[0m"
	@echo "\t\t\t\t\t\t(to learn more about [\033[1mnumbers\033[0m] launch ./randomizer)"
	@echo "\n\t\033[1m2.\033[0m launch \033[1mpush swap\033[0m and \033[1mchecker\033[0m: \033[1m./push_swap \`echo \$$ARG\` | ./checker \`echo \$$ARG\`\033[0m"
	@echo "\t\t\t    (launch each \033[1m./push_swap\033[0m or \033[1m./checker\033[0m to see their usage)"
	@echo "\n\texample: \033[1mARG=\"\`./randomizer 100 -100 100\`\"; ./push_swap \`echo \$$ARG\` | ./checker \`echo \$$ARG\`\033[0m\n"
	@echo "\n      \033[34;1m* * * * * * * * * * * * * * * * * * * *  🎉   \033[32mHAVE FUN\033[34m  🎉  * * * * * * * * * * * * * * * * * * * * * *\033[0m\n"


clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3)

fclean: clean
	rm -f $(NAME)

re: fclean all
