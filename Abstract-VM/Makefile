#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 11:54:36 by pkolomiy          #+#    #+#              #
#    Updated: 2019/10/24 11:54:37 by pkolomiy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = avm

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -I inc -std=c++11

SRC =	main.cpp \
		Line.cpp \
		Lexer.cpp \
		OperandFactory.cpp \
		Parser.cpp \
		Exceptions.cpp \
		Reader.cpp \

OBJ = $(addprefix src/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
