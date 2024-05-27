# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 16:32:07 by deymons           #+#    #+#              #
#    Updated: 2024/05/27 17:11:49 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	--no-print-directory

NAME		=	minishell
HEADER		=	-I ./include
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g

SRCS		=	src/main.c									\
				src/debug_print.c							\
				src/builtins/builtin_handling.c				\
				src/builtins/ft_cd.c						\
				src/builtins/ft_cd_utils.c					\
				src/builtins/ft_echo.c						\
				src/builtins/ft_env.c						\
				src/builtins/ft_exit.c						\
				src/builtins/ft_export_print.c				\
				src/builtins/ft_export_utils.c				\
				src/builtins/ft_export.c					\
				src/builtins/ft_pwd.c						\
				src/builtins/ft_unset.c						\
				src/exec/cmd_exec/exec_commands.c			\
				src/exec/cmd_exec/cmd_err_msg.c				\
				src/exec/cmd_exec/exec_utils.c				\
				src/exec/cmd_exec/exit_code.c				\
				src/exec/cmd_exec/get_cmd_args.c			\
				src/exec/cmd_exec/get_path.c				\
				src/exec/cmd_exec/prep_for_exec.c			\
				src/exec/envp/envp_utils.c					\
				src/exec/envp/envp.c						\
				src/exec/free_close/close.c					\
				src/exec/free_close/err_handlers.c			\
				src/exec/free_close/free.c					\
				src/exec/heredocs/empty_heredoc.c			\
				src/exec/heredocs/heredoc_utils.c			\
				src/exec/heredocs/heredoc.c					\
				src/exec/file/file_creat_no_cmd.c			\
				src/exec/redirections/check_valid_fds.c		\
				src/exec/redirections/input_piped_cmds.c	\
				src/exec/redirections/input_utils.c			\
				src/exec/redirections/input.c				\
				src/exec/redirections/outfiles.c			\
				src/exec/redirections/output_utils.c		\
				src/exec/redirections/output.c				\
				src/exec/redirections/redirect_utils.c		\
				src/exec/redirections/redirect.c			\
				src/exec/signals/signals.c					\
				src/exec/exec_handling.c					\
				src/parsing/lexer/lexer_utils.c				\
				src/parsing/lexer/lexer.c					\
				src/parsing/true_line/true_line_utils.c		\
				src/parsing/true_line/true_line.c			\
				src/parsing/true_line/var_expand_utils.c	\
				src/parsing/true_line/var_expand.c			\
				src/parsing/utils/ms_split.c				\
				src/parsing/utils/print_err.c				\
				src/parsing/utils/rm_quotes.c				\
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
				@echo "  __  __ ___ _  _ ___ ___ _  _ ___ _    _    "
				@echo " |  \/  |_ _| \| |_ _/ __| || | __| |  | |   "
				@echo " | |\/| || || .\` || |\__ \ __ | _|| |__| |__ "
				@echo " |_|  |_|___|_|\_|___|___/_||_|___|____|____|\n"
				@echo "            by rwintgen && amalangi\n"
				@echo "$(GREEN)libft created$(NC)"
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline
				@echo "$(GREEN)minishell linked$(NC)"

$(OBJDIR)/%.o: %.c
				@mkdir -p $(@D)
				@$(CC) $(HEADER) $(CFLAGS) -c $< -o $@

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

run			:	$(NAME)
				@echo "$(GREEN)launching minishell...$(NC)"
				@./$(NAME)

.PHONY: all clean fclean re