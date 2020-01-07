NM = ft_nm

OTOOL = ft_otool

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes

LIBFT = $(addprefix libft/, ft_atoi.c ft_strcmp.c ft_strlen.c ft_strncmp.c)

PARSE = $(addprefix parse/,	parse_archive.c parse_fat.c parse_file.c \
			parse_load_cmd.c parse_macho.c parse_object.c parse_segments.c)

PRINT =	$(addprefix print/, print_arch.c print_error.c print_otool.c \
			print_symbols.c print_hex.c)

SRC =	$(LIBFT) $(PARSE) $(PRINT) get_mem.c sort_symbols.c swap.c

NM_SRC = ft_nm.c $(SRC)

OTOOL_SRC = ft_otool.c $(SRC)

NM_OBJ = $(addprefix src/, $(NM_SRC:.c=.o))

OTOOL_OBJ = $(addprefix src/, $(OTOOL_SRC:.c=.o))

all: $(NM) $(OTOOL)

$(NM): $(NM_OBJ)
	$(CC) $^ -o $@

$(OTOOL): $(OTOOL_OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(NM_OBJ) $(OTOOL_OBJ)

fclean: clean
	rm -f $(NM) $(OTOOL)

re: fclean all
