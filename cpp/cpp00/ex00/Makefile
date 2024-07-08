# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 11:53:02 by rwintgen          #+#    #+#              #
#    Updated: 2024/07/08 12:34:29 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	megaphone.cpp
OBJ			=	$(SRCS:.cpp=.o)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@rm $(OBJ)

fclean:
	@rm  $(OBJ) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re