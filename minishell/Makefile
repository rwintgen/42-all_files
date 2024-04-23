# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 16:32:07 by deymons           #+#    #+#              #
#    Updated: 2024/04/23 13:26:06 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   minishell

CC          =   cc

FLAG        =   -Wall -Wextra -Werror -g

LIBFT_FILE  =   libft.a

LIBFT_PATH  =   ./libft/

LIBFT_LIB   =   $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

LIBFT_EX    =   $(LIBFT_LIB) $(FLAG)

C_FILE      =   main.c									\
				debug_print.c							\
				builtins/builtin_handling.c				\
				builtins/ft_cd.c						\
				builtins/ft_echo.c						\
				builtins/ft_pwd.c						\
				exec/cmd_exec/exec_commands.c			\
				exec/cmd_exec/exec_utils.c				\
				exec/cmd_exec/exit_code.c				\
				exec/cmd_exec/get_cmd_args.c			\
				exec/cmd_exec/get_path.c				\
				exec/cmd_exec/prep_for_exec.c			\
				exec/envp/envp.c						\
				exec/free_close/close.c					\
				exec/free_close/free.c					\
				exec/heredocs/empty_heredoc.c			\
				exec/heredocs/heredoc.c					\
				exec/redirections/input_utils.c			\
				exec/redirections/input.c				\
				exec/redirections/output_utils.c		\
				exec/redirections/output.c				\
				exec/redirections/redirect_utils.c		\
				exec/redirections/redirect.c			\
				exec/signals/signals.c					\
				exec/exec_handling.c					\
				parsing/lexer/lexer_utils.c				\
				parsing/lexer/lexer.c					\
				parsing/true_line/dollar.c				\
				parsing/true_line/true_line_utils.c		\
				parsing/true_line/true_line.c			\
				parsing/valid_input/valid_input.c		\
				parsing/parsing_handling.c

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