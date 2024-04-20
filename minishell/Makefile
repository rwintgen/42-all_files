# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deymons <deymons@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 16:32:07 by deymons           #+#    #+#              #
#    Updated: 2024/04/17 18:06:41 by deymons          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   minishell

CC          =   cc

FLAG        =   -Wall -Wextra -Werror -g

LIBFT_FILE  =   libft.a

LIBFT_PATH  =   ./libft/

LIBFT_LIB   =   $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

LIBFT_EX    =   $(LIBFT_LIB) $(FLAG)

C_FILE      =   main.c								\
				debug_print.c						\
				builtin/builtin_handling.c			\
				builtin/ft_cd.c						\
				builtin/ft_pwd.c					\
				builtin/ft_echo.c					\
				builtin/isbuiltin.c					\
				exec/exec_commands.c				\
				exec/exec_handling.c				\
				exec/prep_for_exec.c				\
				exec/envp.c							\
				exec/empty_heredoc.c				\
				exec/heredoc.c						\
				exec/i_o.c							\
				exec/input.c						\
				exec/output.c						\
				exec/signal_handling.c				\
				exec/exec_utils.c					\
				exec/free_close.c					\
				exec/get_path.c						\
				exec/output_utils.c					\
				parsing/true_line.c					\
				parsing/parsing.c					\
				parsing/empty_line.c				\
				parsing/quote.c						\
				parsing/dollar.c					\
				parsing/lexer.c

SRC_DIR     =   ./src/

INC_DIR     =   ./include/

OBJ_DIR     =   ./obj/

SRC         =   $(addprefix $(SRC_DIR),$(C_FILE))

OBJ         =   $(patsubst %,$(OBJ_DIR)%,$(C_FILE:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(FLAG) -I $(INC_DIR) -c $< -o $@

all: $(NAME)

kermit:
	@echo "bisous sur kermit"
	
./libft/libft.a:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)...\n"
	@make -sC $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT created\033[0m\n"

$(NAME): kermit ./libft/libft.a $(OBJ)
	@echo "\033[0;33m\nLINKING MINISHELL...\n"
	$(CC) $(OBJ) $(LIBFT_EX) -lreadline -o $(NAME)
	@echo "\033[1;32m./minishell linked !\n"

clean:
	@echo "\033[0;31mDeleting Minishell object files and directory...\n"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting Minishell executable..."
	@rm -f $(NAME)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re