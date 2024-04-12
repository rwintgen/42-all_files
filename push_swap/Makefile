# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:19:52 by rwintgen          #+#    #+#              #
#    Updated: 2024/01/30 15:22:23 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap

CFLAGS	:=	-Wall -Wextra -Werror -g -no-pie

LIBPATH	:=	./libft/

LIBFTA	:=	libft.a

LIBFT	:=	$(addprefix $(LIBPATH), $(LIBFTA))

LIBFTEX	:=	$(LIBFT) $(CFLAGS)

CC		:=	gcc

SRCS_C	:=	algo_utils.c \
				algorithms.c \
				cmd_push.c \
				cmd_swap.c \
				cmd_rotate.c \
				cmd_rrotate.c \
				data.c \
				errors.c \
				push_swap.c \
				utils.c \
				utils_2.c \

SRCDIR	:=	./sources/

SRCS	:=	$(addprefix $(SRCDIR), $(SRCS_C))

OBJS	:=	$(SRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

./libft/libft.a:
		@make -sC $(LIBPATH)

$(NAME): ./libft/libft.a $(OBJS)
		$(CC) $(OBJS) $(LIBFTEX) -o $(NAME)

clean:
		@make clean -sC $(LIBPATH)
		@rm -rf $(OBJS) $(NAME)

fclean: clean
		@rm -f $(NAME)
		@make clean -sC $(LIBPATH)
		@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
