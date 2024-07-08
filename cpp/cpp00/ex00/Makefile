# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 11:53:02 by rwintgen          #+#    #+#              #
#    Updated: 2024/07/08 12:28:07 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	megaphone.cpp
OBJ			=	$(SRCS:.cpp=.o)

.cpp.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33m\ncompiling cpp00 ex00...\n"
	$(CC) $(OBJ) -o $(NAME)
	@echo "\033[1;32m./compiled cpp00 ex00\n"

clean:
	@echo "\033[0;31mdeleting object files...\n"
	@rm $(OBJ)
	@echo "\033[1;32mobject files deleted\n"

fclean:
	@echo "\033[0;31mdeleting executable..."
	@rm  $(OBJ) $(NAME)
	@echo "\033[1;32mexecutable deleted\n"

re: fclean all

.PHONY: all clean fclean re