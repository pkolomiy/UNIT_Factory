# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 16:05:10 by pkolomiy          #+#    #+#              #
#    Updated: 2018/03/29 22:32:18 by pkolomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm

NAME2 = corewar

NAME = $(NAME1) $(NAME2)

CC = gcc -Wall -Wextra -Werror -O3 -I assembler/libft/ -I includes -g

LIB = assembler/libft/libft.a

ASM =  asm.c									\
	   asm_reader.c								\
	   error_management.c						\
\
	   asm_validator/check_params.c				\
	   asm_validator/asm_validator.c			\
	   asm_validator/deal_with_label.c			\
	   asm_validator/check_instruction.c		\
	   asm_validator/valid_instruction.c		\
	   asm_validator/valid_name_and_comm.c		\
	   asm_validator/valid_lab_and_instr.c		\
\
	   asm_parser/pow.c							\
	   asm_parser/free.c						\
	   asm_parser/labl.c						\
	   asm_parser/labl2.c						\
	   asm_parser/asm_parser.c					\
	   asm_parser/bit_record.c					\
	   asm_parser/write_error.c					\
	   asm_parser/name_comment.c				\
	   asm_parser/process_name.c				\
	   asm_parser/creat_first_block.c			\
	   asm_parser/bit_write_to_string.c			\
	   asm_parser/ft_cheak_inctruction.c		\
	   asm_parser/cheak_of_valid_values.c		\
	   asm_parser/ft_cheak_inctruction2.c		\
	   asm_parser/creat_and_write_in_file.c		\
	   asm_parser/ft_cheak_inctruction_help.c	\
	   asm_parser/cre_struct_data_labels_proc.c	\
	   asm_parser/my_parser_read.c 				\
	   asm_parser/create_line.c

VM =	main/main.c								\
		main/malloc_error.c						\
		main/libft.c							\
		main/vm_init.c							\
\
		vm_args/vm_args.c						\
		vm_args/vm_reader.c						\
\
		vm_commands/commands_operations.c		\
		vm_commands/get_arguments.c				\
		vm_commands/vm_commands.c				\
\
		vm_commands/commands/cmd_add_sub.c		\
		vm_commands/commands/cmd_aff.c			\
		vm_commands/commands/cmd_and_or_xor.c	\
		vm_commands/commands/cmd_fork_lfork.c	\
		vm_commands/commands/cmd_ld_lld.c		\
		vm_commands/commands/cmd_ldi_lldi.c		\
		vm_commands/commands/cmd_live.c			\
		vm_commands/commands/cmd_st.c			\
		vm_commands/commands/cmd_sti.c			\
		vm_commands/commands/cmd_zjmp.c			\
\
		vm_program/vm_program.c					\
\
		vm_visualizer/vm_visualizer.c			\
		vm_visualizer/menu.c					\
		vm_visualizer/key_press.c

ASM_OBJ = $(addprefix assembler/, $(ASM:.c=.o))

VM_OBJ = $(addprefix virtual_machine/, $(VM:.c=.o))

all: $(NAME1) $(NAME2)

$(NAME1): $(ASM_OBJ)
	make -j4 -C assembler/libft
	$(CC) $^ $(LIB) -o $@

$(NAME2): $(VM_OBJ)
	$(CC) -lncurses $^ -o $@

clean:
	rm -f $(ASM_OBJ) $(VM_OBJ)
	make -C assembler/libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
