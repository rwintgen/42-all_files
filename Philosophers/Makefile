# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:52:17 by rwintgen          #+#    #+#              #
#    Updated: 2024/05/22 16:13:18 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	--no-print-directory

NAME		=	philo
HEADER		=	-I ./include

CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g

SRCS		=	src/main.c \
				src/debug.c \
				src/print.c \
				src/do_dishes.c \
				src/eat_dinner.c \
				src/set_table/set_table.c \
				src/set_table/valid_arg.c \
				src/welcome_guests/welcome_guests.c \
				src/utils/actions.c \
				src/utils/utils.c \
				src/utils/get_set.c \
				src/utils/sync.c \
				src/utils/functions/ph_nblen.c \
				src/utils/functions/ph_strlen.c \
				src/utils/functions/ph_atol.c \
				src/utils/functions/ph_malloc.c \
				src/utils/functions/ph_usleep.c

GREEN	=	\033[0;32m
RED		=	\033[0;31m
NC		=	\033[0m

OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all			:	$(NAME)
				@echo "$(GREEN)philo compiled$(NC)"

$(NAME)		:	$(OBJS)
				@clear
				@echo "  __                       "
				@echo " /__)/ '/   _     / _ _  _ "
				@echo "/   /)/(()_) ()/)/)(-/ _)  "
				@echo "              /            "
				@echo "  by rwintgen\n"
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)philo linked$(NC)"

$(OBJDIR)/%.o: %.c
				@mkdir -p $(@D)
				@$(CC) $(HEADER) $(CFLAGS) -c $< -o $@

clean		:
				@rm -rf $(OBJDIR)
				@echo "$(RED)philo object files deleted$(NC)"

fclean		:	clean
				@rm -f $(NAME)
				@echo "$(RED)philo executable deleted$(NC)"

re			:	fclean all

.PHONY: all clean fclean re