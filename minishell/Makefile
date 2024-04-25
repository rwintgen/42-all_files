# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 16:32:07 by deymons           #+#    #+#              #
#    Updated: 2024/04/25 13:29:52 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME		=	minishell
HEADER		=	./include/
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER)

SRCS		=	src/main.c									\
				src/debug_print.c							\
				src/builtins/builtin_handling.c				\
				src/builtins/ft_cd.c						\
				src/builtins/ft_echo.c						\
				src/builtins/ft_pwd.c						\
				src/exec/cmd_exec/exec_commands.c			\
				src/exec/cmd_exec/cmd_err_msg.c				\
				src/exec/cmd_exec/exec_utils.c				\
				src/exec/cmd_exec/exit_code.c				\
				src/exec/cmd_exec/get_cmd_args.c			\
				src/exec/cmd_exec/get_path.c				\
				src/exec/cmd_exec/prep_for_exec.c			\
				src/exec/envp/envp.c						\
				src/exec/free_close/close.c					\
				src/exec/free_close/free.c					\
				src/exec/heredocs/empty_heredoc.c			\
				src/exec/heredocs/heredoc.c					\
				src/exec/redirections/input_utils.c			\
				src/exec/redirections/input.c				\
				src/exec/redirections/output_utils.c		\
				src/exec/redirections/output.c				\
				src/exec/redirections/redirect_utils.c		\
				src/exec/redirections/redirect.c			\
				src/exec/signals/signals.c					\
				src/exec/exec_handling.c					\
				src/parsing/lexer/lexer_utils.c				\
				src/parsing/lexer/lexer.c					\
				src/parsing/true_line/dollar.c				\
				src/parsing/true_line/true_line_utils.c		\
				src/parsing/true_line/true_line.c			\
				src/parsing/valid_input/valid_input_utils.c	\
				src/parsing/valid_input/valid_input.c		\
				src/parsing/parsing_handling.c

GREEN	=	\033[0;32m
RED		=	\033[0;31m
NC		=	\033[0m

OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all			:	$(NAME)
				@echo "$(GREEN)minishell compiled$(NC)"

$(NAME)		:	$(OBJS) $(LIBFT)
				@clear
				@echo "  __  __ ___ _  _ ___ ___ _  _ ___ _    _    \n"
				@echo " |  \/  |_ _| \| |_ _/ __| || | __| |  | |   \n"
				@echo " | |\/| || || .\` || |\__ \ __ | _|| |__| |__ \n"
				@echo " |_|  |_|___|_|\_|___|___/_||_|___|____|____|\n"
				@echo " by rwintgen && amalangi                     \n"
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline
				@echo "$(GREEN)libft created$(NC)"
				@echo "$(GREEN)minishell linked$(NC)"

$(OBJDIR)/%.o: %.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)	:
				@make -C ./libft
				@echo "$(GREEN)libft compiled$(NC)"

clean		:
				@make clean -C ./libft
				@echo "$(RED)libft object files deleted$(NC)"
				@rm -rf $(OBJDIR)
				@echo "$(RED)minishell object files deleted$(NC)"

fclean		:	clean
				@make fclean -C ./libft
				@echo "$(RED)libft executable deleted$(NC)"
				@rm -f $(NAME)
				@echo "$(RED)minishell executable deleted$(NC)"

re			:	fclean all

.PHONY: all clean fclean re