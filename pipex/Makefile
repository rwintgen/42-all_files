# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 16:18:08 by romain            #+#    #+#              #
#    Updated: 2024/03/19 09:44:46 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	pipex

CFLAGS	:=	-Wall -Wextra -Werror -g

LIBPATH	:=	./libft/

LIBFTA	:=	libft.a

LIBFT	:=	$(addprefix $(LIBPATH), $(LIBFTA))

LIBFTEX	:=	$(LIBFT) $(CFLAGS)

CC		:=	gcc

SRCS_C	:=	pipex.c \
				utils.c \
				exec.c

SRCDIR	:=	./sources/

SRCS	:=	$(addprefix $(SRCDIR), $(SRCS_C))

OBJS	:=	$(SRCS:.c=.o)

BSRCS_C	:=	pipex_bonus.c \
				utils_bonus.c \
				heredoc_bonus.c \
				file_bonus.c \
				exec_bonus.c

SRCBDIR	:=	./sources_bonus/

BSRCS	:=	$(addprefix $(SRCBDIR), $(BSRCS_C))

BOBJS	:=	$(BSRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME)_bonus 

./libft/libft.a:
		@make -sC $(LIBPATH)

$(NAME): ./libft/libft.a $(OBJS)
		$(CC) $(OBJS) $(LIBFTEX) -o $(NAME)

$(NAME)_bonus: ./libft/libft.a $(BOBJS)
		$(CC) $(BOBJS) $(LIBFTEX) -o $(NAME)_bonus

clean:
		@make clean -sC $(LIBPATH)
		@rm -rf $(OBJS)
		@rm -rf $(BOBJS)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(NAME)_bonus
		@make clean -sC $(LIBPATH)
		@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus