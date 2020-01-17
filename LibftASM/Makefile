AS = nasm
ASFLAGS = -f macho64
NAME = libfts.a

SRC =	ft_bzero.s ft_strlen.s ft_memcpy.s ft_strdup.s ft_memset.s ft_strcat.s \
		ft_isalnum.s ft_isalpha.s ft_isascii.s ft_isdigit.s ft_isprint.s \
		ft_toupper.s ft_tolower.s ft_puts.s ft_putchar.s ft_cat.s \
		ft_memalloc.s ft_strcmp.s ft_strjoin.s ft_putnbr.s

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

test: all
	gcc main.c $(NAME)
	./a.out

test_output: all
	gcc main_output.c $(NAME)
	./a.out > my_output
	echo "putchar test\n-2147483648-101100-452147483647\n(null)\ntest string" > default_output
	diff default_output my_output

test_cat: all
	gcc main_cat.c $(NAME)
	./a.out > my_cat
	cat big.txt > default_cat
	diff default_cat my_cat

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) a.out my_output default_output my_cat default_cat

re: fclean all
